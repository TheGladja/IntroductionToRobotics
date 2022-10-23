 # Introduction to Robotics (2021 - 2022)
 Introduction to Robotics laboratory homeworks, taken in the 3rd year at the Faculty of Mathematics and Computer Science, University of Bucharest. Here I will post every homework and project covered by this course throughout the semester. Also, each material will be as perfectly structured as possible, that means including every detail about the subject (such as requirements, implementation details, code and image files) in order to make things more understandable. Give it a go!

 ## Homework 1

 ### Requirements 
 #### Technical Task
 Use a separat potentiometer in controlling each of thecolor of the RGB led (Red,Green andBlue). The control must be done with digital electronics (aka you must read the value of the potentiometer with Arduino, and write a mapped value to each of the pins connected to the led.
 #### Coding task
 Coding style is of utmost importance. You must have aperfectly clean code in order to receive the maximum grade. Keep in mind that magic numbers are not accepted, although you might see them in the lab(as a trade-off for speed). Remember to be consistent in your style, check the style guide and the provided style  document and use correct spacing.
 
 ### Details
 In this homework I made a three potentiometer controlled rgb led. Each potentiometer is assigned to one of the colors (red, green and blue) and so the brightness, intensity and the color can be controlled by hand. The code structure is fairly simple, we read the value given by the potentiometers and apply the write value (voltage divided by the read value) to each color of the led.
 
 ### Image files
 Checkout this link: https://www.youtube.com/watch?v=-pjyUkCzI64&list=PLASPWLXL8uFXgAFEjd-jlXm1SQpGpdLho&index=1&ab_channel=CruceanuCalin
