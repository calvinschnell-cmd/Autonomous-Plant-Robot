#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

int angleToPulse(int angle) {
  return map(angle, 0, 270, 120, 520);
}

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);

  pwm.begin();
  pwm.setPWMFreq(50);
  delay(500);

  Serial.println("Ready. Type: channel angle");
  Serial.println("Example: 0 135");
}

void loop() {
  if (Serial.available()) {
    String line = Serial.readStringUntil('\n');
    line.trim();

    int spaceIndex = line.indexOf(' ');
    if (spaceIndex == -1) {
      Serial.println("Bad format. Use: 0 135");
      return;
    }

    int ch = line.substring(0, spaceIndex).toInt();
    int angle = line.substring(spaceIndex + 1).toInt();

    if (ch < 0 || ch > 15 || angle < 0 || angle > 270) {
      Serial.println("Out of range.");
      return;
    }

    int pulse = angleToPulse(angle);
    pwm.setPWM(ch, 0, pulse);

    Serial.print("Channel ");
    Serial.print(ch);
    Serial.print(" -> ");
    Serial.print(angle);
    Serial.print(" deg, pulse ");
    Serial.println(pulse);
  }
}