# arduino_control
Implementation of low-cost feedback control in a shell-and-tube heat exchanger

Low-Cost PID Control for Shell-and-Tube Heat Exchanger Using Arduino
Overview

This repository contains the code and documentation for implementing a low-cost PID control system for a shell-and-tube heat exchanger using Arduino. The project focuses on temperature control of the heat exchanger outlet by manipulating the rotation of a centrifugal pump and fluid flow in the shell.

Heat Exchanger
Table of Contents

    Project Description
    Requirements
    Installation
    Usage
    Contributing
    License

Project Description

Industrial process control is typically done using expensive Programmable Logic Controllers (PLCs). This project explores an alternative by implementing a low-cost PID control system using Arduino. The PID controller adjusts the pump's rotation to maintain the process temperature close to a set-point.

The methodology involves utilizing an educational shell-and-tube heat exchanger module in conjunction with Arduino components. The PID controller's feasibility is assessed within the pump's operational range.
Requirements

To run this project, you will need the following hardware and software:

    Arduino board (e.g., Arduino Uno)
    Centrifugal pump
    Temperature sensor
    Shell-and-tube heat exchanger module
    Arduino IDE

Installation

    Clone this repository to your local machine:

    bash

    git clone https://github.com/yourusername/heat-exchanger-pid-control.git

    Open the Arduino IDE.

    Load the Arduino sketch provided in the src/ directory.

    Connect your Arduino board to the computer.

    Upload the sketch to your Arduino board.

Usage

    Connect the temperature sensor to the appropriate pins on the Arduino board.

    Install the heat exchanger module and the centrifugal pump in the system.

    Power on the Arduino and the hardware components.

    Open the Arduino serial monitor to view temperature readings and control adjustments.

Contributing

Contributions to this project are welcome. Feel free to open issues, submit pull requests, or provide feedback.
License

This project is licensed under the MIT License.
