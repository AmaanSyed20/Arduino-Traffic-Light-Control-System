# Task 5 · Traffic Light Control Using UART

This task extends the [Task 4 pedestrian-crossing prototype](../Task%204/) by distributing the vehicle and pedestrian signals across two separate Arduino microcontrollers. The controllers exchange crossing requests and status signals through UART communication.

[Watch the traffic light system demonstration](./Traffic_Light_Demo.mp4)

## Communication between the controllers

UART provides bidirectional communication without requiring a separate clock signal. The `SoftwareSerial` library enables communication at 9600 baud using digital pins D2 and D3. The transmit pin of each Arduino connects to the receive pin of the other, and both controllers share a common ground.

## Crossing sequence

When the pedestrian button is pressed, the pedestrian controller sends a crossing request to the vehicle controller. The vehicle signal passes through yellow to red before permission to cross is transmitted.

After the crossing phase ends, the pedestrian signal returns to red and sends a completion signal. The vehicle controller then transitions through red and yellow before returning to green.

## Arduino pin assignments

| Connection | Vehicle Arduino | Pedestrian Arduino |
|---|---|---|
| Red LED | D9 | D10 |
| Yellow LED | D7 | — |
| Green LED | D5 | D5 |
| Push-button | — | D8 |
| UART RX | D2 | D2 |
| UART TX | D3 | D3 |

Unlike the [Task 2 pedestrian-crossing design](../Task%202/), the two signals are controlled by independent microcontrollers. The hardware recording documents the integration of serial communication into the ongoing lab project.
