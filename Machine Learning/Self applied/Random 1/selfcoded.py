#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Mar 18 17:42:31 2020

@author: eklavaya
"""

import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

dataset = pd.read_csv('corona.csv')
dataset.columns = ['Balance','LW', 'LD', 'RW' , 'RD']

dataset.isnull().sum()

moddataset = dataset.fillna(0)

moddataset.isnull().sum()

df = moddataset.groupby('location')

xf = df.sum()

df = moddataset.groupby('date')

vf = df.sum()

X = vf.iloc[2:3]