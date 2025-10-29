# Briefly Explanation
In this project, I designed a simple system that mimics how a water dam sensor works. The idea is to monitor the water level and send an alert when it gets too high.

When the water level reaches a dangerous height, the sensor activates a warning signal to the operator - just like in a real dam, where the operator would start the water turbine to release water and prevent flooding or damage.

# Code explanation
```c++
// Sensor pins
#define sensorPower 7
#define sensorPin A0
// LED pins
#define greenLED 2
#define redLED 4
// HIGH and LOW abbreviations
#define H HIGH
#define L LOW
```
**Explanation:**
- Assigns each pin a name for easy reference.
- `sensorPower` powers the water sensor through pin 7.
- `sensorPin` reads the analog signal (water level).
- `greenLED` and `redLED` show safe or high water levels.
- Defines H and L to shorten HIGH and LOW for cleaner code.

```c++
// Variables
int val = 0;
const THRESH = 170;
```
**Explanation:**
- `val` stores the raw sensor reading.
- `THRESH` is the threshold value that determines when the water level is considered high.
  - If the reading goes above 170 → the water level is too high.

```c++
// This is a function used to get the reading
int readSensor() {
    digitalWrite(sensorPower, H);  // Turn the sensor ON
    delay(10);                        // wait 10 milliseconds
    val = analogRead(sensorPin);      // Read the analog value form sensor
    digitalWrite(sensorPower, L);   // Turn the sensor OFF
    return val;                       // send current reading
}
```
**Explanation:**
- Turns the sensor on only when needed (saves power).
- Waits briefly (10 ms) to stabilize the signal.
- Reads the analog input and returns that value.
- Turns the sensor off after each read to prevent corrosion.

```c++
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
```
**Explanation:**
- Defines pin directions for output signals.
- Keeps sensor initially off (LOW).
- Starts the Serial Monitor for displaying water level readings.

```c++
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
    // Over the threshold then send the alert.
    else {
        digitalWrite(greenLED, L);
        digitalWrite(redLED, H);
        Serial.println("HIGH WATER LEVEL!!! Turbine starts RUNNING!");
    }
    Serial.println();
}
```
**Explanation:**
- Continuously reads the water level.
- Displays the value in the Serial Monitor for real-time - observation.
- Uses an if-else statement to:
- Light green LED when the level is safe.
- Light red LED and send a warning message when the level is too - high.
- The system repeats every 0.5 seconds for monitoring updates.