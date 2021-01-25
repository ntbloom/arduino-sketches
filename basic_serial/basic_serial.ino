
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

void setup() { Serial.begin(9600); }

void loop() {
    // printUchar();
    printInts();
    delay(5000);
}
