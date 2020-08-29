#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Apr 19 11:49:30 2020

@author: eklavaya
"""

import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
import numpy as np

#importing the dataset 
dataset = pd.read_csv('BreastCancer.csv')
dataset['Outcome'].replace(('R', 'N'), (1, 0), inplace = True)

#feature selection
corr_matrix=dataset.corr() 
fig, ax = plt.subplots(figsize=(20,20)) 
sns.heatmap(corr_matrix,annot=True,linewidths=.5, ax=ax) 

#removing columns with high correlation
dataset = dataset.drop(columns=['radius_mean','area_mean','radius_std_dev','area_std_dev','Worst_radius','Worst_area']);

#splitting into x and y
X = dataset.iloc[:,2:29].values
y = dataset.iloc[:,1:2]

#handling missing data
from sklearn.impute import SimpleImputer
imputer = SimpleImputer(missing_values = '?', strategy = 'most_frequent')
imputer = imputer.fit(X[:,26:])
X[:,26:] = imputer.transform(X[:,26:])

import statsmodels.regression.linear_model as sm
# add a column of ones as integer data type 
X = np.append(arr = np.ones((198, 1)).astype(int),values = X, axis = 1) 

X_opt = X[:,[0,1,3,4,9,18,19,27]]
ols = sm.OLS(endog = y, exog = X_opt.astype(float)).fit() 
ols.summary() 
X=X_opt

from sklearn.feature_selection import SelectFromModel


#class imbalance found
dataset['Outcome'].value_counts()

#splitting into training and test set
from sklearn.model_selection import train_test_split
X_train,X_test,y_train,y_test = train_test_split(X,y,test_size = 0.25,random_state = 0)

#scaling
from sklearn.preprocessing import StandardScaler
sc = StandardScaler()
X_train = sc.fit_transform(X_train)
X_test = sc.transform(X_test)

#oversampling to remove class imbalance
from imblearn.over_sampling import SMOTE
sm = SMOTE(random_state = 42)
X_train_oversampled, y_train_oversampled = sm.fit_sample(X_train, y_train)
X_train=X_train_oversampled
y_train=y_train_oversampled

#checking accuracy and false negatives
from sklearn.metrics import confusion_matrix
from sklearn.model_selection import cross_val_score

from xgboost import XGBClassifier
from sklearn.model_selection import StratifiedKFold
xgb= XGBClassifier(silent=False, 
                      scale_pos_weight=1,
                      learning_rate=0.001,  
                      colsample_bytree = 1,
                      subsample = 1,
                      objective='binary:logistic', 
                      n_estimators=1000, 
                      reg_alpha = 0.3,
                      max_depth=20, gamma=10)
eval_set = [(X_test, y_test)]
xgb.fit(X_train, y_train,eval_metric="error", eval_set=eval_set, verbose=True)
from sklearn.metrics import accuracy_score
print('Accuracy score on train_data: ', accuracy_score(y_true = y_train, y_pred = xgb.predict(X_train).round()))
print('Accuracy score on test_data: ', accuracy_score(y_true = y_test, y_pred = xgb.predict(X_test).round()))
y_pred = xgb.predict(X_test).round()
kfold = StratifiedKFold(n_splits=10, random_state=7)
results = cross_val_score(xgb, X, y, cv=kfold)
print("Accuracy: %.2f%% (%.2f%%)" % (results.mean()*100, results.std()*100))

from sklearn.svm import SVC
classifier = SVC(kernel = 'rbf', random_state = 0)
classifier.fit(X_train, y_train)
y_pred = classifier.predict(X_test)
cm = confusion_matrix(y_test, y_pred)
print('Accuracy on training set:',classifier.score(X_train,y_train))
print('Accuracy on test set:',classifier.score(X_test,y_test))
kfold = StratifiedKFold(n_splits=10, random_state=7)
results = cross_val_score(classifier, X, y, cv=kfold)
print("Accuracy: %.2f%% (%.2f%%)" % (results.mean()*100, results.std()*100))

#Logistic Regression
from sklearn.linear_model import LogisticRegression
classifier = LogisticRegression(C=20,random_state = 2,max_iter=200)
classifier.fit(X_train, y_train)
kfold = StratifiedKFold(n_splits=10, random_state=7)
results = cross_val_score(classifier, X, y, cv=kfold)
print("Accuracy: %.2f%% (%.2f%%)" % (results.mean()*100, results.std()*100))

# Predicting the Test set results
y_pred = classifier.predict(X_test)
cm = confusion_matrix(y_test,y_pred)

from sklearn.model_selection import GridSearchCV
from sklearn.neighbors import KNeighborsClassifier
knn = KNeighborsClassifier()
params_knn = {'n_neighbors': np.arange(1, 25)}
knn_gs = GridSearchCV(knn, params_knn, cv=5)
knn_gs.fit(X_train, y_train)
knn_best = knn_gs.best_estimator_
print(knn_gs.best_params_)

from sklearn.ensemble import VotingClassifier
estimators=[('knn', knn_best), ('xgb', xgb), ('classifier', classifier)]
ensemble = VotingClassifier(estimators, voting='hard')
ensemble.fit(X_train,y_train)
y_pred = ensemble.predict(X_test)
kfold = StratifiedKFold(n_splits=10, random_state=7)
results = cross_val_score(ensemble, X, y, cv=kfold)
print("Accuracy: %.2f%% (%.2f%%)" % (results.mean()*100, results.std()*100))

df = pd.DataFrame(data=X_test)
df.to_csv('test_set.csv')
df2 = pd.DataFrame(data=y_pred,columns=['column1'])
df2.to_csv('pred.csv')