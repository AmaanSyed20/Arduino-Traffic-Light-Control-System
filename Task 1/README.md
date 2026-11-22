# Task 1 · Timed Vehicle Signal

This Arduino sketch controls red, yellow and green LEDs using a four-state finite state machine. The controller starts on red and repeats the following sequence.

| State | LEDs on | Programmed duration |
|---|---|---|
| Red | Red | 5 seconds |
| Red and yellow | Red and yellow together | 1 second |
| Green | Green | 5 seconds |
| Yellow | Yellow | 2 seconds |

One complete cycle lasts **13 seconds**.

## Implementation

The sketch assigns digital pin D10 to red, D7 to yellow and D4 to green. The variable `currentState` tracks the active phase. On each pass through `loop()`, a `switch` selects the corresponding LED pattern, holds it using `delay()`, and sets the next state.

The helper function `setLights()` writes all three outputs for each phase. For example, the red-and-yellow state turns both LEDs on together while keeping green off.

## Files

- [Arduino sketch](./Code.ino)
- [Class and state-machine diagrams](./Class%20Diagram%20%26%20State%20Machine%20Diagram.png)
- [Tinkercad circuit screenshot](./Simulation%20-%20Image.png)
- [Tinkercad simulation link](./Simulation%20-%20TinkerCAD.txt)
- [Breadboard demonstration in Task 3](../Task%203/)
