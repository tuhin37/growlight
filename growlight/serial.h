uint8_t header;


void serialEvent() {
    uint8_t value;
    if(!header) {
        header=Serial.read();
        
        // set flags
        // show clock
        if(header=='C'){
            flagClock=1;   // 1 for ON
            Serial.println("Clock display is ON");
            header = 0;
        }

        else if(header=='c'){
            flagClock=0;   // 0 for OFF
            Serial.println("Clock display is off");
            header = 0;
        }
        

        // Set clock Values
        else if(header=='h'){
            Serial.print("Enter hour value (0-23): ");
        }

        else if(header=='m'){
            Serial.print("Enter minute value (0-59): ");
        }

        else if(header=='s'){
            Serial.print("Enter second value (0-59): ");
        }


        // set maximum red intensity
        else if(header=='R'){
            Serial.print("Enter maximum intensity of red (0-255): ");
        }

        // set maximum blue intensity
        else if(header=='B'){
            Serial.print("Enter maximum intensity of blue (0-255): ");
        }


        else if(header=='r'){
            Serial.print("Turning on red light. Please specify an intensity (0-255): ");
        }

        else if(header=='b'){
            Serial.print("Turning on blue light. Please specify an intensity (0-255): ");
        }

        // get the current red and blue Values
        else if(header=='q'){
            Serial.println();
            Serial.println();
            Serial.println("******************** STATUS ********************");
            Serial.print("Current timestamp: ");
            Serial.print(h);
            Serial.print(":");
            Serial.print(m);
            Serial.print(":");
            Serial.println(s);
            
            Serial.print("Max RED intencity set to: ");
            Serial.println(maxRed);
            
            Serial.print("Max BLUE intencity set to: ");
            Serial.println(maxBlue);

            Serial.print("Current RED intencity: ");
            Serial.println(currentRed);
            
            Serial.print("Current BLUE intencity: ");
            Serial.println(currentBlue);

            Serial.print("Light curve: ");
            if(lightCurve==RISE) {
                Serial.print("RISING");
            }
            else if(lightCurve==FALL) {
                Serial.print("FALLING");
            }
            else if(lightCurve==MAX){
                Serial.print("MAX");
            }
            else if(lightCurve==OFF){
                Serial.print("OFF");
            } 

            Serial.println();
            Serial.println();
            header=0;
        }
        
        // get soil data
        else if(header=='S'){
            Serial.print("Current Soil moisture is : ");
            Serial.println(getMoisture());
            header=0;
        }








        // help menu
        else if(header=='v'){
            Serial.println();
            Serial.println();
            Serial.println();
            Serial.println();
            Serial.println("*************  Welcome to console Healp *************");
            Serial.println("C  :  Display clock");
            Serial.println("c  :  Hide clock");
            Serial.println("h  :  Set hour value");
            Serial.println("m  :  Set minute value");
            Serial.println("s  :  Set second value");
            Serial.println("R  :  Set maximum intensity for RED");
            Serial.println("B  :  Set maximum intensity for BLUE");
            Serial.println("r  :  Set the current red value");
            Serial.println("b  :  Set the current blue value");
            Serial.println("q  :  Query the current red and blue values");
            Serial.println("S  :  Query the current soil moisture values");
            Serial.println();
            Serial.println();
            Serial.println();
            Serial.println();
            header=0;
        } 
        
    }

    else {
        value=Serial.parseInt();
        if(header=='h'){
            h=value;
            Serial.println(value);
            Serial.print("Hour is set to ");
            Serial.println(value);
        }

        else if(header=='m'){
            m=value;
            Serial.println(value);
            Serial.print("Minute is set to ");
            Serial.println(value);
        }

        else if(header=='s'){
            s=value;
            Serial.println(value);
            Serial.print("second is set to ");
            Serial.println(value);
        }

        // set maximum intensities for red and blue 
        else if(header=='R'){
            maxRed=value;
            Serial.println(value);
            Serial.print("Maximum red intensity is set to ");
            Serial.println(value);
        }

        else if(header=='B'){
            maxBlue=value;
            Serial.println(value);
            Serial.print("Maximum blue intensity is set to ");
            Serial.println(value);
        }
        

        // Manually turn on red and blue leds
        else if(header=='r'){
            Serial.println(value);
            redLED(value);
        }

        else if(header=='b'){
            Serial.println(value);
            blueLED(value);
        }
        header=0;
    }
}