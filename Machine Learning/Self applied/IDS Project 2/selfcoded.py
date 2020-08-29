#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Dec  5 17:37:24 2019

@author: eklavaya
"""

#data preprocessing

#importing the libraries
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import math

import warnings as warn
warn.filterwarnings('ignore')

#importing the dataset 
dataset = pd.read_csv('balance-scale.data')
dataset.columns = ['Balance','LW', 'LD', 'RW' , 'RD']

dataset['Balance'].replace(('L', 'R', 'B'), (-1, 1, 0), inplace = True)

import seaborn
corr_matrix=dataset.corr() 
fig, ax = plt.subplots(figsize=(11,11)) 
seaborn.heatmap(corr_matrix,annot=True,linewidths=.5, ax=ax)

X = dataset.iloc[:,1:].values
y = dataset.iloc[:,0:1]

#splitting dataset into training set and test set
from sklearn.model_selection import train_test_split
X_train,X_test,y_train,y_test = train_test_split(X,y,test_size = 0.15,random_state = 1)

dataset['Balance'].value_counts().sort_index()

labels = ['L', 'B', 'R']
colors = ['pink', 'green', 'yellow']
size = [288, 48, 288]
explode = [0.1, 0.1, 0.1]
plt.rcParams['figure.figsize'] = (10, 10)
plt.pie(size, labels = labels, colors = colors, explode = explode, shadow = True, autopct = "%.2f%%")
plt.title('A Pie Chart Representing different methods used', fontsize = 20)
plt.axis('off')
plt.legend()
plt.show()

#Visualization after doing label encoding
from sklearn.preprocessing import LabelEncoder
import seaborn 
dataset['Balance'] = LabelEncoder().fit_transform(dataset['Balance'].tolist())
seaborn.pairplot(data=dataset)

print('Some class imbalance')

from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score as model_score
rfc = RandomForestClassifier(n_estimators=1000, n_jobs=-1, )
rfc.fit(X_train, y_train)
y_pred = rfc.predict(X_test)
print('Accuracy in percent = ',model_score(y_pred,y_test)*100)

from sklearn.svm import SVC
classifier = SVC()
classifier.fit(X_train, y_train)
y_pred = classifier.predict(X_test)
print('Accuracy in percent = ',model_score(y_pred,y_test)*100)


from sklearn.neighbors import KNeighborsClassifier
clf = KNeighborsClassifier(n_neighbors=20)
clf.fit(X_train, y_train)
y_pred = clf.predict(X_test)
print('Accuracy in percent = ',model_score(y_pred,y_test)*100)

from sklearn.tree import DecisionTreeClassifier
clf = DecisionTreeClassifier(max_depth=6)
clf.fit(X_train, y_train)
y_pred = clf.predict(X_test)
print('Accuracy in percent = ',model_score(y_pred, y_test)*100)

arr = X_train.tolist()
ans = []
ans2 = y_train.values.tolist()
for i in range(len(arr)):
    l_w=arr[i][0]*arr[i][1]
    r_w=arr[i][2]*arr[i][3]
    if(l_w>r_w):
        ans.append([-1])
    elif(l_w==r_w):
        ans.append([0])
    else:
        ans.append([1])
t=len(arr)
s=0
for i in range(len(arr)):
    if(ans2[i]==ans[i]):
        s+=1
print (s/t)





