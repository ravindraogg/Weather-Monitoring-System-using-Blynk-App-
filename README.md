# Weather Monitoring System using Blynk App 🌦️

This project is a real-time weather monitoring system that collects environmental data and displays it on the Blynk mobile app. The system is powered by NodeMCU (ESP8266) and uses multiple sensors to measure temperature, humidity, light intensity, and rainfall levels, providing a complete weather tracking solution.

## Table of Contents
1. [Overview](#overview)
2. [Modules Used](#modules-used)
3. [Material Required](#material-required)
4. [Circuit Diagram](#circuit-diagram)
5. [Installation](#installation)
6. [Code Explanation](#code-explanation)
7. [Project Setup](#project-setup)
8. [Applications](#applications)
9. [Advantages](#advantages)
10. [Result](#result)

## Overview
The **Weather Monitoring System** is an IoT project designed to provide real-time weather data, such as temperature, humidity, rainfall, and light levels, which can be accessed remotely via the Blynk app. This setup is beneficial for agriculture, research, or home automation systems where users need accurate weather data.

### Purpose and Goals
- **Real-Time Data**: Continuously monitor and log weather data.
- **Remote Accessibility**: Access data from anywhere using the Blynk app.
- **Alert System**: Receive notifications for extreme weather conditions.

## Modules Used
1. **DHT11 (Temperature & Humidity Sensor)**: Measures temperature and humidity.
2. **Rain Sensor**: Detects rainfall and its intensity.
3. **LDR (Light Dependent Resistor)**: Measures ambient light levels.
4. **NodeMCU (ESP8266)**: Microcontroller that processes sensor data and sends it to the Blynk app.

## Material Required
- NodeMCU (ESP8266)
- DHT11 sensor
- Rain sensor
- LDR sensor
- 16x2 LCD with I2C module
- Breadboard, jumper wires, and a power source
- Blynk App

## Circuit Diagram
**Connection Table:**
- **DHT11** → D3
- **LDR** → D4
- **Rain Sensor** → A0
- **I2C LCD** → SCL (D1), SDA (D2)

## Installation
1. Install the **Blynk** app and create a new project with required widgets.
2. Install the libraries:
   - Blynk Library
   - ESP8266 Library
   - DHT11 Library
   - LiquidCrystal I2C Library

## Code Explanation
- The main code initializes the sensors and NodeMCU’s connection to Blynk.
- Sensor values are read and sent to the Blynk app, providing real-time weather data.

## Project Setup
1. Configure the **Blynk app** with widgets for each sensor.
2. Connect NodeMCU to Wi-Fi using the credentials in the code.

## Applications
- **Agriculture**: Helps farmers monitor weather conditions.
- **Smart Homes**: Integrates with home automation systems.
- **Environmental Monitoring**: Useful for research and analysis.

## Advantages
- Fully automated, requires minimal human interaction.
- High accuracy, reliable for monitoring weather remotely.

## Result
The system provides real-time weather data accessible on the Blynk app. Temperature, humidity, rainfall, and light levels are displayed for remote monitoring.

---
