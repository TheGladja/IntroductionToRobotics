#include <LiquidCrystal.h>
#include <LedControl.h>

//for the intro song
#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978
#define REST 0
// change this to make the song slower or faster
int tempo = 220;
// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
int melody[] = {
  // Nokia Ringtone
  // Score available at https://musescore.com/user/29944637/scores/5266155

  NOTE_E5,
  8,
  NOTE_D5,
  8,
  NOTE_FS4,
  4,
  NOTE_GS4,
  4,
  NOTE_CS5,
  8,
  NOTE_B4,
  8,
  NOTE_D4,
  4,
  NOTE_E4,
  4,
  NOTE_B4,
  8,
  NOTE_A4,
  8,
  NOTE_CS4,
  4,
  NOTE_E4,
  4,
  NOTE_A4,
  2,
};
// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
int notes = sizeof(melody) / sizeof(melody[0]) / 2;
// this calculates the duration of a whole note in ms
int wholenote = (60000 * 4) / tempo;
int divider = 0, noteDuration = 0;

const byte buzzerPin = A2;

const byte dinPin = 12;
const byte clockPin = 11;
const byte loadPin = 10;
const byte matrixSize = 8;
// pin 12 is connected to the MAX7219 pin 1
// pin 11 is connected to the CLK pin 13
// pin 10 is connected to LOAD pin 12
// 1 as we are only using 1 MAX7219
LedControl lc = LedControl(dinPin, clockPin, loadPin, 1);  //DIN, CLK, LOAD, No. DRIVER
byte matrixBrightness = 15;
byte snake[matrixSize] = { 0x7F, 0x41, 0xCF, 0x88, 0x88, 0x82, 0x85, 0x02 };
byte startGame[matrixSize] = { 0x38, 0x44, 0x88, 0x91, 0x88, 0x44, 0x38, 0x00 };
byte highscore[matrixSize] = { 0x1C, 0x3E, 0x7F, 0x49, 0x7F, 0x63, 0x7F, 0x55 };
byte settings[matrixSize] = { 0x3C, 0x7E, 0x7E, 0x3C, 0x18, 0x18, 0x18, 0x18 };
byte about[matrixSize] = { 0xFF, 0x81, 0xA5, 0x81, 0xBD, 0xBD, 0x81, 0xFF };
byte howToPlay[matrixSize] = { 0x30, 0x30, 0x1C, 0x7A, 0x38, 0x3C, 0x3E, 0x30 };
byte resetHighscore[matrixSize] = { 0x00, 0x66, 0x99, 0x81, 0x42, 0x24, 0x18, 0x00 };

const byte rs = 9;
const byte en = 8;
const byte d4 = 7;
const byte d5 = 6;
const byte d6 = 5;
const byte d7 = 4;
const byte intensity = 3;

const int pinSW = 2;  // digital pin connected to switch output
const int pinX = A0;  // A0 - analog pin connected to X output
const int pinY = A1;  // A1 - analog pin connected to Y output

byte buttonValue = LOW;
int xValue = 0;
int yValue = 0;
bool joyMoved = false;
bool brightnessJoyMoved = false;
bool modifyLetterJoyMoved = false;
const int minThreshold = 400;
const int maxThreshold = 600;
const int menuDisplayNumber = 6;
const int settingsDisplayNumber = 3;
const int levelDisplayNumber = 3;
const int rankDisplayNumber = 5;
int currentMenuDisplay = 0;
int currentSettingsDisplay = 0;
int currentLevelDisplay = 0;
int currentRankDisplay = 0;
String menuDisplay[menuDisplayNumber] = { "1. Start Game", "2. Highscore", "3. Settings", "4. About", "5. How To Play", "6. Reset Score" };
String settingsMenuDisplay[settingsDisplayNumber] = { "Led Shine:", "Matrix Shine:", "Sound:" };
String levelDisplay[levelDisplayNumber] = { " EASY ", "MEDIUM", " HARD " };
String rankDisplay[rankDisplayNumber] = { "1st.", "2nd.", "3rd.", "4th.", "5th." };
String playerNameDisplay[rankDisplayNumber] = { "OLIVER", "DANIEL", "SAMUEL", "CARTER", "JULIAN" };
int playerScoreDisplay[rankDisplayNumber] = { 5, 4, 3, 2, 1 };
String clearLcd = "                ";
bool cursorPosition = false;
String newPlayer = "";
int newScore = 10;
String emptyString = "";

char* introText = "Hello and Welcome to the amazing Cozy Snake Game!!! Press the button to enter menu...                ";
int introTextLineNumber = 1;
char* aboutText = "Github link: https://github.com/TheGladja, Creator name: Cruceanu Calin, Game name: The Cozy Snake                ";
int aboutTextLineNumber = 1;
char* howToPlayText = "Random food(dots) will spawn on the playground. Use the joystick to gather as much food as you can in 1 minute in order to beat the highscore. Good luck fellow gamer and may the force be with you. Hurry up, you don't have much time...                ";
int howToPlayTextLineNumber = 1;
const int defaultTextCursor = 0;
int scrollingTextCursor = 0;

//for the readButton function
int buttonStatePrevious = LOW;
unsigned long minButtonLongPressDuration = 3000;
unsigned long buttonLongPressMillis;
bool buttonStateLongPress = false;
const int intervalButton = 200;
unsigned long previousButtonMillis;
unsigned long buttonPressDuration;
unsigned long currentMillis;
unsigned long previousTime = 0;
const int scrollTextTime = 400;

const int alphabetLetterNumber = 25;
int currentEnterNameLetter = 0;
const int playerNameLetterNumber = 6;
int enterNameLetters[playerNameLetterNumber] = { 0, 0, 0, 0, 0, 0 };
char alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int enterNameLeftLimit = 9;
const int enterNameRightLimit = 14;
int enterNameArrowPosition = 9;
int menuCursor = 1;
bool introduction = true;
bool menu = false;
bool aboutDisplay = false;
bool howToPlayDisplay = false;
bool settingsDisplay = false;
bool resetScoreDisplay = false;
bool highscoreDisplay = false;
bool startGameDisplay = false;
bool enterUserNameDisplay = true;
bool enterLevelDisplay = false;
int lcdShine = 5;
int lcdShineStep = 50;
int matrixShine = 5;
int matrixShineStep = 3;
String soundSetting = "on";
bool sound = true;
bool resetScore = false;

String test = "";

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // the zero refers to the MAX7219 number, it is zero for 1 chip
  lc.shutdown(0, false);  // turn off power saving, enables display
  lc.clearDisplay(0);     // clear screen

  lcd.begin(16, 2);
  pinMode(intensity, OUTPUT);
  pinMode(pinSW, INPUT_PULLUP);
  introSong();
}

void loop() {
  if (introduction) {
    displayIntro();
  } else if (menu) {
    displayMenu();
  } else if (aboutDisplay) {
    aboutMenu();
  } else if (howToPlayDisplay) {
    howToPlayMenu();
  } else if (settingsDisplay) {
    settingsMenu();
  } else if (resetScoreDisplay) {
    resetScoreMenu();
  } else if (highscoreDisplay) {
    highscoreMenu();
  } else if (startGameDisplay) {
    startGameMenu();
  }
  analogWrite(intensity, (lcdShine * lcdShineStep));
  lc.setIntensity(0, (matrixShine * matrixShineStep));
}

void displayIntro() {
  displayIntroFigure();
  lcd.setCursor(1, 0);
  lcd.print("The Cozy Snake");
  scrollingMessage(introText, introTextLineNumber);
  readIntroductionButton();
}

void displayIntroFigure() {
  printByte(snake);
}

void printByte(byte character[]) {
  int i = 0;
  for (i = 0; i < matrixSize; i++) {
    lc.setRow(0, i, character[i]);
  }
}

void scrollingMessage(char* Text, int TextLineNumber) {
  if (millis() - previousTime >= scrollTextTime) {
    int lengthOfText = strlen(Text);

    if (scrollingTextCursor == lengthOfText - 1) {
      scrollingTextCursor = 0;
    }
    lcd.setCursor(0, TextLineNumber);
    if (scrollingTextCursor < lengthOfText - 16) {
      for (int i = scrollingTextCursor; i < scrollingTextCursor + 16; i++) {
        lcd.print(Text[i]);
      }
    } else {
      for (int i = scrollingTextCursor; i < lengthOfText; i++) {
        lcd.print(Text[i]);
      }
      for (int i = 0; i <= 16 - (lengthOfText - scrollingTextCursor); i++) {
        lcd.print(Text[i]);
      }
    }
    scrollingTextCursor++;
    previousTime = millis();
  }
}

void displayMenu() {
  displayAnimation();

  yValue = analogRead(pinY);

  //the star position
  if (cursorPosition == false) {
    menuCursor = currentMenuDisplay + 1;
    lcd.setCursor(15, 1);
    lcd.print("*");
  } else {
    menuCursor = currentMenuDisplay + 2;
    if (currentMenuDisplay == menuDisplayNumber - 1) {
      menuCursor = 1;
    }
    lcd.setCursor(15, 0);
    lcd.print("*");
  }

  lcd.setCursor(0, 1);
  lcd.print(menuDisplay[currentMenuDisplay]);
  lcd.setCursor(0, 0);

  if (currentMenuDisplay == menuDisplayNumber - 1) {
    lcd.print(menuDisplay[0]);
  } else {
    lcd.print(menuDisplay[currentMenuDisplay + 1]);
  }

  //move up
  if (yValue < minThreshold && joyMoved == false) {
    if (cursorPosition == false) {
      cursorPosition = true;
    } else {
      if (currentMenuDisplay < menuDisplayNumber - 1) {
        currentMenuDisplay++;
      } else {
        currentMenuDisplay = 0;
      }
      cursorPosition = false;
    }

    if (sound) {
      tone(buzzerPin, 3000, 5);
    }
    clearScreen();
    lc.clearDisplay(0);
    joyMoved = true;
  }

  //move down
  if (yValue > maxThreshold && joyMoved == false) {
    if (cursorPosition == true) {
      cursorPosition = false;
    } else {
      if (currentMenuDisplay > 0) {
        currentMenuDisplay--;
      } else {
        currentMenuDisplay = 4;
      }
      cursorPosition = true;
    }

    if (sound) {
      tone(buzzerPin, 3000, 5);
    }
    clearScreen();
    lc.clearDisplay(0);
    joyMoved = true;
  }

  if (yValue >= minThreshold && yValue <= maxThreshold) {
    joyMoved = false;
  }
  readMenuButton();
}

void startGameMenu() {
  if (enterUserNameDisplay) {
    enterUserName();
  } else if (enterLevelDisplay) {
    enterLevel();
  }
  readMenuButton();
}

void enterLevel() {
  xValue = analogRead(pinX);

  //for the arrows
  if (currentLevelDisplay == 0) {
    lcd.setCursor(15, 0);
    lcd.print(">");
  } else if (currentLevelDisplay == levelDisplayNumber - 1) {
    lcd.setCursor(0, 0);
    lcd.print("<");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("<");
    lcd.setCursor(15, 0);
    lcd.print(">");
  }

  //display the image
  lcd.setCursor(3, 0);
  lcd.print("Difficulty");
  lcd.setCursor(5, 1);
  lcd.print(levelDisplay[currentLevelDisplay]);

  //move left
  if (xValue < minThreshold && joyMoved == false) {
    if (currentLevelDisplay < levelDisplayNumber - 1) {
      currentLevelDisplay++;
    }
    if (sound) {
      tone(buzzerPin, 3000, 5);
    }
    clearScreen();
    joyMoved = true;
  }

  //move right
  if (xValue > maxThreshold && joyMoved == false) {
    if (currentLevelDisplay > 0) {
      currentLevelDisplay--;
    }
    if (sound) {
      tone(buzzerPin, 3000, 5);
    }
    clearScreen();
    joyMoved = true;
  }

  //reset joystick
  if (xValue >= minThreshold && xValue <= maxThreshold) {
    joyMoved = false;
  }
}

void enterUserName() {
  lcd.setCursor(enterNameArrowPosition, 0);
  lcd.print("v");
  lcd.setCursor(0, 1);
  lcd.print("Name:");
  lcd.setCursor(8, 1);
  lcd.print(">");
  lcd.setCursor(15, 1);
  lcd.print("<");

  moveNameArrow();
  displayUserName();
  modifyLetter();
}

void modifyLetter() {
  yValue = analogRead(pinY);

  //move up
  if (yValue < minThreshold && modifyLetterJoyMoved == false) {
    if (enterNameLetters[currentEnterNameLetter] < alphabetLetterNumber) {
      enterNameLetters[currentEnterNameLetter]++;
    }
    if (sound) {
      tone(buzzerPin, 3000, 5);
    }
    clearScreen();
    modifyLetterJoyMoved = true;
  }

  //move down
  if (yValue > maxThreshold && modifyLetterJoyMoved == false) {
    if (enterNameLetters[currentEnterNameLetter] > 0) {
      enterNameLetters[currentEnterNameLetter]--;
    }
    if (sound) {
      tone(buzzerPin, 3000, 5);
    }
    clearScreen();
    modifyLetterJoyMoved = true;
  }

  if (yValue >= minThreshold && yValue <= maxThreshold) {
    modifyLetterJoyMoved = false;
  }
}

void displayUserName() {
  lcd.setCursor(9, 1);
  lcd.print(alphabet[enterNameLetters[0]]);
  lcd.setCursor(10, 1);
  lcd.print(alphabet[enterNameLetters[1]]);
  lcd.setCursor(11, 1);
  lcd.print(alphabet[enterNameLetters[2]]);
  lcd.setCursor(12, 1);
  lcd.print(alphabet[enterNameLetters[3]]);
  lcd.setCursor(13, 1);
  lcd.print(alphabet[enterNameLetters[4]]);
  lcd.setCursor(14, 1);
  lcd.print(alphabet[enterNameLetters[5]]);
}

void moveNameArrow() {
  xValue = analogRead(pinX);

  //move left
  if (xValue < minThreshold && joyMoved == false) {
    if (enterNameArrowPosition < enterNameRightLimit) {
      currentEnterNameLetter++;
      enterNameArrowPosition++;
    }
    if (sound) {
      tone(buzzerPin, 3000, 5);
    }
    clearScreen();
    joyMoved = true;
  }

  //move right
  if (xValue > maxThreshold && joyMoved == false) {
    if (enterNameArrowPosition > enterNameLeftLimit) {
      currentEnterNameLetter--;
      enterNameArrowPosition--;
    }
    if (sound) {
      tone(buzzerPin, 3000, 5);
    }
    clearScreen();
    joyMoved = true;
  }

  //reset joystick
  if (xValue >= minThreshold && xValue <= maxThreshold) {
    joyMoved = false;
  }
}

void settingsMenu() {
  xValue = analogRead(pinX);

  //for the arrows
  if (currentSettingsDisplay == 0) {
    lcd.setCursor(15, 0);
    lcd.print(">");
  } else if (currentSettingsDisplay == settingsDisplayNumber - 1) {
    lcd.setCursor(0, 0);
    lcd.print("<");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("<");
    lcd.setCursor(15, 0);
    lcd.print(">");
  }

  //display the menu settings static variables
  if (currentSettingsDisplay == 0) {
    lcd.setCursor(13, 1);
    lcd.print(lcdShine);
    lcd.setCursor(14, 1);
    lcd.print("/5");
  } else if (currentSettingsDisplay == 1) {
    lcd.setCursor(13, 1);
    lcd.print(matrixShine);
    lcd.setCursor(14, 1);
    lcd.print("/5");
  } else if (currentSettingsDisplay == 2) {
    lcd.setCursor(12, 1);
    lcd.print(soundSetting);
  }

  //display the image we want to see
  lcd.setCursor(4, 0);
  lcd.print("Settings");
  lcd.setCursor(0, 1);
  lcd.print(settingsMenuDisplay[currentSettingsDisplay]);

  //move left
  if (xValue < minThreshold && joyMoved == false) {
    if (currentSettingsDisplay < settingsDisplayNumber - 1) {
      currentSettingsDisplay++;
    }
    if (sound) {
      tone(buzzerPin, 3000, 5);
    }
    clearScreen();
    joyMoved = true;
  }

  //move right
  if (xValue > maxThreshold && joyMoved == false) {
    if (currentSettingsDisplay > 0) {
      currentSettingsDisplay--;
    }
    if (sound) {
      tone(buzzerPin, 3000, 5);
    }
    clearScreen();
    joyMoved = true;
  }

  //reset joystick
  if (xValue >= minThreshold && xValue <= maxThreshold) {
    joyMoved = false;
  }

  modifyBrightnessAndSound();
  readMenuButton();
}

void modifyBrightnessAndSound() {
  yValue = analogRead(pinY);

  //move up
  if (yValue < minThreshold && brightnessJoyMoved == false) {
    if (currentSettingsDisplay == 0) {
      if (lcdShine < 5) {
        lcdShine++;
      }
    } else if (currentSettingsDisplay == 1) {
      if (matrixShine < 5) {
        matrixShine++;
      }
    } else if (currentSettingsDisplay == 2) {
      soundSetting = "on";
      sound = true;
    }

    if (sound) {
      tone(buzzerPin, 3000, 5);
    }
    clearScreen();
    brightnessJoyMoved = true;
  }

  //move down
  if (yValue > maxThreshold && brightnessJoyMoved == false) {
    if (currentSettingsDisplay == 0) {
      if (lcdShine > 0) {
        lcdShine--;
      }
    } else if (currentSettingsDisplay == 1) {
      if (matrixShine > 0) {
        matrixShine--;
      }
    } else if (currentSettingsDisplay == 2) {
      soundSetting = "off";
      sound = false;
    }

    if (sound) {
      tone(buzzerPin, 3000, 5);
    }
    clearScreen();
    brightnessJoyMoved = true;
  }

  if (yValue >= minThreshold && yValue <= maxThreshold) {
    brightnessJoyMoved = false;
  }
}

void howToPlayMenu() {
  lcd.setCursor(2, 0);
  lcd.print("How to play");
  scrollingMessage(howToPlayText, howToPlayTextLineNumber);
  readMenuButton();
}

void aboutMenu() {
  lcd.setCursor(5, 0);
  lcd.print("About");
  scrollingMessage(aboutText, aboutTextLineNumber);
  readMenuButton();
}

void resetScoreMenu() {
  yValue = analogRead(pinY);

  lcd.setCursor(5, 0);
  lcd.print("Reset");
  lcd.setCursor(5, 1);
  lcd.print("Cancel");

  //print the arrow
  if (resetScore) {
    lcd.setCursor(4, 0);
    lcd.print(">");
  } else {
    lcd.setCursor(4, 1);
    lcd.print(">");
  }

  //move up
  if (yValue < minThreshold && joyMoved == false) {
    if (sound) {
      tone(buzzerPin, 3000, 5);
    }
    clearScreen();
    resetScore = true;
    joyMoved = true;
  }

  //move down
  if (yValue > maxThreshold && joyMoved == false) {
    if (sound) {
      tone(buzzerPin, 3000, 5);
    }
    clearScreen();
    resetScore = false;
    joyMoved = true;
  }

  if (yValue >= minThreshold && yValue <= maxThreshold) {
    joyMoved = false;
  }

  readMenuButton();
}

void highscoreMenu() {
  xValue = analogRead(pinX);

  //for the arrows
  if (currentRankDisplay == 0) {
    lcd.setCursor(15, 0);
    lcd.print(">");
  } else if (currentRankDisplay == rankDisplayNumber - 1) {
    lcd.setCursor(0, 0);
    lcd.print("<");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("<");
    lcd.setCursor(15, 0);
    lcd.print(">");
  }

  //display the image we want to see
  lcd.setCursor(3, 0);
  lcd.print("Highscore");
  lcd.setCursor(0, 1);
  lcd.print(rankDisplay[currentRankDisplay]);
  lcd.setCursor(5, 1);
  lcd.print(playerNameDisplay[currentRankDisplay]);
  lcd.setCursor(12, 1);
  lcd.print(":");
  lcd.setCursor(14, 1);
  lcd.print(playerScoreDisplay[currentRankDisplay]);

  //move left
  if (xValue < minThreshold && joyMoved == false) {
    if (currentRankDisplay < rankDisplayNumber - 1) {
      currentRankDisplay++;
    }
    if (sound) {
      tone(buzzerPin, 3000, 5);
    }
    clearScreen();
    joyMoved = true;
  }

  //move right
  if (xValue > maxThreshold && joyMoved == false) {
    if (currentRankDisplay > 0) {
      currentRankDisplay--;
    }
    if (sound) {
      tone(buzzerPin, 3000, 5);
    }
    clearScreen();
    joyMoved = true;
  }

  //reset joystick
  if (xValue >= minThreshold && xValue <= maxThreshold) {
    joyMoved = false;
  }

  modifyBrightnessAndSound();
  readMenuButton();
}

void displayAnimation() {
  if (menuCursor == 1) {
    printByte(startGame);
  } else if (menuCursor == 2) {
    printByte(highscore);
  } else if (menuCursor == 3) {
    printByte(settings);
  } else if (menuCursor == 4) {
    printByte(about);
  } else if (menuCursor == 5) {
    printByte(howToPlay);
  } else {
    printByte(resetHighscore);
  }
}

void clearScreen() {
  lcd.setCursor(0, 0);
  lcd.print(clearLcd);
  lcd.setCursor(0, 1);
  lcd.print(clearLcd);
}

void readIntroductionButton() {
  currentMillis = millis();

  if (currentMillis - previousButtonMillis > intervalButton) {
    buttonValue = digitalRead(pinSW);
    buttonValue = !buttonValue;
    if (buttonValue == HIGH) {
      if (sound) {
        tone(buzzerPin, 1000, 5);
      }
      introduction = false;
      menu = true;
      lc.clearDisplay(0);
      clearScreen();
    }
    previousButtonMillis = currentMillis;
  }
}

void readMenuButton() {
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
      if (sound) {
        tone(buzzerPin, 3000, 20);
      }

      if (menuCursor == 1) {
        if (enterUserNameDisplay) {
          //obtain the new player name
          for (int i = 0; i < playerNameLetterNumber; i++) {
            newPlayer.concat(alphabet[enterNameLetters[i]]);
          }

          //update highscore if necessary
          if (newScore > playerScoreDisplay[0]) {
            playerScoreDisplay[0] = newScore;
            playerNameDisplay[0] = newPlayer;
          } else if (newScore > playerScoreDisplay[1]) {
            playerScoreDisplay[1] = newScore;
            playerNameDisplay[1] = newPlayer;
          } else if (newScore > playerScoreDisplay[2]) {
            playerScoreDisplay[2] = newScore;
            playerNameDisplay[2] = newPlayer;
          } else if (newScore > playerScoreDisplay[1]) {
            playerScoreDisplay[3] = newScore;
            playerNameDisplay[3] = newPlayer;
          } else if (newScore > playerScoreDisplay[1]) {
            playerScoreDisplay[4] = newScore;
            playerNameDisplay[4] = newPlayer;
          }

          //reset newPlayer and input name
          for (int i = 0; i < playerNameLetterNumber; i++) {
            enterNameLetters[i] = 0;
          }
          newPlayer = emptyString;
          newScore = 0;

          enterUserNameDisplay = false;
          enterLevelDisplay = true;
          clearScreen();
        }
      }

      buttonStateLongPress = true;
    }

    if (buttonValue == LOW && buttonStatePrevious == HIGH) {
      buttonStatePrevious = LOW;
      buttonStateLongPress = false;

      //for the short pressing button
      if (!buttonStateLongPress && buttonPressDuration < minButtonLongPressDuration) {
        if (sound) {
          tone(buzzerPin, 1000, 5);
        }
        if (menuCursor == 1) {
          if (startGameDisplay == false) {
            menu = false;
            startGameDisplay = true;
            clearScreen();
          } else if (enterUserNameDisplay == false && startGameDisplay) {
            menu = true;
            startGameDisplay = false;
            enterUserNameDisplay = true;
            enterLevelDisplay = false;
            clearScreen();
          }
        }
        if (menuCursor == 2) {
          if (highscoreDisplay == false) {
            menu = false;
            highscoreDisplay = true;
            clearScreen();
          } else {
            menu = true;
            highscoreDisplay = false;
            clearScreen();
          }
        }
        if (menuCursor == 3) {
          if (settingsDisplay == false) {
            menu = false;
            settingsDisplay = true;
            clearScreen();
          } else {
            menu = true;
            settingsDisplay = false;
            clearScreen();
          }
        }
        if (menuCursor == 4) {
          if (aboutDisplay == false) {
            menu = false;
            aboutDisplay = true;
            scrollingTextCursor = defaultTextCursor;
            clearScreen();
          } else {
            menu = true;
            aboutDisplay = false;
            clearScreen();
          }
        }
        if (menuCursor == 5) {
          if (howToPlayDisplay == false) {
            menu = false;
            howToPlayDisplay = true;
            scrollingTextCursor = defaultTextCursor;
            clearScreen();
          } else {
            menu = true;
            howToPlayDisplay = false;
            clearScreen();
          }
        }
        if (menuCursor == 6) {
          if (resetScoreDisplay == false) {
            menu = false;
            resetScoreDisplay = true;
            clearScreen();
          } else {
            if (resetScore) {
              for (int i = 0; i < rankDisplayNumber; i++) {
                playerScoreDisplay[i] = 0;
              }
            }
            menu = true;
            resetScoreDisplay = false;
            clearScreen();
          }
        }
      }
    }
  }
}

void introSong() {
  // iterate over the notes of the melody.
  // Remember, the array is twice the number of notes (notes + durations)
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
    // calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5;  // increases the duration in half for dotted notes
    }
    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzerPin, melody[thisNote], noteDuration * 0.9);
    // Wait for the specief duration before playing the next note.
    delay(noteDuration);
    // stop the waveform generation before the next note.
    noTone(buzzerPin);
  }
}
