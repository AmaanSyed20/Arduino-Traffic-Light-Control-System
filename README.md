# Arduino Traffic Light Control System

An ongoing Embedded Systems lab project at Hochschule Hamm-Lippstadt. The project explores how an Arduino can control a vehicle signal on a fixed timer and then coordinate vehicle and pedestrian signals when someone requests a crossing.

## Project tasks

| Task | Focus | Files |
|---|---|---|
| [Task 1](./Task%201/) | Program a four-state vehicle signal | Arduino sketch, state diagram and Tinkercad simulation |
| [Task 2](./Task%202/) | Design a push-button pedestrian crossing | State diagram, circuit image and Tinkercad simulation |
| [Task 3](./Task%203/) | Build the Task 1 vehicle signal on a breadboard | Hardware demonstration video |
| [Task 4](./Task%204/) | Build the Task 2 pedestrian crossing on a breadboard | Hardware demonstration video |

## How the controller develops

The first controller repeats a 13-second sequence using three LEDs. The second design introduces a push-button input and a separate pedestrian signal. An all-red interval separates the end of vehicle movement from the start of the crossing phase. A second all-red interval precedes the return to vehicle green.

The lab is still in progress. The timings documented here come from the Task 1 sketch and the Task 2 state diagram. The videos show the corresponding breadboard prototypes.
