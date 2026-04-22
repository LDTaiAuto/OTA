#ifndef FLASH_H_ 
#define FLASH_H_

#include <string.h>
#include <stdio.h>
#include "stm32f1xx_hal.h"

#define APP_ADDRESS 0x0800C800
#define FLASH_END   0x08010000


void Flash_Unlock(void);
void Flash_Lock(void);
void Flash_Wait(void);
void Flash_Erase(void);
void Flash_Write(uint32_t addr, uint8_t *data, uint16_t len);


#endif 
