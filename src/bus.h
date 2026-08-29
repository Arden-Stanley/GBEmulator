#ifndef BUS_H
#define BUS_H

#include <stdint.h>

typedef struct {
  uint8_t vram[0x2000];
  uint8_t wram[0x2000];
  uint8_t oam[0x0A0];
  uint8_t io[0x080];
  uint8_t hram[0x07F];
  uint8_t ie;
} Bus;

uint8_t bus_read(Bus *bus, uint16_t addr);

void bus_write(Bus *bus, uint16_t addr, uint8_t data);

#endif
