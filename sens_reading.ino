#include <NewPing.h>

#define TRIG_PIN 2  // Define the trigger pin
#define ECHO_PIN 3  // Define the echo pin
#define MAX_DISTANCE 200  // Define maximum detection distance (adjust as needed)

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);  // Initialize serial communication at 9600 baud
}

void loop() {
  delay(500);  // Delay between readings (adjust as needed)

  // Trigger the sensor to send a pulse and measure the time for the echo
  unsigned int distance = sonar.ping_cm();

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}
