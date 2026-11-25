#include <SoftwareSerial.h>

SoftwareSerial link(2, 3); // RX, TX

const int GREEN = 5;
const int RED = 10;
const int BUTTON = 8;

bool requested = false;

void setup() {
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);

  Serial.begin(9600);
  link.begin(9600);

  digitalWrite(GREEN, LOW);
  digitalWrite(RED, HIGH);
}

void loop() {

  // Detect button press
  if (digitalRead(BUTTON) == LOW && !requested) {
    requested = true;

    link.write('R');
    Serial.println("Request sent");

    delay(50);
  }

  // Receive messages from traffic Arduino
  if (link.available() > 0) {
    char received = link.read();

    if (received == 'G' && requested) {
      Serial.println("Crossing allowed");

      digitalWrite(RED, LOW);
      digitalWrite(GREEN, HIGH);

      delay(5000);

      digitalWrite(GREEN, LOW);
      digitalWrite(RED, HIGH);

      link.write('D');
      Serial.println("Crossing completed");
    }

    if (received == 'A') {
      // Wait until button is released
      while (digitalRead(BUTTON) == LOW) {
        delay(10);
      }

      requested = false;
      Serial.println("Ready for next request");
    }
  }
}
