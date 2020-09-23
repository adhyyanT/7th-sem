# -*- coding: utf-8 -*-
"""
Created on Tue Aug 18 15:52:56 2020

@author: Adhyyan
"""
# from sklearn import model_selection
# from sklearn import svm
# import numpy as np
# import matplotlib.pyplot as plt
# import pandas as pd
# import random

# data =pd.read_csv('Training_Dataset.csv')
# n=random.randint(0,10000)
# print(n)
# arr=np.arrange(20*25).reshape(20,25)
# X=data.iloc[:,0:25].values
# y=data.iloc[:,25].values

# plt.scatter(X, y, color='blue')
# plt.xlabel("Predictor", fontsize=16)
# plt.ylabel("Target", fontsize=16)
# plt.show()




import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import random

import operator
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score
from sklearn.preprocessing import PolynomialFeatures

dataset = pd.read_csv('Training_Dataset.csv')
n=random.randint(0,10000)
x = dataset.iloc[n:n+20, 0:25].values
y = dataset.iloc[n:n+20, 25].values


polynomial_features= PolynomialFeatures(degree=3)
x_poly = polynomial_features.fit_transform(x)
lm = LinearRegression()
lm.fit(x_poly, y)
y_poly_pred = lm.predict(x_poly)
plt.plot(x,y_poly_pred,color='red')

rmse = np.sqrt(mean_squared_error(y,y_poly_pred))
r2 = r2_score(y,y_poly_pred)

print(rmse)
print(r2)

# plt.scatter(np.array(x), y, s=10)
# # sort the values of x before line plot
# sort_axis = operator.itemgetter(0)
# sorted_zip = sorted(zip(x,y_poly_pred), key=sort_axis)
# x, y_poly_pred = zip(*sorted_zip)
# plt.plot(x, y_poly_pred, color='m')
# plt.show()