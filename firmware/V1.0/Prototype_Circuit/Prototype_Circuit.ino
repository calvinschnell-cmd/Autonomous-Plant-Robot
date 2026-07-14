const int sensorPin = 34;   // Moisture sensor AOUT
const int relayPin = 26;    // Relay IN

const int dryThreshold = 2500;

void setup() {
  Serial.begin(115200);
  pinMode(relayPin, OUTPUT);

  digitalWrite(relayPin, LOW); // Pump OFF
}

void loop() {
  int moisture = analogRead(sensorPin);

  Serial.print("Moisture: ");
  Serial.println(moisture);

  if (moisture > dryThreshold) {
    Serial.println("Dry soil detected. Watering...");

    digitalWrite(relayPin, HIGH); // Pump ON
    delay(5000);                  // Water for 5 sec

    digitalWrite(relayPin, LOW);  // Pump OFF
    Serial.println("Watering done. Waiting for soak.");

    delay(30000);                 // Wait 30 sec before checking again
  } 
  else {
    Serial.println("Soil wet enough. Pump off.");
    digitalWrite(relayPin, LOW);
    delay(5000);
  }
}