const int trigPin = 2;
const int echoPin = 3;
int distance;
long duration;

#define ENA_PIN 11
#define ENB_PIN 10
#define MOTOR_LEFT_PIN1 7
#define MOTOR_LEFT_PIN2 6
#define MOTOR_RIGHT_PIN1 5
#define MOTOR_RIGHT_PIN2 4

void setup() 
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Set motor control pins as outputs
  pinMode(ENA_PIN, OUTPUT);
  pinMode(ENB_PIN, OUTPUT);
  pinMode(MOTOR_LEFT_PIN1, OUTPUT);
  pinMode(MOTOR_LEFT_PIN2, OUTPUT);
  pinMode(MOTOR_RIGHT_PIN1, OUTPUT);
  pinMode(MOTOR_RIGHT_PIN2, OUTPUT);
}

void moveForward() {
  // Set motor directions for forward motion
  digitalWrite(MOTOR_LEFT_PIN1, HIGH);
  digitalWrite(MOTOR_LEFT_PIN2, LOW);
  digitalWrite(MOTOR_RIGHT_PIN1, HIGH);
  digitalWrite(MOTOR_RIGHT_PIN2, LOW);

  analogWrite(ENA_PIN, 185); // Full speed for left motor
  analogWrite(ENB_PIN, 185); // Full speed for right motor
  Serial.println("Moving Forward");
}

void moveBackward() {
  // Set motor directions for backward motion
  digitalWrite(MOTOR_LEFT_PIN1, LOW);
  digitalWrite(MOTOR_LEFT_PIN2, HIGH);
  digitalWrite(MOTOR_RIGHT_PIN1, LOW);
  digitalWrite(MOTOR_RIGHT_PIN2, HIGH);

  analogWrite(ENA_PIN, 185); // Full speed for left motor
  analogWrite(ENB_PIN, 185); // Full speed for right motor
  Serial.println("Moving Backward");
}

void turnLeft() {
  // Set motor directions for left turn
  digitalWrite(MOTOR_LEFT_PIN1, LOW);
  digitalWrite(MOTOR_LEFT_PIN2, HIGH);
  digitalWrite(MOTOR_RIGHT_PIN1, HIGH);
  digitalWrite(MOTOR_RIGHT_PIN2, LOW);

  // Set motor speeds
  analogWrite(ENA_PIN, 150); // Reduce speed for left motor
  analogWrite(ENB_PIN, 155); // Full speed for right motor
  Serial.println("Turning Left");
}

void Stop(){
  // Set motor speeds to zero
  analogWrite(ENA_PIN, 0);
  analogWrite(ENB_PIN, 0);
  Serial.println("Stopped");
}

void loop() 
{
  digitalWrite(trigPin, LOW); // Clear the trigPin by setting it LOW
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); // Trigger the sensor by setting the trigPin HIGH for 10 microseconds
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Calculate the distance in centimeters

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(60); // Wait for next measurement

  if(distance >= 15){
    moveForward();
  }else{
    Stop();
    delay(250);
    moveBackward();
    delay(2500);
    turnLeft();
    delay(2000);
  }
}
}
