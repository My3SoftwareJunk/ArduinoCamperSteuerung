
int offset = 0;
int led = 13;

void setup() {
  
  Serial.begin(9600);

}

void loop() {

  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);

  int volt = analogRead(A0);
  double voltage = map(volt, 0, 1023, 0, 2500) + offset;

   voltage /= 100;
  
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.println("V");

  delay(500);
}
