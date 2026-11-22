// Pin Definitions
const int redPin = 10;
const int yellowPin = 7;
const int greenPin = 4;

// State Definitions
enum State { RED, RED_YELLOW, GREEN, YELLOW };
State currentState = RED; // Start at Red

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  // The Switch State Pattern
  switch (currentState) {
    
    case RED:
      setLights(HIGH, LOW, LOW); // Action: Turn on Red
      delay(5000);               // Wait: 5 seconds
      currentState = RED_YELLOW; // Transition: Move to next state
      break;

    case RED_YELLOW:
      setLights(HIGH, HIGH, LOW);
      delay(1000);
      currentState = GREEN;
      break;

    case GREEN:
      setLights(LOW, LOW, HIGH);
      delay(5000);
      currentState = YELLOW;
      break;

    case YELLOW:
      setLights(LOW, HIGH, LOW);
      delay(2000);
      currentState = RED; // Loop back to the beginning
      break;
  }
}

// Helper method so we don't have to write digitalWrite 3 times per case
void setLights(int r, int y, int g) {
  digitalWrite(redPin, r);
  digitalWrite(yellowPin, y);
  digitalWrite(greenPin, g);
}
