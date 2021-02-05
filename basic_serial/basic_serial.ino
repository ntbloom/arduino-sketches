
/* one way to print 0,1,2 to serial */
void printUint8() {
    u_int8_t* val = new u_int8_t[3];
    val[0] = 01;
    val[1] = 02;
    val[2] = 03;
    for (int j = 0; j < 3; j++) {
        Serial.println(val[j]);
    }
}

/* or use unsigned char and bitwise... */
void printUchar() {
    int i = 1;
    unsigned char val[] = {
        i >> 1,  // should be 0
        i,       // should be 1
        i << 1   // should be 2
    };
    for (int i = 0; i < 3; i++) {
        Serial.println(val[i]);
    }
}
int i = 0;
void printInts() { Serial.println(i++); }

void altogetherNow() {
    unsigned long start = micros();
    Serial.begin(9600);
    unsigned char expected[] = {1, 4, 15, 15, 14, 7};
    for (int i = 0; i < 6; i++) {
        Serial.print(expected[i], HEX);
    }
    Serial.println();
    Serial.end();
    unsigned long finish = micros();
    Serial.begin(100);
    Serial.println(finish - start);
    Serial.end();
}

void setup() {
    // Serial.begin(9600);
}

void loop() {
    // printUchar();
    // printInts();
    // altogetherNow();
    Serial.println("Hello, logic analyzer!");
    delay(5000);
}
