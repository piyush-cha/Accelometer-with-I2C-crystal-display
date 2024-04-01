#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Address 0x27, 16 columns, 2 rows

int Xread;
int Xrest;

int Yread;
int Yrest;

int Zread;
int Zrest;

double Gx;
double Gy;
double Gz;

int xpin = A0;  // Using A0, A1, A2 as analog pins
int ypin = A1;
int zpin = A2;

int t1;

void setup() {
  Serial.begin(9600);
  lcd.init();  // Initialize the LCD
  lcd.backlight();  // Turn on backlight
  digitalWrite(13, HIGH);
  delay(1000);
  Xrest = analogRead(xpin);
  Serial.print(Xrest);
  Yrest = analogRead(ypin);
  Serial.print(Yrest);
  Zrest = analogRead(zpin);
  Serial.print(Zrest);
  digitalWrite(13, LOW);
}

void loop() {
  Serial.print("Time ");
  t1 = millis();
  Serial.println(t1 * 0.001);

  Xread = analogRead(xpin) - Xrest;
  Yread = analogRead(ypin) - Yrest;
  Zread = analogRead(zpin) - Zrest;

  Gx = Xread / 67.584;
  Gy = Yread / 67.584;
  Gz = Zread / 67.584;

  Serial.print("Acceleration X :");
  Serial.print(Gx);
  Serial.print("Acceleration Y :");
  Serial.print(Gy);
  Serial.print("Acceleration Z :");
  Serial.print(Gz);
  Serial.print("\n");

  lcd.setCursor(0, 0);
  lcd.print("gx:");
  lcd.print(Gx);
  lcd.setCursor(8, 0);
  lcd.print("gy:");
  lcd.print(Gy);
  lcd.setCursor(0, 1);
  lcd.print("gz:");
  lcd.print(Gz);
  delay(1000);
  lcd.clear();
}