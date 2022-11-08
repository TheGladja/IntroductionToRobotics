// declare all the joystick pins
const int pinSW = 2; // digital pin connected to switch output
const int pinX = A0; // A0 - analog pin connected to X output
const int pinY = A1; // A1 - analog pin connected to Y output

// declare all the segments pins
const int pinA = 4;
const int pinB = 5;
const int pinC = 6;
const int pinD = 7;
const int pinE = 8;
const int pinF = 9;
const int pinG = 10;
const int pinDP = 11;
const int inaccessible = -1;

const int segSize = 8;

byte dpState = LOW;
int xValue = 0;
int yValue = 0;

int minThreshold = 400;
int maxThreshold = 600;

int segments[segSize] = { 
  pinA, pinB, pinC, pinD, pinE, pinF, pinG, pinDP
};

byte rememberLeds[segSize] = {
  LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW    
};

//size of segmentMatrix
const int noOfMovements = 4;
const int noOfLeds = 8;

//start position and Oxy coordinates
int startOx = 2;
int startOy = 3;
int ox = startOx;
int oy = startOy;
int nextOx = 0;
int nextOy = 0;

//movement matrix
int segmentMatrix[noOfLeds][noOfMovements] = {
// up down left right
 {inaccessible, pinG, pinF, pinB}, // a
 {pinA, pinG, pinF, inaccessible}, // b
 {pinG, pinD, pinE, pinDP}, // c
 {pinG, inaccessible, pinE, pinC}, // d
 {pinG, pinD, inaccessible, pinC}, // e
 {pinA, pinG, inaccessible, pinB}, // f
 {pinA, pinD, inaccessible, inaccessible},// g
 {inaccessible, inaccessible, pinC, inaccessible} // dp
};

//for the movement and remembering of leds
const int blinkTime = 400;
unsigned long prevTime = 0;
byte highLed = HIGH;
bool buttonPressedOnce = false;
bool buttonPressedTwice = true;
int currentLed = 0;
int rememberLedsCorrespondingValue = 0;
bool joyMoved = false;

//for the readButton function
int buttonStatePrevious = LOW;
unsigned long minButtonLongPressDuration = 3000;
unsigned long buttonLongPressMillis;
bool buttonStateLongPress = false;
const int intervalButton;
unsigned long previousButtonMillis;
unsigned long buttonPressDuration;
unsigned long currentMillis;

void setup() {
  // initialize all the pins
  for (int i = 0; i < segSize; i++) {
    pinMode(segments[i], OUTPUT);
  }
  pinMode(pinSW, INPUT_PULLUP);
}

void loop() {
  if(buttonPressedOnce == false){
    stateOne();        
  }
  else if(buttonPressedTwice == false){
    stateTwo();
  }
  if (xValue >= minThreshold && xValue <= maxThreshold && yValue >= minThreshold && yValue <= maxThreshold) {
    joyMoved = false;
  }  
}

void stateOne(){
  readValues();

  readButton();

  //blink
  Blink();  
  
  //move down
  if (xValue < minThreshold && joyMoved == false){
    moveDown();
    joyMoved = true; 
  }
  //move up
  if (xValue > maxThreshold && joyMoved == false){
    moveUp();
    joyMoved = true;
  }
  //move left
  if(yValue < minThreshold && joyMoved == false){
    moveLeft();
    joyMoved = true;
  }
  //move right
  if(yValue > maxThreshold && joyMoved == false){
    moveRight();
    joyMoved = true;
  }
}

void stateTwo(){
  readValues();
  
  displayOnOrOff();

  //move left
  if (yValue < minThreshold && joyMoved == false){
    turnOnLed();
    joyMoved = true;        
  }
  //move right
  if (yValue > maxThreshold && joyMoved == false){
    turnOffLed();
    joyMoved = true;      
  }
  readButton();
}

void displayOnOrOff(){
  rememberLedsCorrespondingValue = segmentMatrix[ox][oy] - 4;
  digitalWrite(segmentMatrix[ox][oy], rememberLeds[rememberLedsCorrespondingValue]);  
}

void turnOnLed(){
  rememberLeds[rememberLedsCorrespondingValue] = HIGH;
}

void turnOffLed(){
  rememberLeds[rememberLedsCorrespondingValue] = LOW;
}

void readValues(){
  xValue = analogRead(pinX);
  yValue = analogRead(pinY);
}

void moveDown(){
  nextOx = segmentMatrix[ox][oy] - 4;
  nextOy = 1;    

  if(segmentMatrix[nextOx][nextOy] != inaccessible){
    digitalWrite(segmentMatrix[ox][oy], rememberLeds[nextOx]);
    ox = nextOx;
    oy = nextOy;       
  }
}

void moveUp(){
  nextOx = segmentMatrix[ox][oy] - 4;
  nextOy = 0;

  if(segmentMatrix[nextOx][nextOy] != inaccessible){
    digitalWrite(segmentMatrix[ox][oy], rememberLeds[nextOx]);
    ox = nextOx;
    oy = nextOy;
  }
}

void moveLeft(){
  nextOx = segmentMatrix[ox][oy] - 4;
  nextOy = 2;

  if(segmentMatrix[nextOx][nextOy] != inaccessible){
    digitalWrite(segmentMatrix[ox][oy], rememberLeds[nextOx]);
    ox = nextOx;
    oy = nextOy;
  }
}

void moveRight(){
  nextOx = segmentMatrix[ox][oy] - 4;
  nextOy = 3;

  if(segmentMatrix[nextOx][nextOy] != inaccessible){
    digitalWrite(segmentMatrix[ox][oy], rememberLeds[nextOx]);
    ox = nextOx;
    oy = nextOy;
  }  
}

void Blink(){
  currentLed = segmentMatrix[ox][oy];
  if(millis() - prevTime >= blinkTime){
      if(highLed == HIGH){
        digitalWrite(currentLed, highLed);
        highLed = LOW;          
        prevTime = millis();           
      }
      else{
        digitalWrite(currentLed, highLed);
        highLed = HIGH;
        prevTime = millis();
      }
    }    
}

void readButton(){
  currentMillis = millis();

  if(currentMillis - previousButtonMillis > intervalButton){
    dpState = digitalRead(pinSW);
    dpState = !dpState;

    if(dpState == HIGH && buttonStatePrevious == LOW && !buttonStateLongPress){
      buttonLongPressMillis = currentMillis;
      buttonStatePrevious = HIGH;
    } 

    buttonPressDuration = currentMillis - buttonLongPressMillis;

    //for the long pressing button
    if(dpState == HIGH && !buttonStateLongPress && buttonPressDuration >= minButtonLongPressDuration){
      buttonStateLongPress = true;
       
      if(buttonPressedOnce == false){
        resetLeds();  
      } 
    }

    if(dpState == LOW && buttonStatePrevious == HIGH){
      buttonStatePrevious = LOW;
      buttonStateLongPress = false;

      //for the short pressing button
      if(!buttonStateLongPress && buttonPressDuration < minButtonLongPressDuration){
        if(buttonPressedTwice == true){
          buttonPressedOnce = true;
          buttonPressedTwice = false; 
        }
        else if(buttonPressedOnce == true){
          buttonPressedOnce = false;
          buttonPressedTwice = true;
        }      
      }      
    }
  }  
}

void resetLeds(){
  for (int i = 0; i < segSize; i++) {
    currentLed = i + 4;
    rememberLeds[i] = LOW;
    digitalWrite(currentLed, LOW);
  }
  //reset position
  ox = startOx;
  oy = startOy;
  buttonPressedOnce = false;
}
