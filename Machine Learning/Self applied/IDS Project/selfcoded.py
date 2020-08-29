#data preprocessing

#importing the libraries
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import math

import warnings as warn
warn.filterwarnings('ignore')

#importing the dataset 
dataset = pd.read_csv('car.csv')

dataset.columns = ['Price', 'Maint Cost', 'Doors', 'Capacity', 'Lug_boot', 'safety', 'Decision']

dataset['safety'].replace(('low', 'med', 'high'), (0, 1, 2), inplace = True)
dataset['Price'].replace(('low', 'med', 'high', 'vhigh'), (0, 1, 2, 3), inplace = True)
dataset['Maint Cost'].replace(('low', 'med', 'high', 'vhigh'), (0, 1, 2, 3), inplace = True)
dataset['Lug_boot'].replace(('small', 'med', 'big', 'small'), (0, 1, 2, 3), inplace = True)
dataset['Doors'].replace(('1', '2', '3', '4','5more'), (1, 2, 3, 4,5), inplace = True)
dataset['Capacity'].replace(('1', '2', '3', '4','more'), (1, 2, 3, 4,5), inplace = True)

X=dataset.iloc[:,0:6]
y=dataset.iloc[:,6:]

#splitting dataset into training set and test set
from sklearn.model_selection import train_test_split
X_train,X_test,y_train,y_test = train_test_split(X,y,test_size = 0.2,random_state = 0)

from sklearn.preprocessing import StandardScaler
sc = StandardScaler()
X_train = sc.fit_transform(X_train)
X_test = sc.transform(X_test)

#test set and training set randomised with training set = 20% of dataset

#checking for biases in the data,training set and test set
dataset['Decision'].value_counts().sort_index()
y_train['Decision'].value_counts().sort_index()
y_test['Decision'].value_counts().sort_index()

print('Existence of class imbalance')

#pie chart to indicate distribution of decision attribute
labels = ['acc', 'good', 'unacc', 'vgood']
colors = ['blue', 'black', 'yellow', 'magenta']
size = [384, 69, 1210, 65]
explode = [0.1, 0.1, 0.1, 0.1]
plt.rcParams['figure.figsize'] = (10, 10)
plt.pie(size, labels = labels, colors = colors, explode = explode, shadow = True, autopct = "%.2f%%")
plt.title('A Pie Chart Representing Different Decisions', fontsize = 20)
plt.axis('off')
plt.legend()
plt.show()

#scatter plots
price = pd.crosstab(dataset['Price'], dataset['Decision'])
price.div(price.sum(1).astype(float), axis = 0).plot(kind = 'bar', stacked = True, figsize = (10, 7))
plt.title('Stacked Bar Graph to Depict portions of Decisions taken on each Price Category', fontsize = 20)
plt.xlabel('Price Range in Increasing Order', fontsize = 15)
plt.ylabel('Count', fontsize = 15)
plt.legend()
plt.show()

mc = pd.crosstab(dataset['Maint Cost'], dataset['Decision'])
mc.div(mc.sum(1).astype(float), axis = 0).plot(kind = 'bar', stacked = True, figsize = (10, 7))
plt.title('Stacked Bar Graph to Depict portions of Decisions taken on each Maintenance Cost Category', fontsize = 20)
plt.xlabel('Maintenance Cost in Increasing Order', fontsize = 15)
plt.ylabel('Count', fontsize = 15)
plt.legend()
plt.show()

safety = pd.crosstab(dataset['Lug_boot'], dataset['Decision'])
safety.div(safety.sum(1).astype(float), axis = 0).plot(kind = 'bar', stacked = True, figsize = (10, 7))
plt.title('Stacked Bar Graph to Depict portions of Decisions taken on each boot size Category', fontsize = 20)
plt.xlabel('Increasing size of luggage boot', fontsize = 15)
plt.ylabel('Count', fontsize = 15)
plt.legend()
plt.show()

doors = pd.crosstab(dataset['Capacity'], dataset['Decision'])
doors.div(doors.sum(1).astype(float), axis = 0).plot(kind = 'bar', stacked = True, figsize = (10, 7))
plt.title('Stacked Bar Graph to Depict portions of Decisions taken on each capacity Category', fontsize = 20)
plt.xlabel('Capacity in Increasing Order', fontsize = 15)
plt.ylabel('Count', fontsize = 15)
plt.legend()
plt.show()

from sklearn.linear_model import LogisticRegression
from sklearn.metrics import confusion_matrix
model = LogisticRegression(C = 1)
model.fit(X_train, y_train)
y_pred = model.predict(X_test)
print("Training Accuracy: ",model.score(X_train, y_train))
print("Testing Accuracy: ", model.score(X_test, y_test))
cm = confusion_matrix(y_test, y_pred)
print(cm)

from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import confusion_matrix
model = DecisionTreeClassifier(max_depth = 3)
model.fit(X_train, y_train)
y_pred = model.predict(X_test)
print("Training Accuracy: ",model.score(X_train, y_train))
print("Testing Accuracy: ", model.score(X_test, y_test))
cm = confusion_matrix(y_test, y_pred)
print(cm)

dataset['Decision'].replace(('unacc','acc','good','vgood'), (0, 1, 1, 1), inplace = True)
X=dataset.iloc[:,0:6]
y=dataset.iloc[:,6:]
from sklearn.model_selection import train_test_split
X_train,X_test,y_train,y_test = train_test_split(X,y,test_size = 0.2,random_state = 3)
from sklearn.preprocessing import StandardScaler
sc = StandardScaler()
X_train = sc.fit_transform(X_train)
X_test = sc.transform(X_test)

from sklearn.linear_model import LogisticRegression
from sklearn.metrics import confusion_matrix
model = LogisticRegression(C = 1)
model.fit(X_train, y_train)
y_pred = model.predict(X_test)
print("Training Accuracy: ",model.score(X_train, y_train))
print("Testing Accuracy: ", model.score(X_test, y_test))
cm = confusion_matrix(y_test, y_pred)
print(cm)

from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import confusion_matrix
model = DecisionTreeClassifier(max_depth = 3)
model.fit(X_train, y_train)
y_pred = model.predict(X_test)
print("Training Accuracy: ",model.score(X_train, y_train))
print("Testing Accuracy: ", model.score(X_test, y_test))
cm = confusion_matrix(y_test, y_pred)
print(cm)

from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import confusion_matrix
model = DecisionTreeClassifier(max_depth = 5)
model.fit(X_train, y_train)
y_pred = model.predict(X_test)
print("Training Accuracy: ",model.score(X_train, y_train))
print("Testing Accuracy: ", model.score(X_test, y_test))
cm = confusion_matrix(y_test, y_pred)
print(cm)

from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import confusion_matrix
model = DecisionTreeClassifier(max_depth = 8)
model.fit(X_train, y_train)
y_pred = model.predict(X_test)
print("Training Accuracy: ",model.score(X_train, y_train))
print("Testing Accuracy: ", model.score(X_test, y_test))
cm = confusion_matrix(y_test, y_pred)
print(cm)

from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import confusion_matrix
from sklearn.metrics import classification_report
model = DecisionTreeClassifier(max_depth = 10)
model.fit(X_train, y_train)
y_pred = model.predict(X_test)
print("Training Accuracy: ",model.score(X_train, y_train))
print("Testing Accuracy: ", model.score(X_test, y_test))
cm = confusion_matrix(y_test, y_pred)
print(classification_report(y_test,y_pred))
print(cm)

from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import confusion_matrix
model = DecisionTreeClassifier(max_depth = 11)
model.fit(X_train, y_train)
y_pred = model.predict(X_test)
print("Training Accuracy: ",model.score(X_train, y_train))
print("Testing Accuracy: ", model.score(X_test, y_test))
cm = confusion_matrix(y_test, y_pred)
print(cm)

from sklearn import svm
from sklearn.svm import SVC
svc = svm.SVC(kernel='linear', C=1).fit(X_train,y_train)
y_pred=svc.predict(X_test)
cm = confusion_matrix(y_test, y_pred)
print(classification_report(y_test,y_pred))
print(cm)

from sklearn.neighbors import KNeighborsClassifier
model=KNeighborsClassifier(n_neighbors=5)
model.fit(X_train,y_train)
y_pred=model.predict(X_test)
print("Training Accuracy: ",model.score(X_train, y_train))
print("Testing Accuracy: ", model.score(X_test, y_test))
cm = confusion_matrix(y_test, y_pred)
print(cm)

from sklearn.neighbors import KNeighborsClassifier
model=KNeighborsClassifier(n_neighbors=1)
model.fit(X_train,y_train)
y_pred=model.predict(X_test)
print("Training Accuracy: ",model.score(X_train, y_train))
print("Testing Accuracy: ", model.score(X_test, y_test))
cm = confusion_matrix(y_test, y_pred)
print(cm)

from sklearn.neighbors import KNeighborsClassifier
model=KNeighborsClassifier(n_neighbors=3)
model.fit(X_train,y_train)
y_pred=model.predict(X_test)
print("Training Accuracy: ",model.score(X_train, y_train))
print("Testing Accuracy: ", model.score(X_test, y_test))
cm = confusion_matrix(y_test, y_pred)
print(cm)

from sklearn.neighbors import KNeighborsClassifier
model=KNeighborsClassifier(n_neighbors=5) #best accuracy
model.fit(X_train,y_train)
y_pred=model.predict(X_test)
print(classification_report(y_test,y_pred))
cm = confusion_matrix(y_test, y_pred)
print(cm)

from sklearn.neighbors import KNeighborsClassifier
model=KNeighborsClassifier(n_neighbors=8)
model.fit(X_train,y_train)
y_pred=model.predict(X_test)
print("Training Accuracy: ",model.score(X_train, y_train))
print("Testing Accuracy: ", model.score(X_test, y_test))
cm = confusion_matrix(y_test, y_pred)
print(cm)

from sklearn.neighbors import KNeighborsClassifier
model=KNeighborsClassifier(n_neighbors=10)
model.fit(X_train,y_train)
y_pred=model.predict(X_test)
print("Training Accuracy: ",model.score(X_train, y_train))
print("Testing Accuracy: ", model.score(X_test, y_test))
cm = confusion_matrix(y_test, y_pred)
print(cm)

def separate_by_class(dataset):
	separated = dict()
	for i in range(len(dataset)):
		vector = dataset[i]
		class_value = vector[-1]
		if (class_value not in separated):
			separated[class_value] = list()
		separated[class_value].append(vector)
	return separated


df = dataset.values.tolist()
separated = separate_by_class(df)
from math import sqrt,pi,exp

for label in separated:
	print(label)
	for row in separated[label]:
		print(row)
        
def mean(numbers):
	return sum(numbers)/float(len(numbers))

def stdev(numbers):
	avg = mean(numbers)
	variance = sum([(x-avg)**2 for x in numbers]) / float(len(numbers)-1)
	return sqrt(variance)

def summarize_dataset(dataset):
	summaries = [(mean(column), stdev(column), len(column)) for column in zip(*dataset)]
	del(summaries[-1])
	return summaries

summary = summarize_dataset(df)
print(summary)

def calculate_probability(x, mean, stdev):
	exponent = exp(-((x-mean)**2 / (2 * stdev**2 )))
	return (1 / (sqrt(2 * pi) * stdev)) * exponent

def calculate_class_probabilities(summaries, row):
	total_rows = sum([summaries[label][0][2] for label in summaries])
	probabilities = dict()
	for class_value, class_summaries in summaries.items():
		probabilities[class_value] = summaries[class_value][0][2]/float(total_rows)
		for i in range(len(class_summaries)):
			mean, stdev, _ = class_summaries[i]
			probabilities[class_value] *= calculate_probability(row[i], mean, stdev)
	return probabilities

def summarize_by_class(dataset):
	separated = separate_by_class(dataset)
	summaries = dict()
	for class_value, rows in separated.items():
		summaries[class_value] = summarize_dataset(rows)
	return summaries

def calculate_class_probabilities(summaries, row):
    total_rows = sum([summaries[label][0][1] for label in summaries])
    probabilities = dict()
    for class_value, class_summaries in summaries.items():
        probabilities[class_value] = summaries[class_value][0][2]/float(total_rows)
        print(class_value)
        for i in range(len(class_summaries)):
            mean, stdev, _ = class_summaries[i]
            probabilities[class_value] *= calculate_probability(row[i], mean, stdev)
    return probabilities

summaries = summarize_by_class(df)
df2 = y.values.tolist()
for i in range(len(df2)):
    df2[i]=df2[i][0]
#probabilities = calculate_class_probabilities(summaries, df[289])
t1=[]
for i in range(len(df)):
    probabilities = calculate_class_probabilities(summaries, df[i])
    if(probabilities[0]>probabilities[1]):
        t1.append(0)
    else:
        t1.append(1)
cm=[[0,0],[0,0]]
for i in range(len(df)):    
    if(df2[i]==0 and t1[i]==0):
        cm[1][1]+=1
    if(df2[i]==0 and t1[i]==1):
        cm[1][0]+=1
    if(df2[i]==1 and t1[i]==0):
        cm[0][1]+=1
    if(df2[i]==1 and t1[i]==1):
        cm[0][0]+=1
print(cm)
print(classification_report(df2,t1))

observables = dataset.iloc[:,0:6]
color_wheel = {0: "blue", 1: "red"}
colors = dataset["Decision"].map(lambda x: color_wheel.get(x))
pd.plotting.scatter_matrix(observables, c=colors, alpha = 0.9, figsize = (18, 18), diagonal = 'kde'
);
      
import seaborn
corr_matrix=dataset.corr() 
fig, ax = plt.subplots(figsize=(12,12)) 
seaborn.heatmap(corr_matrix,annot=True,linewidths=.5, ax=ax) 
