const int ACS712_Pin = A1;
const int zeroCurrentValue = 510;
void setup() {
  Serial.begin(9600);
  Serial.println("ACS712 - Basissketch");
}
void loop() {
  int rawValue= analogRead(ACS712_Pin);
  float current = (rawValue - zeroCurrentValue)*5.0/1.023/0.185;
  Serial.print("Strom [mA]: ");
  Serial.println(current);
  delay(2000);        
}
