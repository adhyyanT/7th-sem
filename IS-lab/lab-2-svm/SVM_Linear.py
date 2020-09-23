# importing required libraries 
import numpy as np 
import pandas as pd 
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC
  
# reading csv file and extracting class column to y. 
#Data = pd.read_csv("Data_Train.csv",header=None)
Data = pd.read_csv("Bill.csv")
V = np.array(Data)
#X = Data[:,0:3]
#Y  = Data[:,4] # classes having 0 and 1 
X = Data.drop('Class', axis=1)
y = Data['Class']

# plotting scatters  
plt.scatter(V[:, 0], V[:, 1], c=y, s=50, cmap='spring'); 
plt.show()

# creating line space between -1 to 3.5  
xfit = np.linspace(-1, 2.5) 
  
# plotting scatter 
plt.scatter(V[:, 0], V[:, 1], c=y, s=50, cmap='spring') 
  
# plot a line between the different sets of data 
for m, b, d in [(1, 0.65, 0.33), (0.5, 1.6, 0.55), (-0.2, 2.9, 0.2)]: 
    yfit = m * xfit + b 
    plt.plot(xfit, yfit, '-k') 
    plt.fill_between(xfit, yfit - d, yfit + d, edgecolor='none',  
    color='#AAAAAA', alpha=0.4) 
  
plt.xlim(-1, 2.5); 
plt.show() 


X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.20)
#print (x),(y) 

 # "Support Vector Classifier" 
clf = SVC(kernel='linear')

# fitting x samples and y classes 
clf.fit(X_train, y_train) 

y_pred = clf.predict(X_test)

from sklearn.metrics import classification_report, confusion_matrix
print(confusion_matrix(y_test,y_pred))
print(classification_report(y_test,y_pred))
