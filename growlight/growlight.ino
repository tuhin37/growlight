#include "TimerOne.h"
#include "config.h"
#include "globals.h"
#include "functions.h"



void setup() {
    Serial.begin(9600);
    pinMode(RED, OUTPUT);
    pinMode(BLUE, OUTPUT);
    pinMode(PUMP, OUTPUT);
    pinMode(SENSOR_PWR, OUTPUT);
    
    Timer1.initialize(1000000);         // initialize timer1, and set a 1/2 second period
    Timer1.attachInterrupt(oneSecCallback);  // attaches callback() as a timer overflow interrupt

}

void loop() {
    analogWrite(RED, 200);
    analogWrite(BLUE, 100);
}





void oneSecCallback() {
    s++;
    if(s==60) {
        s=0;
        m++;
    }

    if(m==60) {
        m=0;
        h++;
    }

    if(h==24) {
        h=0;
        m=0;
        s=0;
    }

    // display time`
    // Serial.print(h);
    // Serial.print(":");
    // Serial.print(m);
    // Serial.print(":");
    // Serial.println(s);

    Serial.println(getMoisture());
}
        