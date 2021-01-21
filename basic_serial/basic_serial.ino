void printMe() {
    u_int8_t* val = new u_int8_t[3];
    val[0] = 01;
    val[1] = 02;
    val[2] = 03;
    for (int j = 0; j < 3; j++) {
        Serial.println(val[j]);
    }
}
void setup() {}

void loop() {
    printMe();
    delay(5000);
}
