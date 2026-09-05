#include "bus.h"

#include <stdio.h>

uint8_t bus_read(Bus *bus, uint16_t addr) {
  if (addr < 0x8000) {
    return 0x00; // change later
  }
  if (addr < 0xA000) {
    return bus->vram[addr - 0x8000];
  }
  if (addr < 0xC000) {
    return 0x00; // change later
  }
  if (addr < 0xE000) {
    return bus->wram[addr - 0xC000];
  }
  if (addr < 0xFE00) {
    return bus->wram[addr - 0xE000];
  }
  if (addr < 0xFEA0) {
    return bus->oam[addr - 0xFE00];
  }
  if (addr < 0xFF00) {
    return 0x00;
  }
  if (addr < 0xFF80) {
    return bus->io[addr - 0xFF00];
  }
  if (addr < 0xFFFF) {
    return bus->hram[addr - 0xFF80];
  }
  if (addr == 0xFFFF) {
    return bus->ie;
  }
  return 0x00;
}

void bus_write(Bus *bus, uint16_t addr, uint8_t data) {
  if (addr < 0x8000) {
  }
  if (addr < 0xA000) {
    bus->vram[addr - 0x8000] = data;
  }
  if (addr < 0xC000) {
  }
  if (addr < 0xE000) {
    bus->wram[addr - 0xC000] = data;
  }
  if (addr < 0xFE00) {
    bus->wram[addr - 0xE000] = data;
  }
  if (addr < 0xFEA0) {
    bus->oam[addr - 0xFE00] = data;
  }
  if (addr < 0xFF00) {
  }
  if (addr < 0xFF80) {
    bus->io[addr - 0xFF00] = data;
  }
  if (addr < 0xFFFF) {
    bus->hram[addr - 0xFF80] = data;
  }
  if (addr == 0xFFFF) {
    bus->ie = data;
  }
  if (addr > 0xFFFF) {
    printf("Memory Address Out of Bounds: %X", addr);
  }
}
