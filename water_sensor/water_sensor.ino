// Sensor pins
#define sensorPower 7
#define sensorPin A0
#define greenLED 2
#define yellowLED 3
#define redLED 4
//#define H HIGH
//#define L LOW

// Value for storing water level
int val = 0;
//const int greenLED = 2;
//const int yellowLED = 3;
//const int redLED 4;

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

    if (level < 48) {
        digitalWrite(greenLED, HIGH);
        digitalWrite(yellowLED, LOW);
        digitalWrite(redLED, LOW);
    } else if (level < 96) {
        digitalWrite(greenLED, LOW);
        digitalWrite(yellowLED, HIGH);
        digitalWrite(redLED, LOW);
    } else {
        digitalWrite(greenLED, LOW);
        digitalWrite(yellowLED, LOW);
        digitalWrite(redLED, HIGH);
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
