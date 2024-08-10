  #include <NewPing.h>

  int MOTOR_A1 = 6; // MOTOR_A1 connected to Digital pin D6
  int MOTOR_A2 = 5; // MOTOR_A2 connected to Digital pin D5
  int MOTOR_B1 = 4; // MOTOR_B1 connected to Digital pin D4
  int MOTOR_B2 = 3; // MOTOR_B2 connected to Digital pin D3

  #define TRIG A3 // TRIG PIN connected to Analog pin A3
  #define ECHO A2 // ECHO PIN connected to Analog pin A2
  #define MAX_DISTANCE 100 // Define Maximum Distance

  NewPing sonar(TRIG, ECHO, MAX_DISTANCE);

  void setup() {
    pinMode(MOTOR_A1, OUTPUT); // initialize MOTOR_A1 pin as an output
    pinMode(MOTOR_A2, OUTPUT); // initialize MOTOR_A2 pin as an output
    pinMode(MOTOR_B1, OUTPUT); // initialize MOTOR_B1 pin as an output
    pinMode(MOTOR_B2, OUTPUT); // initialize MOTOR_B2 pin as an output
    
    Serial.begin(9600); // Initialize serial communication
  }

  void loop() {
    delay(70);
    int distance = sonar.ping_cm();
    
    if (distance == 0) {
      distance = 30; // Set a default distance in case of an error
    }
    
    Serial.print("Distance: "); // Print the distance label
    Serial.print(distance); // Print the measured distance in centimeters
    Serial.println(" cm"); // Print a newline for formatting
    
    if (distance <= 5) { // Change the distance threshold to 5 cm
      Stop();
      delay(100);
      turnRight();
      delay(350);
      moveForward();
      delay(500);
      turnLeft();
      delay(350);
      moveForward();
      delay(700);
      turnLeft();
      delay(300);
      moveForward();
      delay(400);
      turnRight();
      delay(400);
    }
  }

  void Stop() {
    digitalWrite(MOTOR_A1, LOW);
    digitalWrite(MOTOR_A2, LOW);
    digitalWrite(MOTOR_B1, LOW);
    digitalWrite(MOTOR_B2, LOW);
  }

  void turnRight() {
    digitalWrite(MOTOR_A1, LOW);
    digitalWrite(MOTOR_A2, HIGH);
    digitalWrite(MOTOR_B1, LOW);
    digitalWrite(MOTOR_B2, HIGH);
  }

  void turnLeft() {
    digitalWrite(MOTOR_A1, HIGH);
    digitalWrite(MOTOR_A2, LOW);
    digitalWrite(MOTOR_B1, HIGH);
    digitalWrite(MOTOR_B2, LOW);
  }

  void moveForward() {
    digitalWrite(MOTOR_A1, LOW);
    digitalWrite(MOTOR_A2, HIGH);
    digitalWrite(MOTOR_B1, HIGH);
    digitalWrite(MOTOR_B2, LOW);
  }
