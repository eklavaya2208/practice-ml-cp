#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Apr 19 15:02:15 2020

@author: eklavaya
"""

import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

#importing the dataset 
dataset = pd.read_csv('BreastCancer.csv')

#selecting only those relations with outcome=R
dataset=dataset.loc[dataset['Outcome']=='R']
dataset=dataset.drop(columns=['Outcome','ID','Lymph_Node_Status'])

corr = dataset.corr()
columns = np.full((corr.shape[0],), True, dtype=bool)
for i in range(corr.shape[0]+1):
    for j in range(i+1, corr.shape[0]):
        if corr.iloc[i,j] >= 0.9:
            if columns[j]:
                columns[j] = False
selected_columns = dataset.columns[columns]
dataset = dataset[selected_columns]

X = dataset.iloc[:,1:].values
y = dataset.iloc[:,0:1]

import statsmodels.regression.linear_model as sm
# add a column of ones as integer data type 
X = np.append(arr = np.ones((47, 1)).astype(int),values = X, axis = 1) 

X_opt = X[:,[0,3,6,20]]
ols = sm.OLS(endog = y, exog = X_opt.astype(float)).fit() 
ols.summary() 

X=X_opt


from sklearn.model_selection import train_test_split
X_train,X_test,y_train,y_test = train_test_split(X,y,test_size = 0.2,random_state = 1)

#fitting linear regression to the dataset
from sklearn.linear_model import LinearRegression
lin_reg = LinearRegression()
lin_reg.fit(X,y)

#fitting polynomial regression to the dataset
from sklearn.preprocessing import PolynomialFeatures
poly_reg = PolynomialFeatures(degree=5)
X_poly = poly_reg.fit_transform(X)
lin_reg2 = LinearRegression()
lin_reg2.fit(X_poly,y)
y_pred = lin_reg2.predict(poly_reg.fit_transform(X_test))


from sklearn.metrics import mean_squared_error
from math import sqrt
rmse = sqrt(mean_squared_error(y_test, y_pred))
print(rmse)

