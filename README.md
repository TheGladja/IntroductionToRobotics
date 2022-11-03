 # Introduction to Robotics (2021 - 2022)
 Introduction to Robotics laboratory homeworks, taken in the 3rd year at the Faculty of Mathematics and Computer Science, University of Bucharest. Here I will post every homework and project covered by this course throughout the semester. Also, each material will be as perfectly structured as possible, that means including every detail about the subject (such as requirements, implementation details, code and image files) in order to make things more understandable. Give it a go!
 
 ### The last homework description is on the lower side of this page

 ## Homework 1

 ### Requirements 
 #### Technical Task
 Use a separate potentiometer in controlling each of thecolor of the RGB led (Red,Green andBlue). The control must be done with digital electronics (aka you must read the value of the potentiometer with Arduino, and write a mapped value to each of the pins connected to the led.
 #### Coding task
 Coding style is of utmost importance. You must have aperfectly clean code in order to receive the maximum grade. Keep in mind that magic numbers are not accepted, although you might see them in the lab(as a trade-off for speed). Remember to be consistent in your style, check the style guide and the provided style  document and use correct spacing.
 
 ### Details
 In this homework I made a three potentiometer controlled rgb led. Each potentiometer is assigned to one of the colors (red, green and blue) and so the brightness, intensity and the color can be controlled by hand. The code structure is fairly simple, we read the value given by the potentiometers and apply the write value (voltage divided by the read value) to each color of the led.
 
 ### Image files
 #### Checkout this link
 https://www.youtube.com/watch?v=-pjyUkCzI64&list=PLASPWLXL8uFXgAFEjd-jlXm1SQpGpdLho&index=1&ab_channel=CruceanuCalin
 #### Setup photo
 ![Homework1](https://user-images.githubusercontent.com/80258120/197415867-93f705b3-5815-4154-92a3-d8d9842ab5b1.jpeg)

 ## Homework 2

 ### Requirements 
 #### Technical Task
 Building the traffic lights for a crosswalk. You will use 2 LEDs to represent the traffic lights for people (red and green) and 3 LEDs to represent the traffic lights for cars (red, yellow and green). See the states it needs to go through. It’s a traffic lights system for people and cars - don’t overthink it.
 
 ##### 1.State 1(default, reinstated after state 4 ends):  
 Green light for cars,red  light  for  people,  no  sounds.   Duration:  indefinite,  changed  bypressing the button.
 ##### 2.State 2(initiated by counting down 8 seconds after a button press):
 The  light  should  be  yellow  for  cars,  red  for  people  and  no  sounds.Duration:  3 seconds.
 ##### 3.State 3(initiated after state 2 ends): 
 Red for cars, green for peopleand a beeping sound from the buzzer at a constant interval. Duration:8 seconds.
 ##### 4.State 4(initiated after state 3 ends): 
 Red for cars,blinking greenfor people and a beeping sound from the buzzer,  at a constant in-terval,  faster than the beeping in state 3.  This state should last 4seconds.
 
 #### Coding task
 Coding style is of utmost importance. You must have a perfectly clean code in order to receive the maximum grade. An important coding challenge present in this task is using millis() instead of delay(). However, remember that the bulk of the grade is if the project works. Do not tend to small details unless you have the entire functionality done.
 
 ### Details
 In this homework I made a five LEDs, one buzzer and one button controlled traffic lights crosswalk. I used boolean validators so each of the four states will be accessible at the right time. Notes: initially all the leds are off when we declare the inputs/outputs and the button is on a pulldown system. Also I used debounce for the button so it can't change it's state in an interval less than 50 milliseconds. Lastly, the millis() function takes the place of delay(), allowing other code instructions to execute while waiting. 
 
 ### Image files
 #### Checkout this link
 https://www.youtube.com/watch?v=EJAYpygHkiI&list=PLASPWLXL8uFXgAFEjd-jlXm1SQpGpdLho&index=2&ab_channel=CruceanuCalin
 #### Setup photos
 ![WhatsApp Image 2022-11-03 at 18 00 12 (1)](https://user-images.githubusercontent.com/80258120/199771798-64d78e0c-d45f-429f-9ff9-e62293be4892.jpeg)
.jpeg)
 ![WhatsApp Image 2022-11-03 at 18 00 12 (2)](https://user-images.githubusercontent.com/80258120/199771882-c838ade3-b7be-4c21-aedd-60dfad0855c7.jpeg)

 
