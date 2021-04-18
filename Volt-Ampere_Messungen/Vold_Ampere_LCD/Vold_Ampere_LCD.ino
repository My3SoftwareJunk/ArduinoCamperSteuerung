#include <Robojax_AllegroACS_Current_Sensor.h>

#include <LiquidCrystal.h>

LiquidCrystal lcd(7,8,9,10,11,12);
int offset = 0;

const int VIN = A1; // define the Arduino pin A0 as voltage input (V in)
  const float VCC   = 5.00;// supply voltage
  const int MODEL = 2;

  Robojax_AllegroACS_Current_Sensor robojax(MODEL, VIN, VCC);

void setup() {

  lcd.begin(16,2);
  
}

void loop() {

  int volt = analogRead(A0);
  double voltage = map(volt, 0, 1023, 0, 2500) + offset;

   voltage /= 100;

  lcd.setCursor(00,0);
  lcd.print("Voltage: ");
  lcd.setCursor(10,0);
  lcd.print(voltage);
  lcd.setCursor(16,0);
  lcd.print("V");

  lcd.setCursor(0,1);
  lcd.print("Current: ");
  lcd.setCursor(10,1);
  lcd.print(robojax.getCurrent(),3); // print the current with 3 decimal places
  lcd.setCursor(16,1);
  lcd.print("A");
  
  delay(500);



}
