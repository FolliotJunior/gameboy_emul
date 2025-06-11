#include "mmu.h"

uint8_t mmu_read8(mmu_t *mmu, uint16_t addr)
{
    if (addr <= 0x7FFF) return mmu->rom[addr];
    if (addr <= 0x9FFF) return mmu->vram[addr - 0x8000];
    if (addr <= 0xBFFF) return mmu->eram[addr - 0xA000];
    if (addr <= 0xDFFF) return mmu->wram[addr - 0xC000];
    if (addr <= 0xFDFF) return mmu->wram[addr - 0xE000];
    if (addr <= 0xFE9F) return mmu->oam[addr - 0xFE00];
    if (addr <= 0xFEFF) return 0xFF;
    if (addr <= 0xFF7F) return mmu->io[addr - 0xFF00];
    if (addr <= 0xFFFE) return mmu->hram[addr - 0xFF80];
    if (addr == 0xFFFF) return mmu->ie;
    return 0xFF;
}
