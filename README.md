# Smart-Glove
Sign Language recognition system (model) developed using Random Forest Classifier, that translates the sign language alphabets and common words into text and sound.
________________________________
## Hardware look
![Hardware Image](images/hardware_image.jpg)
________________________________
### Overall system Information
* __[Supervised machine learning](https://en.wikipedia.org/wiki/Supervised_learning).__

* [Random Forest Algorithm](https://en.wikipedia.org/wiki/Random_forest)

* System recognizes gestures through the use of [flex sensor](https://en.wikipedia.org/wiki/Flex_sensor),
 [accelerometer](https://www.sciencedirect.com/topics/engineering/accelerometer-sensor) 
 and [gyroscope](https://www.elprocus.com/gyroscope-sensor/).

* All the programming and integration has been done in mac and for mac, so  adjust the port for arduino as per device port number.

* Arduino_code.ino is burned inside the [Arduino Mega2560](https://www.arduino.cc/en/Guide/ArduinoMega2560).

* python_code whenever is executed it fetches the data from the serial port of the laptop then passes the data from the model for prediction of output as well as display and audio.


_Note : Dataset is developed for the used system, so is not made public._
____________________________________
### Data Visualizations of overall sensor data
![Overall Sensor Data Visualization](images/data_visualization.png)
____________________________________
#### Some [correlation](https://www.surveysystem.com/correlation.htm) plots of different sensors values for different alphabets
* Correlation plot of alphabet __A__

![Correlation plot of alphabet __A__](correlation_images/correlation_plot_alphabet_a.png)
_______________________________________
* Correlation plot of alphabet __B__ 

![Correlation plot of alphabet __B__](correlation_images/correlation_plot_alphabet_b.png)
_______________________________________
* Correlation plot of alphabet __C__ 

![Correlation plot of alphabet __C__](correlation_images/correlation_plot_alphabet_c.png)
_______________________________________
* Correlation plot of alphabet __D__

![Correlation plot of alphabet __D__](correlation_images/correlation_plot_alphabet_d.png)
_______________________________________
* Correlation plot of alphabet __E__

![Correlation plot of alphabet __E__](correlation_images/correlation_plot_alphabet_e.png)
_______________________________________
* Correlation plot of alphabet __M__ 

![Correlation plot of alphabet __M__](correlation_images/correlation_plot_alphabet_m.png)
_______________________________________
* Correlation plot of alphabet __N__ 

![Correlation plot of alphabet __N__](correlation_images/correlation_plot_alphabet_n.png)
_______________________________________
* Correlation plot of alphabet __O__ 

![Correlation plot of alphabet __O__](correlation_images/correlation_plot_alphabet_o.png)
_______________________________________
* Correlation plot of alphabet __S__

![Correlation plot of alphabet __S__](correlation_images/correlation_plot_alphabet_s.png)
_______________________________________
* Correlation plot of alphabet __T__

![Correlation plot of alphabet __T__](correlation_images/correlation_plot_alphabet_t.png)
_______________________________________
* Correlation plot of alphabet __U__

![Correlation plot of alphabet __U__](correlation_images/correlation_plot_alphabet_u.png)
_______________________________________
* Correlation plot of alphabet __V__

![Correlation plot of alphabet __V__](correlation_images/correlation_plot_alphabet_v.png)

_______________________________________

## Authors
* __[Adarsh Ghimire](ghimireadarsh.github.io)__ - _Initial Work_ - Project Lead
* __[Aakriti Basnet](https://www.linkedin.com/in/aakritibasnet/)__ - Project Member 
* __[Anushma Shrestha](https://np.linkedin.com/in/anushma-shrestha-862449125)__- Project Member
* __[Bhupendra Kadayat](https://www.linkedin.com/in/bhupendra-kadayat-48b6b3178/)__ - Project Member
