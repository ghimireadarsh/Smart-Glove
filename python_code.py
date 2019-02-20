#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Jun 22 23:29:25 2018

@author: adarshghimire
"""
import sys
sys.executable
#import numpy as np
import pandas as pd
#import matplotlib.pyplot as plt
import serial
import time
from os import system
#from IPython.display import display
#import seaborn as sns
train_df=pd.read_csv("./words.csv")
train_x=train_df.drop(["Word"], axis=1)
train_y=train_df["Word"]
print(type(train_x))
print(type(train_y))

from sklearn.ensemble import RandomForestClassifier
clf_rf=RandomForestClassifier(n_estimators=20, random_state=30)
print(clf_rf.fit(train_x,train_y))
print(clf_rf.score(train_x,train_y))

serial_port = '/dev/tty.usbmodemFA131';
baud_rate = 9600; #In arduino, Serial.begin(baud_rate)
write_to_file_path = "test_df.csv";

def sound_function(predictions):
    system('say %s' %(predictions))

def contloop():
    output_file = open(write_to_file_path, "w+");
    arduino = serial.Serial(serial_port, baud_rate)
    count=0;
    while count<3:
        arduino.flush()
        line=arduino.read(arduino.inWaiting())
        line=line.decode("utf-8")
        #print(line);
        output_file.write(line);
        time.sleep(1);
        count+=1;
    output_file.close()
    test_df=pd.read_csv("./test_df.csv")
    predictions=clf_rf.predict(test_df)
    print(predictions)
    sound_function(predictions)
    
var=1;
while var ==1:
    contloop()
    


    

    
    
