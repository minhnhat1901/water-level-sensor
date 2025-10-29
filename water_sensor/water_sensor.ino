// Sensor pins
#define sensorPower 7
#define sensorPin A0
// LED pins
#define greenLED 2
#define redLED 4
// HIGH and LOW abbreviations
#define H HIGH
#define L LOW

// Value for storing water level
int val = 0;
const THRESH = 170;

void setup() {
    // Set D7 as an OUTPUT
    pinMode(sensorPower, OUTPUT);
    
    // Light up LED signal
    pinMode(greenLED, OUTPUT);
    pinMode(redLED, OUTPUT);

    // Set to LOW so no power flows through the sensor
    digitalWrite(sensorPower, L);
    
    Serial.begin(9600);
}

void loop() {
    // Get the reading from the function below and print it
    int level = readSensor();
    
    // Print out the level 
    Serial.print("Water level: ");
    Serial.println(level);
    delay(500);

    // Check if the water level is under the threshold
    if (level < THRESH) {
        digitalWrite(greenLED, H);
        digitalWrite(redLED, L);
        Serial.println("Safety mode");
        delay(200);
    } 
    // Over the threshold then ssend the alert.
    else {
        digitalWrite(greenLED, L);
        digitalWrite(redLED, H);
        Serial.println("HIGH WATER LEVEL!!! Turbine starts RUNNING!");
    }
    Serial.println();
}

//This is a function used to get the reading
int readSensor() {
    digitalWrite(sensorPower, H);  // Turn the sensor ON
    delay(10);                        // wait 10 milliseconds
    val = analogRead(sensorPin);      // Read the analog value form sensor
    digitalWrite(sensorPower, L);   // Turn the sensor OFF
    return val;                       // send current reading
}