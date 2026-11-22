# Task 2 · Push-Button Pedestrian Crossing

This task extends the vehicle signal with a pedestrian push-button and separate red and green pedestrian LEDs. The controller rests in vehicle green. A crossing request starts the transition once the minimum vehicle-green interval has elapsed.

## Crossing sequence

| Phase | Timing specified in the design |
|---|---|
| Vehicle green | Minimum 10 seconds |
| Vehicle yellow | 5 seconds |
| Both signals red before the crossing | 2 seconds |
| Pedestrian green, vehicle red | 10 seconds |
| Both signals red after the crossing | 2 seconds |
| Vehicle red and yellow | 2 seconds |
| Return to vehicle green | Await the next request |

The two all-red phases serve different points in the sequence. The first introduces a pause before pedestrians receive green. The second introduces a pause after pedestrian green ends and before the vehicle signal prepares to return to green.

## Arduino pin assignments

| Connection | Digital pin |
|---|---|
| Vehicle red, yellow and green LEDs | D10, D7 and D4, respectively |
| Pedestrian red and green LEDs | D3 and D2, respectively |
| Pedestrian push-button | D12 |

## Files

- [Class and state-machine diagrams](./Class%20Diagram%20%26%20State%20Machine%20Diagram.png)
- [Traffic light circuit image](./Task%202%20Traffic%20Light%20System.png)
- [Tinkercad simulation link](./Simulation%20-%20TinkerCAD.txt)
- [Breadboard demonstration in Task 4](../Task%204/)
