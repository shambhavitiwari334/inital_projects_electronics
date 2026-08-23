const int trigPin = 9;
const int echoPin = 10;

const int ledPin = 7;
const int buzzerPin = 6;

const int dangerThreshold = 10;
const int cautionThreshold = 20;

const int SAFE = 0;
const int CAUTION = 1;
const int DANGER = 2;

int currentState = SAFE;
int previousState = SAFE;

unsigned long previousMillis = 0;
bool buzzerState = false;


void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
}


void loop() {

  // -------------------------
  // 1. Trigger sensor
  // -------------------------

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);


  // -------------------------
  // 2. Measure echo
  // -------------------------

  long duration = pulseIn(echoPin, HIGH, 30000);


  // -------------------------
  // 3. Handle sensor timeout
  // -------------------------

  if (duration == 0) {

    Serial.println("Sensor timeout!");

    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);

    return;
  }


  // -------------------------
  // 4. Calculate distance
  // -------------------------

  float distance = duration * 0.034 / 2;


  // -------------------------
  // 5. Determine state
  // -------------------------

  if (distance > cautionThreshold) {
    currentState = SAFE;
  }

  else if (distance >= dangerThreshold) {
    currentState = CAUTION;
  }

  else {
    currentState = DANGER;
  }


  // -------------------------
  // 6. Detect state change
  // -------------------------

  if (currentState != previousState) {

    previousMillis = millis();

    buzzerState = false;

    noTone(buzzerPin);

    previousState = currentState;
  }


  unsigned long currentMillis = millis();


  // -------------------------
  // 7. SAFE
  // -------------------------

  if (currentState == SAFE) {

    digitalWrite(ledPin, LOW);

    noTone(buzzerPin);

    buzzerState = false;
  }


  // -------------------------
  // 8. CAUTION
  // -------------------------

  else if (currentState == CAUTION) {

    digitalWrite(ledPin, HIGH);

    if (currentMillis - previousMillis >= 500) {

      previousMillis = currentMillis;

      buzzerState = !buzzerState;

      if (buzzerState) {
        tone(buzzerPin, 1000);
      }

      else {
        noTone(buzzerPin);
      }
    }
  }


  // -------------------------
  // 9. DANGER
  // -------------------------

  else if (currentState == DANGER) {

    digitalWrite(ledPin, HIGH);

    if (currentMillis - previousMillis >= 150) {

      previousMillis = currentMillis;

      buzzerState = !buzzerState;

      if (buzzerState) {
        tone(buzzerPin, 2000);
      }

      else {
        noTone(buzzerPin);
      }
    }
  }


  // -------------------------
  // 10. Serial output
  // -------------------------

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm | ");

  if (currentState == SAFE) {
    Serial.println("SAFE");
  }

  else if (currentState == CAUTION) {
    Serial.println("CAUTION");
  }

  else {
    Serial.println("DANGER");
  }

  delay(50);
}