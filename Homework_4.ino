// declare all the joystick pins
const int pinSW = 2;  // digital pin connected to switch output
const int pinX = A1;  // A0 - analog pin connected to X output
const int pinY = A0;  // A1 - analog pin connected to Y output

byte buttonValue = LOW;
int xValue = 0;
int yValue = 0;

//DS= [D]ata [S]torage - data
//STCP= [ST]orage [C]lock [P]in latch
//SHCP= [SH]ift register [C]lock [P]in clock

const int latchPin = 11;  // STCP to 12 on Shift Register
const int clockPin = 10;  // SHCP to 11 on Shift Register
const int dataPin = 12;   // DS to 14 on Shift Register

const int segD1 = 7;
const int segD2 = 6;
const int segD3 = 5;
const int segD4 = 4;

const int startNumber = 0;
const int startDp = 0;
unsigned long prevTime = 0;
const long blinkTime = 500;
bool highLed = false;
int lastSeg = 0;
int thirdSeg = 0;
int secondSeg = 0;
int firstSeg = 0;

int displayDigits[] = {
  segD1, segD2, segD3, segD4
};
const int displayCount = 4;

const int encodingsNumber = 16;

int currentDp = 0;
bool joyMoved = false;
const int minThreshold = 400;
const int maxThreshold = 600;
bool firstState = true;
bool secondState = false;

int currentNumbers[displayCount]{
  lastSeg, thirdSeg, secondSeg, firstSeg
};

int byteEncodings[encodingsNumber] = {
  //A B C D E F G DP
  B11111100,  // 0
  B01100000,  // 1
  B11011010,  // 2
  B11110010,  // 3
  B01100110,  // 4
  B10110110,  // 5
  B10111110,  // 6
  B11100000,  // 7
  B11111110,  // 8
  B11110110,  // 9
  B11101110,  // A
  B00111110,  // b
  B10011100,  // C
  B01111010,  // d
  B10011110,  // E
  B10001110   // F
};

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
  // put your setup code here, to run once:
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  for (int i = 0; i < displayCount; i++) {
    pinMode(displayDigits[i], OUTPUT);
    digitalWrite(displayDigits[i], LOW);
  }

  pinMode(pinSW, INPUT_PULLUP);
}

void loop() {
  if (firstState) {
    stateOne();
  } else if (secondState) {
    stateTwo();
  }

  readButton();
}

void stateTwo() {
  yValue = analogRead(pinY);

  displayEncodings();

  //move down
  if (yValue < minThreshold && joyMoved == false) {
    if (currentNumbers[currentDp] > 0) {
      currentNumbers[currentDp]--;
    }
    joyMoved = true;
  }
  //move up
  if (yValue > maxThreshold && joyMoved == false) {
    if (currentNumbers[currentDp] < encodingsNumber - 1) {
      currentNumbers[currentDp]++;
    }
    joyMoved = true;
  }

  if (yValue >= minThreshold && yValue <= maxThreshold) {
    joyMoved = false;
  }
}

void stateOne() {
  xValue = analogRead(pinX);

  displayEncodings();

  //move left
  if (xValue < minThreshold && joyMoved == false) {
    if (currentDp < 3) {
      currentDp++;
    }
    joyMoved = true;
  }
  //move right
  if (xValue > maxThreshold && joyMoved == false) {
    if (currentDp > 0) {
      currentDp--;
    }
    joyMoved = true;
  }

  if (xValue >= minThreshold && xValue <= maxThreshold) {
    joyMoved = false;
  }
}

void displayEncodings() {
  for (int i = 0; i < displayCount; i++) {
    byte encoding = byteEncodings[currentNumbers[i]];

    if (i == currentDp) {
      if (firstState) {
        Blink(encoding);
      } else if (secondState) {
        encoding++;
      }
    }

    writeReg(encoding);
    digitalWrite(displayDigits[i], LOW);
    delay(1);
    digitalWrite(displayDigits[i], HIGH);
  }
}

void writeReg(int encoding) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, encoding);
  digitalWrite(latchPin, HIGH);
}

void Blink(byte &encoding) {
  if (millis() - prevTime >= blinkTime) {
    prevTime = millis();
    highLed = !highLed;
  }
  if (highLed) {
    encoding += 1;
  }
}

void readButton() {
  currentMillis = millis();

  if (currentMillis - previousButtonMillis > intervalButton) {
    buttonValue = digitalRead(pinSW);
    buttonValue = !buttonValue;

    if (buttonValue == HIGH && buttonStatePrevious == LOW && !buttonStateLongPress) {
      buttonLongPressMillis = currentMillis;
      buttonStatePrevious = HIGH;
    }

    buttonPressDuration = currentMillis - buttonLongPressMillis;

    //for the long pressing button
    if (buttonValue == HIGH && !buttonStateLongPress && buttonPressDuration >= minButtonLongPressDuration) {
      buttonStateLongPress = true;

      if (firstState) {
        resetSegments();
      }
    }

    if (buttonValue == LOW && buttonStatePrevious == HIGH) {
      buttonStatePrevious = LOW;
      buttonStateLongPress = false;

      //for the short pressing button
      if (!buttonStateLongPress && buttonPressDuration < minButtonLongPressDuration) {
        if (firstState) {
          secondState = true;
          firstState = false;
        } else if (secondState) {
          secondState = false;
          firstState = true;
        }
      }
    }
  }
}

void resetSegments() {
  for (int i = 0; i < displayCount; i++) {
    currentNumbers[i] = startNumber;
  }
  currentDp = startDp;
}
