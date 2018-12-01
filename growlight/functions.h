uint16_t getMoisture() {
    digitalWrite(SENSOR_PWR, HIGH);
    delay(400);
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