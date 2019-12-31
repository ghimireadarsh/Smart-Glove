"""
Created on Fri Jun 22 23:29:25 2018

@author: adarshghimire
"""

import pandas as pd
import serial
import time

# For machine learning
from sklearn.ensemble import RandomForestClassifier

from os import system

# For loading the model developed
import pickle5 as pickle
# loading model for all alphabets
clf_rf = pickle.load(open('models/all_alphabets_model','rb'))

# loading model for all alphabets and yes no
# Uncomment the below line for loading the model
# clf_rf = pickle.load(open('models/alphabets_yes_no_model','rb'))

# loading model for all alphabets
# Uncomment the below line for loading the words model
# clf_rf = pickle.load(open('models/words_model','rb'))

serial_port = '/dev/tty.usbmodemFA131';
baud_rate = 9600; #In arduino, Serial.begin(baud_rate)
write_to_file_path = "test_df.csv";

def sound_function(predictions):
    system('say %s' %(predictions))

def contloop():
    output_file = open(write_to_file_path, "w+");   # For saving the predicted value in file for later use
    arduino = serial.Serial(serial_port, baud_rate)
    count=0;
    while count<3:

        arduino.flush() # clears the arduino buffer memory
        line=arduino.read(arduino.inWaiting())   # reading inputs from arduino interface
        line=line.decode("utf-8")    # decooding the inputs from arduino
        #print(line);
        output_file.write(line);    # saving the input data
        time.sleep(1);    # delaying the loop so that system takes input per second
        count+=1;
    output_file.close()
    test_df=pd.read_csv("./test_df.csv")
    predictions=clf_rf.predict(test_df)     # Passing through the model for prediction of the input
    print(predictions)
    sound_function(predictions)
    
var=1;
while var ==1:
    # Make system work, whenever the system is integrated
    contloop()