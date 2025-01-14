# FireFighter Bot

FireFighter Bot is an Arduino-based project designed to detect and extinguish fires. It integrates sensors and actuators to create a functional fire-fighting robot. The system includes a flame sensor, servo motor, water pump, and an ultrasonic sensor to navigate and react to fire hazards.

## Features

- **Fire Detection:** Utilizes a flame sensor to identify fire sources.
- **Extinguishing System:** Activates a water pump to extinguish the detected fire.
- **Obstacle Avoidance:** Uses an ultrasonic sensor for obstacle detection and navigation.
- **Servo Control:** Directs the water pump towards the fire using a servo motor.
- **Motorized Movement:** Controlled by a motor driver for mobility.

## Components Used

- Arduino board
- Flame sensor
- Ultrasonic sensor (HC-SR04)
- Servo motor
- Water pump
- Motor driver
- DC motors
- Miscellaneous (resistors, wires, breadboard, etc.)

## How It Works

1. The flame sensor continuously monitors for fire.
2. Upon detecting a fire, the servo motor aligns the water pump to target the flame.
3. The water pump is activated to extinguish the fire.
4. The ultrasonic sensor helps navigate the robot and avoid obstacles.
5. The motor driver controls the robot’s movement based on the input from the ultrasonic sensor.

## Setup Instructions

1. Connect the components as per the circuit diagram provided in the code.
2. Upload the `FireFighter.ino` code to the Arduino board.
3. Power the Arduino board and ensure all connections are secure.
4. Place the robot in an area where it can detect and extinguish small fires safely.

## Code Overview

The code is written in Arduino C and includes the following key elements:

- **Libraries:** Uses the Servo library for servo motor control.
- **Pin Definitions:** Assigns specific pins for the flame sensor, ultrasonic sensor, motor driver, and pump.
- **Setup Function:** Initializes all components and sets pin modes.
- **Loop Function:** Continuously monitors sensor inputs and executes fire-fighting logic.

## Safety Note

This project is designed for educational purposes only. Ensure safety precautions when testing with flames and use small, controlled fires in a safe environment.

## Contributing

Feel free to fork the repository and contribute to improving the FireFighter Bot.

## License

This project is licensed under the MIT License. See the LICENSE file for details.

---

### Contact

For questions or suggestions, please open an issue or reach out to the repository maintainer.

