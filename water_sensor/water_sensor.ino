// Sensor pins
#define sensorPower 7
#define sensorPin A0
#define greenLED 2
#define redLED 4
#define H HIGH
#define L LOW

// Value for storing water level
int val = 0;

void setup() {
    // Set D7 as an OUTPUT
    pinMode(sensorPower, OUTPUT);

    pinMode(greenLED, OUTPUT);
    pinMode(redLED, OUTPUT);

    // Set to LOW so no power flows through the sensor
    digitalWrite(sensorPower, L);
    
    Serial.begin(9600);
}

void loop() {
    //get the reading from the function below and print it
    int level = readSensor();

    Serial.print("Water level: ");
    Serial.println(level);

    if (level < 170) {
        digitalWrite(greenLED, H);
        digitalWrite(redLED, L);
    } else {
        digitalWrite(greenLED, L);
        digitalWrite(redLED, H);
    }
    delay(500);
}

//This is a function used to get the reading
int readSensor() {
    digitalWrite(sensorPower, H);  // Turn the sensor ON
    delay(10);                        // wait 10 milliseconds
    val = analogRead(sensorPin);      // Read the analog value form sensor
    digitalWrite(sensorPower, L);   // Turn the sensor OFF
    return val;                       // send current reading
}
