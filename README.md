# 🤖 Obstacle-Avoiding Robot

![Project Status](https://img.shields.io/badge/status-Completed-brightgreen.svg)
![Sensors](https://img.shields.io/badge/Sensors-Ultrasonic%20Sensor-brightgreen.svg)
![Platform](https://img.shields.io/badge/platform-Arduino-blue.svg)
![Language](https://img.shields.io/badge/language-C%2FC%2B%2B-00599C.svg)
![IDE](https://img.shields.io/badge/IDE-Arduino%20IDE-success.svg)
![License](https://img.shields.io/badge/license-MIT-lightgrey.svg)

---

## Introduction

This project involves designing an autonomous robot that avoids obstacles using an ultrasonic sensor. The robot moves forward freely until it detects an obstacle within a predefined distance, upon which it stops, moves backward, and turns left to find a new path.

## Features

- Real-time obstacle detection
- Automatic decision-making for navigation
- Autonomous movement using DC motors
- Efficient obstacle-avoidance logic
- Simple and cost-effective design


## Hardware Components

- Arduino Uno (1x)
- Ultrasonic Sensor HC-SR04 (1x)
- L298N Motor Driver Module (1x)
- DC Geared Motors (4x)
- Robot Chassis (1x)
- Wheels (4x)
- Jumper Wires
- Power Supply (Battery)


## Pin Configuration
| **Component**       | **Arduino Pin**         |
|----------------------|-------------------------|
| Ultrasonic Sensor Trig | 2                      |
| Ultrasonic Sensor Echo | 3                      |
| Motor Driver ENA      | 11                     |
| Motor Driver ENB      | 10                     |
| Left Motor Pin 1      | 7                      |
| Left Motor Pin 2      | 6                      |
| Right Motor Pin 1     | 5                      |
| Right Motor Pin 2     | 4                      |

---


## Functional Overview

### Ultrasonic Sensor
- Measures the distance to the nearest object using sound waves.
- The trigger pin sends a short pulse, and the echo pin receives the reflected pulse.
- The time taken for the pulse to return is converted to distance.

### Motor Control
- The L298N motor driver controls the left and right DC motors.
- Motors are driven in different directions to achieve forward, backward, or turning movements.

### Movement Logic
1. **Move Forward**: If no obstacle is detected within 15 cm.
2. **Stop**: When an obstacle is detected.
3. **Move Backward**: Reverses direction for 2.5 seconds upon obstacle detection.
4. **Turn Left**: Rotates left for 2 seconds to find a clear path.

### Movement Functions
- `moveForward()`: Sets motor directions and speeds for forward motion.
- `moveBackward()`: Reverses motor directions for backward motion.
- `turnLeft()`: Spins the robot left by controlling motor directions and speeds.
- `Stop()`: Stops the robot by setting motor speeds to zero.

### Loop Function
- Measures the distance to the nearest object.
- Executes movement commands based on the measured distance:
  - **Distance ≥ 15 cm**: Move forward.
  - **Distance < 15 cm**: Stop, move backward, and turn left.


## Software Requirements

- Arduino IDE
- Arduino USB Drivers
- Serial Monitor for debugging (optional)

---

## Circuit Diagram


---

## Working Principle

The ultrasonic sensor emits sound waves and calculates the distance based on the time taken by the echo. If the detected distance is greater than 15 cm, the robot moves forward. If it's less than 15 cm, the robot stops, moves backward for a short duration, and then turns left to avoid the obstacle.

---

##  How to Run

1. Connect all hardware components as per the circuit diagram.
2. Open the Arduino IDE.
3. Paste the provided code into a new sketch.
4. Select the correct board (Arduino Uno) and port.
5. Upload the code.
6. Place the robot on the floor and power it on.
7. Watch it autonomously navigate around obstacles.

---

## Demonstration



---

## Applications

- Smart autonomous vehicles
- Line follower upgrades
- AI navigation-based robots
- Industrial automation robots
- Educational STEM kits

---

## Future Improvements

- Add IR sensors for edge detection
- Add a PID control 
- Introduce servo motors for dynamic sensor rotation
- Implement object mapping using SLAM
- Integrate Bluetooth or Wi-Fi for remote control override
- Use rechargeable battery and power monitoring circuit

---

## Troubleshooting / Common Issues

- **Robot not moving:** Check motor connections and power supply.
- **Ultrasonic sensor not detecting:** Ensure correct wiring of `trig` and `echo` pins.
- **Inconsistent movements:** Confirm proper voltage to the motor driver.
- **Serial Monitor not showing:** Make sure the correct baud rate (9600) is selected.

---

## Credits / Acknowledgements

This project was created and implemented by **Awais Asghar** as a part of learning embedded systems and robotics using Arduino.

---

## License

This project is licensed under the **MIT License**. You are free to use, modify, and distribute it with attribution.
