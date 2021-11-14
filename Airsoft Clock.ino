#include <Wire.h>
#include <LiquidCrystal_I2C.h>


// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int buzzer = 15;

unsigned long previousTime = 0;
byte seconds ;
byte minutes ;
byte hours ;
unsigned long previousTime2 = 0;
byte seconds2 ;
byte minutes2 ;
byte hours2 ;
int T1 = 0;
int T2 = 0;

void setup()
{
  // initialize the LCD
  lcd.init();
  // Turn on the blacklight and print a message.
  lcd.backlight();
  pinMode(buzzer, OUTPUT); // Set buzzer
  pinMode(12, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  lcd.clear();
}

void timer1()
{
  if (millis() >= (previousTime))
  {
    previousTime = previousTime + 1000;  // use 100000 for uS
    seconds = seconds + 1;
    if (seconds == 60)
    {
      seconds = 0;
      minutes = minutes + 1;
      lcd.clear();
      tone(buzzer, 2000, 200);
    }
    if (minutes == 60)
    {
      minutes = 0;
      hours = hours + 1;
    }
    if (hours == 13)
    {
      hours = 1;
    }
  }
}
void timer2()
{
  if (millis() >= (previousTime2))
  {
    previousTime2 = previousTime2 + 1000;  // use 100000 for uS
    seconds2 = seconds2 + 1;
    if (seconds2 == 60)
    {
      seconds2 = 0;
      minutes2 = minutes2 + 1;
      lcd.clear();
      tone(buzzer, 2000, 200);
    }
    if (minutes2 == 60)
    {
      minutes2 = 0;
      hours2 = hours2 + 1;
    }
    if (hours2 == 13)
    {
      hours2 = 1;
    }
  }
}

void loop() {
  int Trigger1 = digitalRead(12);
  int Trigger2 = digitalRead(14);
  if (Trigger1 != 0) {
    timer1();
  }
  if (Trigger2 != 0) {
    timer2();
  }
  lcd.setCursor(0, 1);
  lcd.print("Red Team: ");
  lcd.print (hours2, DEC);
  lcd.print (":");
  lcd.print (minutes2, DEC);
  lcd.print (":");
  lcd.print(seconds2, DEC);
  lcd.setCursor(0, 0);
  lcd.print("Blue Team: ");
  lcd.print (hours, DEC);
  lcd.print (":");
  lcd.print (minutes, DEC);
  lcd.print (":");
  lcd.print(seconds, DEC);
  delay(1000);
}
