#include "Flash.h"


void Flash_Unlock(void)
{
    if (FLASH->CR & FLASH_CR_LOCK)
    {
        FLASH->KEYR = 0x45670123;
        FLASH->KEYR = 0xCDEF89AB;
    }
}

void Flash_Lock(void)
{
    FLASH->CR |= FLASH_CR_LOCK;
}

void Flash_Wait(void)
{
    while (FLASH->SR & FLASH_SR_BSY);
}

void Flash_Erase(void)
{
    Flash_Unlock();

    for (uint32_t addr = APP_ADDRESS; addr < FLASH_END; addr += 1024)
    {
        Flash_Wait();

        FLASH->CR |= FLASH_CR_PER;
        FLASH->AR = addr;
        FLASH->CR |= FLASH_CR_STRT;

        Flash_Wait();

        FLASH->CR &= ~FLASH_CR_PER;
    }

    Flash_Lock();
}

void Flash_Write(uint32_t addr, uint8_t *data, uint16_t len)
{
    Flash_Unlock();

    for (int i = 0; i < len; i += 2)
    {
        uint16_t halfword = data[i];

        if (i + 1 < len)
            halfword |= (data[i + 1] << 8);
        else
            halfword |= 0xFF00;

        Flash_Wait();

        FLASH->CR |= FLASH_CR_PG;

        *(volatile uint16_t*)addr = halfword;

        Flash_Wait();

        FLASH->CR &= ~FLASH_CR_PG;

        addr += 2;
    }

    Flash_Lock();
}
