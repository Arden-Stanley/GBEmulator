#include "cpu.h"

void cpu_toggle_flag(CPU *cpu, Flags flag) {
  switch (flag) {
  case Z:
    cpu->f ^= (1 << 0);
    break;
  case N:
    cpu->f ^= (1 << 1);
    break;
  case H:
    cpu->f ^= (1 << 2);
    break;
  case C:
    cpu->f ^= (1 << 3);
    break;
  }
}
uint8_t cpu_get_flag(CPU *cpu, Flags flag) {
  switch (flag) {
  case Z:
    return (cpu->f >> 0) & 1;
  case N:
    return (cpu->f >> 1) & 1;
  case H:
    return (cpu->f >> 2) & 1;
  case C:
    return (cpu->f >> 3) & 1;
  }
}

uint8_t cpu_step(CPU *cpu, Bus *bus) {
  uint8_t opcode = bus_read(bus, cpu->pc++);

  switch (opcode) {

  case 0x00: // noop
    return 1;
  case 0x01: // ld bc, n16
    cpu->bc = bus_read(bus, cpu->pc++);
    return 3;
  case 0x02: // ld [bc], a
    bus_write(bus, cpu->bc, cpu->a);
    return 2;
  case 0x03: // inc bc
    cpu->bc++;
    return 2;
  case 0x04: // inc b
             // todo
  case 0x05: // dec b
             // todo
  case 0x06:
  }

  return 0;
}
