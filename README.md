🚀 Embedded OTA Firmware Update System over SPI (ESP32 + STM32)
📌 Overview

This project implements a complete Over-The-Air (OTA) firmware update system using SPI communication between:

ESP32 (Master)






STM32F1 (Slave Bootloader)

The system transfers firmware in Intel HEX format, ensuring reliable delivery using a custom ACK/NACK protocol with retry handling.


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
⚙️ Hardware Setup

    ESP32 (Master)
        MOSI → GPIO12
        
        MISO → GPIO13
        
        CLK → GPIO15
        
        CS → GPIO14
        
    STM32F103 (Slave)
    
        SPI1 (Hardware NSS enabled)
        
💡 Key Learnings
    Designing reliable communication over SPI
    
    Handling streaming data in embedded systems
    
    Bootloader and memory management on STM32
    
    Debugging real-world data loss issues
    
