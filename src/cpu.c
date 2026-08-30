#include "cpu.h"

uint8_t cpu_step(CPU *cpu, Bus *bus) {
  uint8_t opcode = bus_read(bus, cpu->pc);
  cpu->pc++;
  switch (opcode) {
  case 0x00: // nop
    break;

  case 0x01: // ld bc, n16
    cpu->bc = bus_read(bus, cpu->pc);
    cpu->pc++;
    break;

  case 0x11: // ld de, n16
    cpu->de = bus_read(bus, cpu->pc);
    cpu->pc++;
    break;

  case 0x21: // ld hl, n16
    cpu->hl = bus_read(bus, cpu->pc);
    cpu->pc++;
    break;

  case 0x31: // ld sp, n16
    cpu->sp = bus_read(bus, cpu->pc);
    cpu->pc++;
    break;
  }
}
