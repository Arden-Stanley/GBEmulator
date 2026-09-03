#include "cpu.h"

static void op_ld8_reg_imm(CPU *cpu, Bus *bus, uint8_t *reg) {
  *reg = bus_read(bus, cpu->pc++);
}

static void op_ld16_reg_imm(CPU *cpu, Bus *bus, uint16_t *reg) {
  uint8_t high_byte = bus_read(bus, cpu->pc++);
  uint8_t low_byte = bus_read(bus, cpu->pc++);
  *reg = (high_byte << 8) | low_byte;
}

uint8_t cpu_step(CPU *cpu, Bus *bus) {
  uint8_t opcode = bus_read(bus, cpu->pc++);

  switch (opcode) {
  case 0x00:
    break;
  case 0x01:
    op_ld16_reg_imm(cpu, bus, &cpu->bc);
    break;
  case 0x11:
    op_ld16_reg_imm(cpu, bus, &cpu->de);
    break;
  case 0x21:
    op_ld16_reg_imm(cpu, bus, &cpu->hl);
    break;
  case 0x31: // ld sp, n16
    op_ld16_reg_imm(cpu, bus, &cpu->sp);
    break;
  }
}
