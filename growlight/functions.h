uint16_t getMoisture() {
    digitalWrite(SENSOR_PWR, HIGH);
    delay(500);
    uint16_t val;
    uint8_t i;
    val = 0;
    for(i=0; i<10; i++) {
        val += analogRead(SOIL);
    }
    val /= 10;
    digitalWrite(SENSOR_PWR, LOW);
    return val;
}


void redLED(uint8_t intensity){
    analogWrite(RED, intensity);
}


void blueLED(uint8_t intensity){
    analogWrite(BLUE, intensity);
}



void risingLight() {
    float r,b;
    uint8_t minute;
    minute = (h-5)*60 + m;
    r=(maxRed*minute)/180;
    b=(maxBlue*minute)/180;
    analogWrite(RED, r);
    analogWrite(BLUE, b);
    currentRed = r;
    currentBlue = b;
}

void fallingLight() {
    float r,b;
    uint8_t minute;
    minute = (h-18)*60 + m;
    r=maxRed - (maxRed*minute)/180;
    b=maxBlue - (maxBlue*minute)/180;
    analogWrite(RED, r);
    analogWrite(BLUE, b);
    currentRed = r;
    currentBlue = b;
}

