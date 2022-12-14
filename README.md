 # Introduction to Robotics (2021 - 2022)
 Introduction to Robotics laboratory homeworks, taken in the 3rd year at the Faculty of Mathematics and Computer Science, University of Bucharest. Here I will post every homework and project covered by this course throughout the semester. Also, each material will be as perfectly structured as possible, that means including every detail about the subject (such as requirements, implementation details, code and image files) in order to make things more understandable. Give it a go!
 
 ### !!!The last homework description is on the bottom part of the page!!!

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
 Building the traffic lights for a crosswalk. You will use 2 LEDs to represent the traffic lights for people (red and green) and 3 LEDs to represent the traffic lights for cars (red, yellow and green). See the states it needs to go through. It???s a traffic lights system for people and cars - don???t overthink it.
 
 ##### 1. State 1(default, reinstated after state 4 ends):  
 Green light for cars, red light for people, no sounds. Duration: indefinite, changed by pressing the button.
 ##### 2. State 2(initiated by counting down 8 seconds after a button press):
 The light should be yellow for cars, red for people and no sounds. Duration: 3 seconds.
 ##### 3. State 3(initiated after state 2 ends): 
 Red for cars, green for people and a beeping sound from the buzzer at a constant interval. Duration: 8 seconds.
 ##### 4. State 4(initiated after state 3 ends): 
 Red for cars, blinking green for people and a beeping sound from the buzzer, at a constant interval, faster than the beeping in state 3. This state should last 4 seconds.
 
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
 
 ## Homework 3

 ### Requirements 
 #### Technical Task
 You will use the joystick to control the position of the segment and ???draw??? on the display. The movement between segments should be natural (meaning they should jump from the current position only to neighbors, but without passing through ???walls???.
 
 ##### State 1(default, but also initiated after a button press in State 2): 
 Current position blinking. Can use the joystick to move from one position to neighbors. Short pressing the button toggles state 2. Long pressing the button in state 1 resets the entire display by turning all the segments OFF and moving the current position to the decimal point.
 ##### State 2(initiated after a button press in State 1):
 The current segment stops blinking, adopting the state of the segment before selection (ON or OFF). Toggling the X (or Y, you chose) axis should change the segment  state from ON to OFF or from OFF to ON. Clicking the joystick should save the segment state and exit back to state 1.
 
 #### Be careful:
 1. Long pressing the button to reset should only be available in State1.
 2. Joystick movements should be done with toggle, as in the lab (joy-Moved, etc.).
 3. Correctly using interrupts with  debounce yields a bonus, but it is not a must. Code for homework with bonus points should be submitted before the course, not the lab.
 4. The code in the lab for joystick movement is not perfect and can be improved. The state change is missing something (sounds familiar?), the code should be wrapped in a function and the constraint between 0 and 9 can be simplified.
 
 #### Coding task
 Coding style is of utmost importance. You must have a perfectly clean code in order to receive the maximum grade. An important coding challenge present in this task is using millis() instead of delay(). However, remember that the bulk of the grade is if the project works. Do not tend to small details unless you have the entire functionality done.
 
 ### Details
 In this homework I made a seven LED display and a joystick work together. Joystick movement is done with toggle as in the lab, I used a matrix for the movement of the leds which helps you identify the accessible positions, as well as an array that remembers if the leds are turned off or on. For the difference between the short pressing button and the long pressing one I used a series of debouncing methods (several validators and verification lines) in order to recognize exactly the type of button press. Lastly, the millis() function takes the place of delay(), allowing other code instructions to execute while waiting. 
 
 ### Image files
 #### Checkout this link
 https://www.youtube.com/watch?v=kPTVBHkOPv0&list=PLASPWLXL8uFXgAFEjd-jlXm1SQpGpdLho&index=3&ab_channel=CruceanuCalin
 #### Setup photos
 ![WhatsApp Image 2022-11-09 at 19 37 04](https://user-images.githubusercontent.com/80258120/200901431-53cdefbe-cea0-4bed-9a6a-3aa0e7a384a1.jpeg)
 ![WhatsApp Image 2022-11-09 at 19 37 03](https://user-images.githubusercontent.com/80258120/200901448-f8c66288-0311-4406-8ccb-379645deeed9.jpeg)
 
 ## Homework 4

 ### Requirements 
 
 #### Components
 A joystick, a 4 digit 7-segment display, a 74hc595 shift register.
 
 #### Technical Task
 Use the joystick to move through the 4 digit 7 segment displays digits, press the button to lock in on the current digit and use the other axis to increment or decrement the number. Keep the button pressed to reset all the digit values and the current position to the first digit in the first state.
 
 #### The system has the following states
 
 ##### First state: 
 You can use a joystick axis to cycle through the 4 digits; using the other axis does nothing. A blinking decimal point shows the current digit position. When pressing the button, you lock in on the selected digit and enter the second state.
 ##### Second state:
 In this state, the decimal point stays always on, no longer blinking and you can no longer use the axis to cycle through the 4 digits. Instead, using the other axis,  you can increment or decrement the number on the current digit IN HEX (aka from 0 to F, as in the lab). Pressing the button again returns you to the previous state.  Also, keep in mind that when changing the number, you must increment it for each joystick movement - it should not work continuosly increment if you keep the joystick in one position(aka with joyMoved).
 ##### Reset:
 Toggled by long pressing the button only in the first state. When resetting, all the digits go back to 0 and the current position is set to the first (rightmost) digit, in the first state.
 
 #### Be careful:
 1. You must use shift register.
 2. You must cycle all the way up to ???F??? in HEX.
 3. You need to add the ???reset??? functionality by keeping the button pressed.
 
 ##### Have fun!
 
 #### Coding task
 Coding style is of utmost importance. You must have a perfectly clean code in order to receive the maximum grade. An important coding challenge present in this task is using millis() instead of delay(). However, remember that the bulk of the grade is if the project works. Do not tend to small details unless you have the entire functionality done.
 
 ### Details
 In this homework I made a joystick controlled 4 by 7 segment display. Joystick movement is done with toggle as in the lab, I used a shift register to minimize the entry pins on the arduino board, in this case only the segment pins will go directly to the arduino. This homework is similar to the previous homework, the joystick movement on Ox axis moves the current segment from left to right and the movement on Oy axis changes the value of the current segment. The long and short pressing of the button is the same as in homework 3. Lastly, I used an array for holding each one of the 4 segments value so every time the program will run through the loop it will map the correct values.
 
 ### Image files
 #### Checkout this link
 https://www.youtube.com/watch?v=_0SVNLVXcN0&list=PLASPWLXL8uFXgAFEjd-jlXm1SQpGpdLho&index=4
 #### Setup photos
 ![WhatsApp Image 2022-11-15 at 12 42 18](https://user-images.githubusercontent.com/80258120/201899817-d140d1ac-568f-488f-a722-de24cdef4d7f.jpeg)
 ![WhatsApp Image 2022-11-15 at 12 42 19](https://user-images.githubusercontent.com/80258120/201899841-d30987ff-1faa-4f5b-9eab-aa3083304b54.jpeg)
 ![WhatsApp Image 2022-11-15 at 12 42 19 (1)](https://user-images.githubusercontent.com/80258120/201899862-67e4d671-b57f-4ad3-89b1-edc555505b12.jpeg)
 
 ## Homework 5 (game menu)

 ### Requirements 
 
 #### Components
 An LCD, a joystick, a buzzer, led matrix, potentiometer and a max7219 datasheet.
 
 #### Menu
 
 ##### -Intro message
 
 ##### -Start Game
 * Shown details while playing.
 * Screen(s) upon game ending with input in order to move on.
 * Informs you when highscore is achieved.
 * Enter name for highscore (if not already entered).
 
 ##### -Highscore
 At least top 5 in eeprom with name and score.
 
 ##### -Settings
 ??? Enter name (can be somewhere else, depending on how and where you use it).
 ??? Starting level / difficulty or something similar, depending on game logic.
 ??? LCD contrast control (eeprom) - optional.
 ??? LCD brightness control (eeprom).
 ??? Matrix brightness control (eeprom). Light up the entire matrix when changing it, so you can see the actual difference.
 ??? Sound control on/off (eeprom).
 ??? Reset highscores button in settings.
 
 ##### -About
 Github link/user (specifcy if user!), developer name and game name.
 
 ##### -How to play
 Short and informative description.
 
 ##### -Navigation style
 Usability, intiuitive, beauty. Different ???picture??? on the matrix for each menu category (hammer for settings, challice for highscore etc). Should do a small sound  when changing selected menu category etc.
 
 ##### Have fun!
 
 #### Coding task
 Coding style is of utmost importance. You must have a perfectly clean code in order to receive the maximum grade. An important coding challenge present in this task is using millis() instead of delay(). However, remember that the bulk of the grade is if the project works. Do not tend to small details unless you have the entire functionality done.
 
 ### Details
 
 #### When starting the menu you will hear the authentic Nokia sound.
 
 #### Introduction
 * The game title.
 * A short welcoming scrolling message.
 
 #### Menu (each part will have a different matrix picture)
 You will see a star in the right part of the LCD indicating the current position on the menu.
 Press the joystick button to enter each of these menu parts:
 
 ##### 1. Start game.
 
 ###### Enter player name
 You will need to enter a 6 letter user name.
 Up on the LCD screen a down arrow will indicate the current letter.
 Use the joystick up/down to change the current letter and left/right to cycle through letters.
 Long press the joystick button for 3 seconds to enter the next state.
 
 ###### Select difficulty level
 Use the joystick left/right to select a difficulty level and then press the joystick button to start the game.
 There will be arrows on the upper side of the LCD indicating the position.
 
 ##### 2. Highscore.
 Use the joystick left/right to cycle through the top 5 players.
 Press the joystick button to return to the menu.
 
 ##### 3. Settings.
 Use the joystick left/right to cycle through each setting.
 Press the joystick button to return to the menu.
 
 ###### Led shine
 Use the joystick up/down to select the LCD brightness (0 to 5).
 
 ###### Matrix shine
 Use the joystick up/down to select the matrix brightness (0 to 5).
 
 ###### Sound
 Use the joystick up/down to control the sound (on/off).
 
 ##### 4. About.
 A short scrolling message describing the creator github link, creator name and game name.
 Press the joystick button to return to the menu.
 
 ##### 5. How to play.
 A short scrolling message description about how to play the game.
 Press the joystick button to return to the menu.
 
 ##### 6. Reset score
 Use the joystick up/down to select RESET (reset the highscore the returns you to the menu) or CANCEL (return to menu).
 
 ### Image files
 #### Checkout this link
 https://www.youtube.com/watch?v=s0oF2kljLoA&list=PLASPWLXL8uFXgAFEjd-jlXm1SQpGpdLho&index=5&ab_channel=CruceanuCalin
 #### Setup photos
 ![WhatsApp Image 2022-12-09 at 13 34 55](https://user-images.githubusercontent.com/80258120/206701556-49a8d51d-342c-409e-85d0-fe3b9530755f.jpeg)
 ![WhatsApp Image 2022-12-09 at 13 34 56](https://user-images.githubusercontent.com/80258120/206701566-80867869-d0b1-402c-a5cd-710e775bdea8.jpeg) 
 ![WhatsApp Image 2022-12-09 at 13 34 56 (1)](https://user-images.githubusercontent.com/80258120/206701589-091c85c1-54e3-4ebf-ac90-6fa69a9af2c8.jpeg)






 
