🚀 Embedded OTA Firmware Update System over SPI (ESP32 + STM32)
📌 Overview

This project implements a complete Over-The-Air (OTA) firmware update system using SPI communication between:

ESP32 (Master)
STM32F1 (Slave Bootloader)

The system transfers firmware in Intel HEX format, ensuring reliable delivery using a custom ACK/NACK protocol with retry handling.

🧠 System Architecture
        +-------------------+          SPI           +---------------------+
        |                   |  MOSI / MISO / CLK / CS|                     |
        |      ESP32        |  --------------------> |      STM32F1        |
        |   (SPI Master)    |                        |   (Bootloader)      |
        |                   | <--------------------  |                     |
        +-------------------+        ACK/NACK        +---------------------+
🔄 OTA Flow
START
  |
  v
ESP32 sends HEX line
  |
  v
STM32 receives (byte-by-byte)
  |
  v
Parse HEX record
  |
  +--> VALID? ---- NO ---> Send NACK ---> Retry
  |
  YES
  |
  v
Write to Flash
  |
  v
Send ACK
  |
  v
Next line
  |
  v
EOF received?
  |
  +--> NO ---> Continue
  |
  YES
  |
  v
Send STOP
  |
  v
Jump to Application
📦 Features
🔹 Custom SPI Protocol
    ACK (0x06) → Success
    NACK (0x15) → Retry required
    STOP (0xEE) → OTA complete
🔹 Reliable Transmission
    Retry mechanism (configurable attempts)
    Line-by-line validation
    Flow control between master and slave
🔹 Intel HEX Support
    Data Record (0x00)
    Extended Linear Address (0x04)
    End Of File (0x01)
🔹 Flash Programming (STM32)
    Sector erase before write
    Address validation (protect bootloader region)
    Safe write into application area
🔹 Streaming Parser
    Byte-by-byte processing
    Prevents buffer overflow
    Works with interrupt-based SPI
🔹 Bootloader Execution
    Set MSP (Main Stack Pointer)
    Jump to application reset handler
⚙️ Hardware Setup
    ESP32 (Master)
    MOSI → GPIO12
    MISO → GPIO13
    CLK → GPIO15
    CS → GPIO14
    STM32F103 (Slave)
    SPI1 (Hardware NSS enabled)
