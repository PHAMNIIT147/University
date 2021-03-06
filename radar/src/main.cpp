#include <Servo.h>
#include <LiquidCrystal.h>
#include <Wire.h>

Servo myServo;
LiquidCrystal lcd(7, 6, 5, 4, 3, 2); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)

#define TRIGPIN  9
#define ECHOPIN  10
#define MOTEUR  11
#define BUZZER  12
#define LEDPIN1  14
#define LEDPIN2  15
float distanceCm, DistanceSec,duration;

void setup() {
  myServo.attach(MOTEUR); // Attach the servo motor to pin 11
  lcd.begin(16,2); // Initialize the Lcd interface with their Size
  pinMode(TRIGPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(LEDPIN1, OUTPUT);
  pinMode(LEDPIN2, OUTPUT);
  DistanceSec=20;

}

void loop() {
for (int pos = 0; pos <= 180; pos++) { // goes from 0 to 180 degrees
// in steps of 1 degree
  myServo.write(pos); // Servo programming to get to the position (pos)
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH); // send a pulse of 10 microseconds
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);

  duration = pulseIn(ECHOPIN, HIGH);
  distanceCm= duration*0.034/2;
  if (distanceCm <= DistanceSec){
    if(distanceCm <= DistanceSec/2)
  {
    tone(BUZZER, 10); // Send 1KHz sound signal...
    digitalWrite(LEDPIN1, LOW);
    digitalWrite(LEDPIN2, HIGH);
    delay(700);
    noTone(BUZZER); // Stop sound...
    lcd.setCursor(0,0); // Position the cursor at 0.0
    lcd.print("Distance: "); // Print "Distance" to LCD
    lcd.print(distanceCm); // Print the distance to LCD
    lcd.print(" cm "); // Print the unit sur LCD
    delay(10);
    lcd.setCursor(0,1);
    lcd.print("Angle : ");
    lcd.print(pos);
    lcd.print(" deg ");
    delay(2000);
  }
  else{
    digitalWrite(BUZZER, HIGH);
    digitalWrite(LEDPIN2, LOW);
    digitalWrite(LEDPIN1, HIGH);
    delay(100);
    digitalWrite(BUZZER, LOW);
    lcd.setCursor(0,0); // Position the cursor at 0.0
    lcd.print("Distance: "); // Print "Distance" sur LCD
    lcd.print(distanceCm); // Print the distance to LCD
    lcd.print(" cm "); // Print the unit to LCD
    delay(10);
    lcd.setCursor(0,1);
    lcd.print("Angle : ");
    lcd.print(pos);
    lcd.print(" deg ");
    delay(2000);
  }
}
  else{
    digitalWrite(BUZZER, LOW);
    digitalWrite(LEDPIN1, LOW);
    digitalWrite(LEDPIN2, LOW);
  }

  lcd.setCursor(0,0); // Position the cursor at 0.0
  lcd.print("Distance: "); // Print "Distance" sur LCD
  lcd.print(distanceCm); // Print the distance to LCD
  lcd.print(" cm "); // Printe the unit to LCD
  delay(10);
  lcd.setCursor(0,1);
  lcd.print("Angle : ");
  lcd.print(pos);
  lcd.print(" deg ");
  delay(80); // wait 100ms for the servo to find its position
}
for (int pos = 180; pos >= 0; pos--) { //goes from 180 to 0 degree
  myServo.write(pos); //
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);

  duration = pulseIn(ECHOPIN, HIGH);
  distanceCm= duration*0.034/2;
  if (distanceCm <= DistanceSec){
    if(distanceCm <= DistanceSec/2){
      tone(BUZZER, 10); // Send 1KHz sound signal...
      digitalWrite(LEDPIN1, LOW);
      digitalWrite(LEDPIN2, HIGH);
      delay(700);
      noTone(BUZZER); // Stop sound...
      lcd.setCursor(0,0); // Position the cursor at 0,0
      lcd.print("Distance: "); // Print "Distance" to LCD
      lcd.print(distanceCm); // Print the distance to LCD
      lcd.print(" cm "); // Print the unit to LCD
      delay(10);
      lcd.setCursor(0,1);
      lcd.print("Angle : ");
      lcd.print(pos);
      lcd.print(" deg ");
      delay(2000);
    }
    else{
      digitalWrite(BUZZER, HIGH);
      digitalWrite(LEDPIN2, LOW);
      digitalWrite(LEDPIN1, HIGH);
      delay(100);
      digitalWrite(BUZZER, LOW);
      lcd.setCursor(0,0); // Position the cursor at 0,0
      lcd.print("Distance: "); // Print "Distance" to LCD
      lcd.print(distanceCm); // Print the distance to LCD
      lcd.print(" cm "); // Print the unit to LCD
      delay(10);
      lcd.setCursor(0,1);
      lcd.print("Angle : ");
      lcd.print(pos);
      lcd.print(" deg ");
      delay(2000);
    }
  }
  else{
    digitalWrite(BUZZER, LOW);
    digitalWrite(LEDPIN1, LOW);
    digitalWrite(LEDPIN2, LOW);
  }

  lcd.setCursor(0,0); //
  lcd.print("Distance: "); //
  lcd.print(distanceCm); //
  lcd.print(" cm ");
  delay(10);
  lcd.setCursor(0,1);
  lcd.print("Angle : ");
  lcd.print(pos);
  lcd.print(" deg ");
  delay(80);
}
}