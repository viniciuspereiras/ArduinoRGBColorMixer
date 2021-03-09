#include <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int potRed = 0;
int potGreen = 0;
int potBlue = 0;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(6, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Cores RGB");
  delay(500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("RED");
  lcd.setCursor(5, 0);
  lcd.print("GREEN");
  lcd.setCursor(12, 0);
  lcd.print("BLUE");
  Serial.begin(9600);
}

void loop() {
  potRed = analogRead(A0);
  potRed = map(potRed, 0, 1023, 0, 255);
  lcd.setCursor(0, 1);
  lcd.print(potRed);
  analogWrite(6, potRed);
  if (potRed < 100){
  lcd.setCursor(2, 1);
  lcd.write(B00100000);
  }
  potGreen = analogRead(A1);
  potGreen = map(potGreen, 0, 1023, 0, 255);
  lcd.setCursor(6, 1);
  lcd.print(potGreen);
  analogWrite(9, potGreen);
  if (potGreen < 100){
  lcd.setCursor(8, 1);
  lcd.write(B00100000);
  }
  potBlue = analogRead(A2);
  potBlue = map(potBlue, 0, 1023, 0, 255);
  lcd.setCursor(12, 1);
  lcd.print(potBlue);
  analogWrite(10, potBlue);
  if (potBlue < 100){
  lcd.setCursor(14, 1);
  lcd.write(B00100000);
  }
  if (potRed < 10){
  lcd.setCursor(1, 1);
  lcd.write(B00100000);
  }
 
  if (potGreen < 10){
  lcd.setCursor(7, 1);
  lcd.write(B00100000);
  }
 
  if (potBlue < 10){
  lcd.setCursor(14, 1);
  lcd.write(B00100000);
  }
}
