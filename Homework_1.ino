//voltage defined by the maximum led brightness divided by maximum analog value
float voltage = 255./1023.;

//output pins for the leds
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

//entry pins for the potentiometers
int potPin_red = A0;
int potPin_green = A1;
int potPin_blue = A2;

//the value of the potentiometer which has to be applied on the leds
int readValue_red;
int readValue_green;
int readValue_blue;

//the value to be sent to the leds
int writeValue_red;
int writeValue_green;
int writeValue_blue;

void setup() {
  pinMode(potPin_red, INPUT);
  pinMode(potPin_green, INPUT);
  pinMode(potPin_blue, INPUT);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
    readValue_red = analogRead(potPin_red);
    readValue_green = analogRead(potPin_green);
    readValue_blue = analogRead(potPin_blue);

    writeValue_red = voltage*readValue_red;
    writeValue_green = voltage*readValue_green;
    writeValue_blue = voltage*readValue_blue;

    analogWrite(redPin, writeValue_red);
    analogWrite(greenPin, writeValue_green);
    analogWrite(bluePin, writeValue_blue);
}
