# Obstacle-Avoiding Robot

![Project Status](https://img.shields.io/badge/status-Completed-brightgreen.svg)
![Sensors](https://img.shields.io/badge/Sensors-Ultrasonic%20Sensor-pink.svg)
![Platform](https://img.shields.io/badge/platform-Arduino-blue.svg)
![Language](https://img.shields.io/badge/language-C%2FC%2B%2B-purple.svg)
![IDE](https://img.shields.io/badge/IDE-Arduino%20IDE-yellow.svg)
![License](https://img.shields.io/badge/license-MIT-lightgrey.svg)

![Image](https://github.com/user-attachments/assets/72f1be2b-e19d-4cb7-8683-401f68c6b5b8)

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
  
<img width="1024" height="500" alt="Image" src="https://github.com/user-attachments/assets/5655103a-51f2-4fb1-b3d7-753e2328d417" />

### Motor Control
- The **L298N motor driver** controls the left and right DC motors.
- Motors are driven in different directions to achieve forward, backward, or turning movements.
- **Output A, Output B** - To connect two motors.
- **Driver Power Input** - Board can accept 5V to 35V which will act as the power supply to motor and internal 5V voltage regulator (if it is enabled using jumper).
- **GND** - Common Ground
- **5V Output / Logic Input Voltage** - This pin will give 5V output if the on-board regulator is enabled using the jumper, other we should give the logic supply (5V in the case of Arduino Uno) to this pin.
- **IN1, IN2, IN3, IN4** - H-Bridge control inputs which can be used to control direction of motors.
- **Enable A and Enable B** pins are used for enabling each bridge or for controlling the speed of the motors using PWM.

<img width="1311" height="870" alt="Image" src="https://github.com/user-attachments/assets/d72299fe-5ef6-461a-aa27-9738a8109f35" />
<img width="1016" height="747" alt="Image" src="https://github.com/user-attachments/assets/c7701478-1e1b-4907-a5de-b80cbda0ec14" />
<img width="1035" height="852" alt="Image" src="https://github.com/user-attachments/assets/5a6758d3-49e1-4918-8b6c-d453d10c97c1" />


## Movement Logic
- `moveForward()`: If no obstacle is detected within 15 cm then sets motor directions and speeds for forward motion.
- `moveBackward()`: Reverses the motors direction for 2.5 seconds upon obstacle detection.
- `turnLeft()`: Rotate the robot left for 2 seconds to find a clear path by controlling motor directions and speeds.
- `Stop()`:  When an obstacle is detected it stops the robot by setting motor speeds to zero.


## How to Charge Lithium-Ion

### What You Need:
- **TP4056 charging module** (with or without protection circuit)
- **Lithium-Ion battery** (typically 3.7V, like an 18650 cell)
- **Power source** (5V via USB cable or 5V adapter)

###  Wiring Connections

| TP4056 Pin | Connects To           | Description                      |
|------------|-----------------------|----------------------------------|
| **BAT+**   | Battery Positive (+)  | Connect to battery's positive terminal |
| **BAT-**   | Battery Negative (–)  | Connect to battery's negative terminal |
| **IN+**    | 5V Power Positive     | USB VCC or 5V adapter            |
| **IN-**    | 5V Power Ground       | USB GND or adapter GND           |
| **OUT+**   | Output Positive (Optional) | Same as BAT+ if present     |
| **OUT-**   | Output Negative (Optional) | Same as BAT– if present     |


### Charging Status (LED Indicators)

- 🔴 **Red LED ON** → Charging
- 🟢 **Blue/Green LED ON** → Fully Charged (approx. 4.2V)

### TP4056 Specifications

- **Input Voltage:** 4.5V – 5.5V (recommended: 5V)
- **Charging Cut-off Voltage:** 4.2V
- **Max Charging Current:** 1A (default, adjustable by changing onboard resistor)

### Charging Steps

1. Connect **BAT+** and **BAT-** to the Lithium-ion battery terminals.
2. Connect **IN+** and **IN-** to a 5V power supply (USB or adapter).
3. Observe LED indicators:
   - Red = Charging
   - Green/Blue = Fully Charged
4. Disconnect power once fully charged (unless using protected module).


### Safety Tips

-  Never leave charging unattended.
-  Use only **genuine 3.7V Li-ion batteries**.
-  Avoid **short circuits** on BAT terminals.
-  **Do not reverse polarity** — it can damage the module and the battery.
-  Use **TP4056 with protection** for safer charging and discharging.

![Image](https://github.com/user-attachments/assets/ec110f7a-28bc-419d-adfa-fa863a73bb27)

---


## Software Requirements

- Arduino IDE
- Arduino USB Drivers
- Serial Monitor for debugging

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

![Image](https://github.com/user-attachments/assets/6db6bd8a-d5f4-40ab-9674-078412d4028b)

![Image](https://github.com/user-attachments/assets/5eed4681-d877-414e-917e-2cbeb0960c8f)

![Image](https://github.com/user-attachments/assets/5a248fce-fcd2-48e4-86ed-8843da2d9879)

---

## Applications

- Smart autonomous vehicles
- Line follower upgrades
- AI navigation-based robots
- Industrial automation robots
- Educational STEM kits

---

## Future Improvements

- Add a PID control 
- Implement object mapping using SLAM

---

## Troubleshooting / Common Issues

- **Robot not moving:** Check motor connections and power supply.
- **Ultrasonic sensor not detecting:** Ensure correct wiring of `trig` and `echo` pins.
- **Inconsistent movements:** Confirm proper voltage to the motor driver.
- **Serial Monitor not showing:** Make sure the correct baud rate (9600) is selected.

---

## Credits / Acknowledgements

This project was created and implemented by **Awais Asghar** as a part of learning embedded systems and robotics using Arduino.


## License

This project is licensed under the **MIT License**. You are free to use, modify, and distribute it with attribution.
