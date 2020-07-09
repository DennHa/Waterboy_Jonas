
/*
____    __    ____  ___   .___________. _______ .______         .______     ______   ____    ____ 
\   \  /  \  /   / /   \  |           ||   ____||   _  \        |   _  \   /  __  \  \   \  /   / 
 \   \/    \/   / /  ^  \ `---|  |----`|  |__   |  |_)  |       |  |_)  | |  |  |  |  \   \/   /  
  \            / /  /_\  \    |  |     |   __|  |      /        |   _  <  |  |  |  |   \_    _/   
   \    /\    / /  _____  \   |  |     |  |____ |  |\  \----.   |  |_)  | |  `--'  |     |  |     
    \__/  \__/ /__/     \__\  |__|     |_______|| _| `._____|   |______/   \______/      |__|     
                                                                                                 
*/

// define pins
#define moistPin A0
#define relaisPin D4


//define when pump needs to water the plant
int moistLimes = 400;
int cMoisterLevel = 0;

//define how long the pump should be activated in ms
int pumping = 1000;

// Using millis to time actions in loop
unsigned long currentMillis;  
const unsigned long period = 1000;  //the value is a number of milliseconds 
long previousMillis = 0;        // will store last time LED was updated


void setup(){
    Serial.begin(9600); //start serial communication
    Serial.println("Water Boy initalization ....");
    Serial.print("Your water boy will start to water the plants as soon as it is under: ");
    Serial.println(moistLimes);

    //define pins

    pinMode(relaisPin, OUTPUT);

    //Pin D4 High is off!
    digitalWrite(relaisPin, HIGH);
    
}

void loop(){
    currentMillis = millis();
    if(currentMillis - previousMillis > period) {
        previousMillis = currentMillis;  // save the last time you did the action
        
        cMoisterLevel = analogRead(moistPin); //the lower the more moist the plant is 

        //check if the moisture limes is reached
        Serial.println("----------");
        Serial.print("The current moisture level is: ");
        Serial.println(cMoisterLevel);
        Serial.println("----------");

        if(cMoisterLevel >= moistLimes){ 
            digitalWrite(relaisPin, LOW);
            delay(pumping);
            digitalWrite(relaisPin, HIGH);
        }

    }


}