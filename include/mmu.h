#ifndef _EMUL_GAMEBOY_MMU_H_
#define _EMUL_GAMEBOY_MMU_H_
#include <stdint.h>

typedef struct mmu_s {
    uint8_t rom[0x8000];     // ROM (Bank 0 + switchable)
    uint8_t vram[0x2000];    // VRAM
    uint8_t eram[0x2000];    // External RAM
    uint8_t wram[0x2000];    // Work RAM
    uint8_t oam[0xA0];       // Object Attribute Memory (sprites)
    uint8_t io[0x80];        // I/O registers
    uint8_t hram[0x7F];      // High RAM
    uint8_t ie;              // Interrupt Enable Register
} mmu_t;

/// @brief read 8 bit from the mmu
/// @param mmu the memory struct
/// @param addr the address to read
/// @return the address read
uint8_t mmu_read8(mmu_t *mmu, uint16_t addr);

/// @brief write 8 bit in the memory
/// @param mmu the memory struct
/// @param addr the address to write the value
/// @param val the value to write
void mmu_write8(mmu_t *mmu, uint16_t addr, uint8_t val);

#endif
