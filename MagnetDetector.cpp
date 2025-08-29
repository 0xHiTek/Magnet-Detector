// Week 10: Magnet Detector (Hall/Reed Switch)
// Author: 0xHitek

#define SENSOR_PIN 2
#define LED_PIN 8
#define BUZZER_PIN 9   // optional

void setup() {
  pinMode(SENSOR_PIN, INPUT_PULLUP);  // works for reed or hall sensor (digital)
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
  Serial.begin(9600);
}

void loop() {
  int sensorVal = digitalRead(SENSOR_PIN);

  if (sensorVal == LOW) {   // magnet detected
    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 1000);
    Serial.println("Magnet detected! 🔑");
  } else {
    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);
    Serial.println("No magnet nearby.");
  }

  delay(100);
}
