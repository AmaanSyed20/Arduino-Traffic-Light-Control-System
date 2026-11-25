Task 5 · UART Communication Between Two Arduinos

This task extends the "Task 4 pedestrian-crossing prototype" (../Task%204/) by distributing the vehicle and pedestrian signals across two separate Arduino microcontrollers. Instead of controlling both signals from a single board, the two controllers exchange crossing requests and status signals through UART communication.

"Watch the hardware demonstration" (./Traffic_Light_Demo.mp4)

Implementation

One Arduino controls the red, yellow and green vehicle LEDs, while the second controls the pedestrian LEDs and reads the push-button input.

When a pedestrian requests a crossing, the pedestrian controller sends a signal to the vehicle controller. The vehicle signal transitions through yellow to red before granting permission to cross. Once the crossing phase ends, the pedestrian controller sends a completion signal, allowing the vehicle signal to return to green.

Arduino pin assignments

Connection| Vehicle Arduino| Pedestrian Arduino
Red LED| D9| D10
Yellow LED| D7| —
Green LED| D5| D5
Push-button| —| D8
UART RX| D2| D2
UART TX| D3| D3

The transmit pin of each Arduino connects to the receive pin of the other. Both controllers share a common ground.

Communication interface

UART was selected because the system only requires communication between two microcontrollers. Unlike SPI, it does not require a separate clock signal, and unlike I2C, it does not require device addressing.

The "SoftwareSerial" library enables bidirectional communication at 9600 baud through pins D2 and D3, leaving the hardware serial interface available for debugging.

Hardware testing

The vehicle and pedestrian circuits can be tested independently before establishing UART communication. This separates potential wiring problems from communication errors and simplifies debugging.

The hardware demonstration documents the two-controller breadboard implementation as the next stage of the ongoing lab project.
