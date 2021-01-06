void setup() { Serial.begin(9600); }

float get_temp() {
  int reading = analogRead(A1);
  float voltage = reading * 3.3;
  voltage /= 1024;
  float temp_c = (voltage - 0.5) * 100;  // 10mv per degree with 500 mV offset
  float temp_f = (voltage * 9 / 5) + 32;
  return temp_f;
}

void loop() {
  float temp = get_temp();
  Serial.println(temp);
  delay(1);
}
