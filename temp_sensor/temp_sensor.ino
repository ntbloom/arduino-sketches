void setup() { Serial.begin(9600); }

float get_temp() {
  int reading = analogRead(A1);
  return reading;
}

void loop() {
  int temp = get_temp();
  Serial.println(temp);
  delay(1);
}
