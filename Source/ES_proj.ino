int trigPin = 5;    // TRIG pin
int echoPin = 4;    // ECHO pin
int mortor = 7;
int trigPin2 = 3;
int echoPin2 = 2;

float duration_us, distance_cm;
int distanceTreshold = 0;

long duration, range;

void setup() {
  // begin serial port
  Serial.begin (9600);

  // configure the trigger pin to output mode
  pinMode(trigPin, OUTPUT);
  // configure the echo pin to input mode
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(mortor, OUTPUT);}

void loop() {
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(echoPin, HIGH);

  // calculate the distance
  distance_cm = 0.01723 * duration_us;
  distanceTreshold = 336;
  if ( distance_cm > distanceTreshold-300){
    digitalWrite(mortor, HIGH);
    Serial.println("Motor ON ");
  }
  if ( distance_cm < distanceTreshold-325){
    digitalWrite(mortor, LOW);
    Serial.println("Motor OFF");
  }
  Serial.print("|");
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);  
  digitalWrite(trigPin2, HIGH);  
  delayMicroseconds(10);  
  digitalWrite(trigPin2, LOW);
  duration = pulseIn(echoPin2, HIGH);
  range  = 0.01723 * duration ;
  if (range >= 0){
    if (range > 100){
        Serial.print("Tank is Empty ");
    }
    if ((range >= 30) && (range <= 70)){
        Serial.print("Tank is Medium ");
    }
    if (range <= 30){
        Serial.print("Tank IS Full ");
    }
    Serial.print("|");
    Serial.println();
    delay(500);
  }
}
