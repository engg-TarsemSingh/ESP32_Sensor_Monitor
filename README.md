# ESP32 Sensor Monitor

## Overview
This project demonstrates a simple **ESP32-based IoT system** that reads analog sensor data (heart rate / pulse) and sends it to a laptop via **SoftAP WiFi**. A **Flask API** running on the laptop receives the data and generates real-time plots using **matplotlib**.

---

## Features
- ESP32 runs as a **Soft Access Point (SoftAP)**.
- Sends sensor data to a laptop at **1-second intervals**.
- Flask API receives data and plots it in real time.
- Maintains the last 60 readings for plotting.

---

## Folder Structure
IOT_PROJECT
|--  __pycache__
|--  sketch_nov11a_ino
|    |--  ESP32_Code.ino
|--  Flask_API.py
|--  Graph_Plotting.py
|--  graph.png


---

## Setup Instructions

### 1. ESP32
1. Upload `ESP32_Code.ino` to your ESP32 via Arduino IDE.
2. ESP32 creates a SoftAP network (`ESPtars`).
3. Connect your laptop to this WiFi network.

> **Note:** Check your laptop IP in this network (e.g., `192.168.4.2`) and update `ServerURL` in the ESP32 code.

### 2. Laptop / Flask API
1. Install required Python libraries:
```bash
pip install flask matplotlib
