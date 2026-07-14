const int sensorPin = 34;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int moisture = analogRead(sensorPin);

  Serial.print("Moisture: ");
  Serial.println(moisture);

  delay(1000);
}