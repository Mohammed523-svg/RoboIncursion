// Pin assignments for the L298N motor driver
const int motor1EnablePin = 10;  // Enable pin for Motor 1
const int motor1In1 = 9;        // Input 1 for Motor 1
const int motor1In2 = 8;        // Input 2 for Motor 1
const int motor2EnablePin = 5; // Enable pin for Motor 2
const int motor2In3 = 7;       // Input 3 for Motor 2
const int motor2In4 = 6;       // Input 4 for Motor 2
const int motor3EnablePin = 11; // Enable pin for Motor 3
const int motor3In1 = 12;       // Input 1 for Motor 3
const int motor3In2 = 13;       // Input 2 for Motor 3

// Pin assignment for the flame sensor
const int flameSensorPin = A0;  // Change this to the actual pin your flame sensor is connected to

void setup() {
  // Set up motor control pins
  pinMode(motor1EnablePin, OUTPUT);
  pinMode(motor1In1, OUTPUT);
  pinMode(motor1In2, OUTPUT);
  pinMode(motor2EnablePin, OUTPUT);
  pinMode(motor2In3, OUTPUT);
  pinMode(motor2In4, OUTPUT);
  pinMode(motor3EnablePin, OUTPUT);
  pinMode(motor3In1, OUTPUT);
  pinMode(motor3In2, OUTPUT);

  // Start the serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the sensor value
  int sensorValue = analogRead(flameSensorPin);

  // Print the sensor value to the serial monitor
  Serial.print("Flame Sensor Value: ");
  Serial.println(sensorValue);

  // Check if the sensor value falls below 500
  if (sensorValue < 820) {
       // Rotate 360 degrees
    stopRotation();

}else{

    // Rotate 360 degrees
    rotate360Degrees();

  }
}


// Function to rotate the Arduino 360 degrees
void rotate360Degrees() {
  // Set motor directions to rotate the robot
  digitalWrite(motor1In1, HIGH);
  digitalWrite(motor1In2, LOW);
  digitalWrite(motor2In3, LOW);
  digitalWrite(motor2In4, HIGH);

  // Continuously check the sensor value while rotating
  while (analogRead(flameSensorPin) < 870) {
  // Continue rotating until the condition is met
  }

  // Set motor speeds to rotate the robot
  analogWrite(motor1EnablePin, 45);  // Adjust the speed as needed
  analogWrite(motor2EnablePin, 45);

  // Rotate for approximately 2 seconds (adjust as needed)
  delay(2000);

  // Stop the motors
  analogWrite(motor1EnablePin, 0);
  analogWrite(motor2EnablePin, 0);
}

// Function to stop the rotation
void stopRotation() {
  // Stop the motors
  analogWrite(motor1EnablePin, 0);
  analogWrite(motor2EnablePin, 0);
}