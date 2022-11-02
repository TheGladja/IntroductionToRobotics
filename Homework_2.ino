//the LED entry for car traffic lights
const int redLedCar = 10;
const int yellowLedCar = 9;
const int greenLedCar = 8;

//the LED entry for pedestrian traffic lights
const int redLedPedestrian = 7;
const int greenLedPedestrian = 6;

//the buzzer entry
const int buzzerPin = 5;

//the button entry
const int pushButton = 2;

//values for the button
byte readPushButton = 0;

//for the blinking led and the beeping buzzer
unsigned int i = 0;

//for the millis function
unsigned long previousTime = millis();

//for the coming states
bool State1 = 1;
bool State2 = 0;
bool State3 = 0;
bool State4 = 0;

//for the two intervals of state 2
bool State2_Step1 = 1;
bool State2_Step2 = 0;

//beeping counter for state 3
unsigned int beepCounterState3 = 0;
unsigned int beepCounterState4 = 0;

//for debouncing the button
unsigned long lastTimeButtonChanged = millis();
unsigned long debounceDuration = 50;

void entryPin(){
  pinMode(redLedCar, OUTPUT);
  pinMode(yellowLedCar, OUTPUT);
  pinMode(greenLedCar, OUTPUT);
  pinMode(redLedPedestrian, OUTPUT);
  pinMode(greenLedPedestrian, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(pushButton, INPUT);  
}

void ledsOff(){
  digitalWrite(redLedCar, LOW);
  digitalWrite(yellowLedCar, LOW);
  digitalWrite(greenLedCar, LOW);
  digitalWrite(redLedPedestrian, LOW);
  digitalWrite(greenLedPedestrian, LOW);
}

void State_1(){
  if(millis() - lastTimeButtonChanged >= debounceDuration){
    //read the button value
    readPushButton = digitalRead(pushButton);  
  
    //button is not pushed
    if(readPushButton == 0){
      digitalWrite(redLedCar, LOW);
      digitalWrite(yellowLedCar, LOW);
      digitalWrite(greenLedCar, HIGH); 
      digitalWrite(redLedPedestrian, HIGH);
      digitalWrite(greenLedPedestrian, LOW);
    }
    //button is pushed
    else if(readPushButton == 1){
      State1 = 0;
      State2 = 1;  

      lastTimeButtonChanged = millis();
      previousTime = millis();
    }
  }
}

void State_2(){
  if(millis() - previousTime >= 8000){
    if(State2_Step1 == 1){
      digitalWrite(redLedCar, LOW);
      digitalWrite(yellowLedCar, HIGH);
      digitalWrite(greenLedCar, LOW); 
      digitalWrite(redLedPedestrian, HIGH);
      digitalWrite(greenLedPedestrian, LOW); 

      State2_Step1 = 0; 
      State2_Step2 = 1; 
    
      previousTime = millis();                
    }
  }
  
  if(millis() - previousTime >= 3000){
    if(State2_Step2 == 1){
      State2_Step1 = 1; 
      State2_Step2 = 0; 
      
      State2 = 0;
      State3 = 1;

      previousTime = millis();      
    }   
  }
}

void State_3(){
  digitalWrite(redLedCar, HIGH);
  digitalWrite(yellowLedCar, LOW);
  digitalWrite(greenLedCar, LOW); 
  digitalWrite(redLedPedestrian, LOW);
  digitalWrite(greenLedPedestrian, HIGH);

  //the buzzer beeping
  if(millis() - previousTime >= 1000){
    if(beepCounterState3 < 8){
      tone(buzzerPin, 2000, 200);
      
      beepCounterState3++;      

      previousTime = millis();
    }
    else{
      beepCounterState3 = 0;

      State3 = 0;
      State4 = 1;

      previousTime = millis();
    }
  }  
}

void State_4(){
  digitalWrite(redLedCar, HIGH);
  digitalWrite(yellowLedCar, LOW);
  digitalWrite(greenLedCar, LOW); 
  digitalWrite(redLedPedestrian, LOW);

  //blinking green light and beeping buzzer
  if(millis() - previousTime >= 500){
    if(beepCounterState4 < 8){
      //led off and buzzer not beeping
      if(beepCounterState4 % 2 == 0){
        tone(buzzerPin, 3000, 200);
        digitalWrite(greenLedPedestrian, LOW);
      }
      //led on and buzzer beeping
      else{
        tone(buzzerPin, 3000, 200);
        digitalWrite(greenLedPedestrian, HIGH);        
      }
      
      beepCounterState4++;      

      previousTime = millis();
    }
    else{
      beepCounterState4 = 0;

      State4 = 0;
      State1 = 1;
    }
  }  
}

void setup() {
  //declaring the in and out pins
  entryPin();

  //initially all the leds are turned off
  ledsOff();
}

void loop() {
  //State 1
  if(State1 == 1){
    State_1();      
  }
  //State 2
  if(State2 == 1){
    State_2();
  }
  //State 3
  else if(State3 == 1){
    State_3();
  }
  //State 4
  else if(State4 == 1){
    State_4();    
  }
}
