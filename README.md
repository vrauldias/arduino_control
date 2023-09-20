# Implementation of low-cost feedback control in a shell-and-tube heat exchanger

This work was developed at Federal University of Technology – Paraná (Universidade Tecnológica Federal do Paraná), Londrina, Paraná, Brazil.

## Overview

This repository contains the code and documentation for implementing a low-cost PID control system for a shell-and-tube heat exchanger using Arduino. The project focuses on temperature control of the heat exchanger outlet by manipulating the rotation of a centrifugal pump and fluid flow in the shell.

![sketch_hor_bb](https://github.com/vrauldias/arduino_control/assets/71993154/9bde133d-29a7-4c54-acae-a28fb02fb069)

## Project Description

Industrial process control is typically done using expensive Programmable Logic Controllers (PLCs). This project uses Arduino to explore an alternative by implementing a low-cost PID control system. The PID controller adjusts the pump's rotation to maintain the process temperature close to a set point.

The methodology involves utilizing an educational shell-and-tube heat exchanger module with Arduino components. The PID controller's feasibility is assessed within the pump's operational range.

##Requirements

To run this project, you will need the following hardware and software:

1. Arduino board (Arduino Uno R3)
2. Centrifugal water pump (RS385)
3. PWM Driver (IRF520 MOSFET)
4. DC Power Supply (12V)
5. Temperature sensor (DS18B20)
6. Water flow sensor (YF-S201)
7. Resistors (1 kΩ)
8. Shell-and-tube heat exchanger module
9. Arduino IDE

## Installation

Clone this repository to your local machine:
```
git clone https://github.com/yourusername/heat-exchanger-pid-control.git
```
1. Open the Arduino IDE
2. Load the Arduino sketch provided in the src/ directory
3. Connect your Arduino board to the computer
4. Upload the sketch to your Arduino board

## Usage

1. Connect the temperature sensor with resistors to the appropriate pins on the Arduino board
2. Repeat the first step for the water flow sensor
3. Connect the centrifugal water pump and the DC Power Supply to the PWM Driver and connect the Driver to the Arduino board
4. Install the sensors in the best point for the PID Control
5. Power on the Arduino and the other hardware components
6. Open the Arduino IDE and, if needed, change the P, I & D parameters.

For the last step, you can try [sTune](https://www.arduino.cc/reference/en/libraries/stune/) to tune the three parameters (P, I & D).

## Contact

Raul Guilherme Dias - rauldias@alunos.utfpr.edu.br

Felipi Luiz de Assunção Bezerra - felipibezerra@utfpr.edu.br

## License

This work is licensed under a [Creative Commons Attribution 4.0 International License](http://creativecommons.org/licenses/by/4.0/).
