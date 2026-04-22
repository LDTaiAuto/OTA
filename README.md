🚀 Embedded OTA Firmware Update System over SPI (ESP32 + STM32)
📌 Overview

This project implements a complete Over-The-Air (OTA) firmware update system using SPI communication between:

ESP32 (Master)






STM32F1 (Slave Bootloader)

The system transfers firmware in Intel HEX format, ensuring reliable delivery using a custom ACK/NACK protocol with retry handling.
