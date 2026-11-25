#include <SoftwareSerial.h>

SoftwareSerial link(2, 3); // RX, TX

const int GREEN = 5;
const int YELLOW = 7;
const int RED = 9;

void setup() {
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);

  Serial.begin(9600);
  link.begin(9600);

  digitalWrite(GREEN, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, LOW);
}

void loop() {
  if (link.available() > 0) {
    char received = link.read();

    if (received == 'R') {
      Serial.println("Pedestrian request received");

      // Cars: Green to yellow
      digitalWrite(GREEN, LOW);
      digitalWrite(YELLOW, HIGH);
      delay(2000);

      // Cars: Yellow to red
      digitalWrite(YELLOW, LOW);
      digitalWrite(RED, HIGH);
      delay(1000);

      // Allow pedestrians to cross
      link.write('G');
      Serial.println("Pedestrian green allowed");

      // Wait until pedestrians finish crossing
      while (true) {
        if (link.available() > 0) {
          if (link.read() == 'D') {
            break;
          }
        }
      }

      delay(1000);

      // Cars: Red and yellow
      digitalWrite(YELLOW, HIGH);
      delay(1000);

      // Cars: Green again
      digitalWrite(RED, LOW);
      digitalWrite(YELLOW, LOW);
      digitalWrite(GREEN, HIGH);

      link.write('A');
      Serial.println("Traffic green again");
    }
  }
}
