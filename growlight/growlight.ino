#include "TimerOne.h"
#include "config.h"
#include "globals.h"
#include "functions.h"
#include "serial.h"




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
    //analogWrite(RED, 200);
    //analogWrite(BLUE, 100);
}





void oneSecCallback() {
    s++;
    if(s==60) {
        s=0;
        m++;

        //rising light lightCurve
        if(lightCurve==RISE) {
            risingLight();           
        }
        else if(lightCurve==FALL) {
            fallingLight();
        }
        else if(lightCurve==MAX) {
            analogWrite(RED, maxRed);
            analogWrite(BLUE, maxBlue);
            currentRed = maxRed;
            currentBlue = maxBlue;
        }
        else if(lightCurve==OFF) {
            analogWrite(RED, 0);
            analogWrite(BLUE, 0);
            currentRed = 0;
            currentBlue = 0;
        }

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
    if(flagClock) {
        Serial.print(h);
        Serial.print(":");
        Serial.print(m);
        Serial.print(":");
        Serial.print(s);
        Serial.print("  ");
        
        Serial.print("Red:(");
        Serial.print(currentRed);
        Serial.print("/");
        Serial.print(maxRed);
        Serial.print(")  ");

        Serial.print("Blue:(");
        Serial.print(currentBlue);
        Serial.print("/");
        Serial.print(maxBlue);
        Serial.print(")  ");

        if(lightCurve==RISE) {
            Serial.println("RISING");
        }
        else if(lightCurve==FALL) {
            Serial.println("FALLING");
        }
        else if(lightCurve==MAX){
            Serial.println("MAX");
        }
        else if(lightCurve==OFF){
            Serial.println("OFF");
        } 
    }

    // set the leds in rising mode 
    if(h>=5 && h<8) {
        lightCurve = RISE;
    }
    // set the leds in MAX mode
    else if(h>=8 && h<18) {
        lightCurve = MAX;
    }
    // set the leds in falling mode
    else if(h>=18 && h<21) {
        lightCurve = FALL;
    }
    // set the leds in OFF mode
    else if(h>=21 || h<5) {
        lightCurve = OFF;
    }


}



        