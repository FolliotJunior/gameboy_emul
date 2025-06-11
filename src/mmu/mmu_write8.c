#include "mmu.h"

void mmu_write8(mmu_t *mmu, uint16_t addr, uint8_t val)
{
    if (addr <= 0x7FFF) return;
    if (addr <= 0x9FFF) mmu->vram[addr - 0x8000] = val;
    else if (addr <= 0xBFFF) mmu->eram[addr - 0xA000] = val;
    else if (addr <= 0xDFFF) mmu->wram[addr - 0xC000] = val;
    else if (addr <= 0xFDFF) mmu->wram[addr - 0xE000] = val;
    else if (addr <= 0xFE9F) mmu->oam[addr - 0xFE00] = val;
    else if (addr <= 0xFEFF) return;
    else if (addr <= 0xFF7F) mmu->io[addr - 0xFF00] = val;
    else if (addr <= 0xFFFE) mmu->hram[addr - 0xFF80] = val;
    else if (addr == 0xFFFF) mmu->ie = val;
}
