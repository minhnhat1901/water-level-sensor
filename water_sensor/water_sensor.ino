// Sensor pins
#define sensorPower 7
#define sensorPin A0
#define greenLED 2
#define yellowLED 3
#define redLED 4
#define HIGH H
#define LOW L

// Value for storing water level
int val = 0;

void setup() {
    // Set D7 as an OUTPUT
    pinMode(sensorPower, OUTPUT);

    pinMode(greenLED, OUTPUT);
    pinMode(yellowLED, OUTPUT);
    pinMode(redLED, OUTPUT);

    // Set to LOW so no power flows through the sensor
    digitalWrite(sensorPower, LOW);
    
    Serial.begin(9600);
}

void loop() {
    //get the reading from the function below and print it
    int level = readSensor();

    Serial.print("Water level: ");
    Serial.println(level);

    if (level < 341) {
        digitalWrite(greenLED, H);
        digitalWrite(yellowLED, L);
        digitalWrite(greenLED, L);
    } else if (level < 682) {
        digitalWrite(greenLED, L);
        digitalWrite(yellowLED, H);
        digitalWrite(redLED, L);
    } else {
        digitalWrite(greenLED, L);
        digitalWrite(yellowLED, H);
        digitalWrite(redLED, H);
    }
    delay(1000);
}

//This is a function used to get the reading
int readSensor() {
    digitalWrite(sensorPower, HIGH);  // Turn the sensor ON
    delay(10);                        // wait 10 milliseconds
    val = analogRead(sensorPin);      // Read the analog value form sensor
    digitalWrite(sensorPower, LOW);   // Turn the sensor OFF
    return val;                       // send current reading
}