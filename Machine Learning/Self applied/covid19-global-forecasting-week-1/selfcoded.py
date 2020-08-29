import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

dataset = pd.read_csv('train.csv')
dataset = dataset.drop(['Province/State'],axis=1)

dataset["Date"] = pd.to_datetime(dataset["Date"])

dataset['Year'] = dataset['Date'].dt.year
dataset['Month'] = dataset['Date'].dt.month
dataset['Day'] = dataset['Date'].dt.day

dataset = dataset.drop(['Date'],axis=1)
dataset = dataset.drop(['Year'],axis=1)
dataset = dataset.drop(['Id'],axis=1)

dataset = dataset[['Country/Region','Lat','Long','Month','Day','ConfirmedCases','Fatalities']]

#predicting the confirmed cases graph
X = dataset.iloc[:,1:5]
y = dataset.iloc[:,5:6]

import seaborn
corr_matrix=dataset.corr() 
fig, ax = plt.subplots(figsize=(12,12)) 
seaborn.heatmap(corr_matrix,annot=True,linewidths=.5, ax=ax)

from sklearn.linear_model import LinearRegression
regressor = LinearRegression()
regressor.fit(X,y)

dataset = pd.read_csv('test.csv')
dataset = dataset.drop(['Province/State'],axis=1)

dataset["Date"] = pd.to_datetime(dataset["Date"])

dataset['Year'] = dataset['Date'].dt.year
dataset['Month'] = dataset['Date'].dt.month
dataset['Day'] = dataset['Date'].dt.day

dataset = dataset.drop(['Date'],axis=1)
dataset = dataset.drop(['Year'],axis=1)
dataset = dataset.drop(['ForecastId'],axis=1)

dataset = dataset[['Country/Region','Lat','Long','Month','Day']]

X = dataset.iloc[:,1:5]

y_pred = regressor.predict(X)