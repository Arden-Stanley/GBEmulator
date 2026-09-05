#include "cpu.h"

static void op_ld8_reg_imm(CPU *cpu, Bus *bus, uint8_t *reg) {
  *reg = bus_read(bus, cpu->pc++);
}

static void op_ld16_reg_imm(CPU *cpu, Bus *bus, uint16_t *reg) {
  uint8_t high_byte = bus_read(bus, cpu->pc++);
  uint8_t low_byte = bus_read(bus, cpu->pc++);
  *reg = (high_byte << 8) | low_byte;
}

static void op_ld8_reg_reg(uint8_t *reg_dest, uint8_t reg_src) {
  *reg_dest = reg_src;
}

static void op_ld8_mem_reg(Bus *bus, uint16_t addr, uint8_t data) {
  bus_write(bus, addr, data);
}

static void op_ld8_reg_mem(Bus *bus, uint16_t addr, uint8_t *reg) {
  *reg = bus_read(bus, addr);
}

static void op_ld8_mem_imm(CPU *cpu, Bus *bus, uint16_t addr) {
  uint8_t data = bus_read(bus, cpu->pc++);
  bus_write(bus, addr, data);
}

static void op_inc8_reg(uint8_t *reg) { *reg = *reg + 1; }

static void op_inc16_reg(uint16_t *reg) { *reg = *reg + 1; }

static void op_inc8_mem(Bus *bus, uint16_t addr) {
  uint8_t data = bus_read(bus, addr);
  bus_write(bus, addr, data + 1);
}
static void op_dec8_reg(uint8_t *reg) { *reg = *reg - 1; }

static void op_dec16_reg(uint16_t *reg) { *reg = *reg - 1; }

static void op_dec8_mem(Bus *bus, uint16_t addr) {
  uint8_t data = bus_read(bus, addr);
  bus_write(bus, addr, data - 1);
}

static void op_rlc_reg(CPU *cpu, uint8_t *reg) {}

static void op_rlc_mem(CPU *cpu, Bus *bus, uint16_t addr) {}

static void op_rl_reg(CPU *cpu, uint8_t *reg) {}

static void op_rl_mem(CPU *cpu, Bus *bus, uint16_t addr) {}

uint8_t cpu_step(CPU *cpu, Bus *bus) {
  uint8_t opcode = bus_read(bus, cpu->pc++);

  switch (opcode) {
  case 0x00:
    break;
  case 0x01:
    op_ld16_reg_imm(cpu, bus, &cpu->bc);
    break;
  case 0x02:
    op_ld8_mem_reg(bus, cpu->bc, cpu->a);
  case 0x03:
    op_inc16_reg(&cpu->bc);
  case 0x04:
    op_inc8_reg(&cpu->b);
  case 0x05:
    op_dec8_reg(&cpu->b);
  case 0x06:
    op_ld8_reg_imm(cpu, bus, &cpu->b);
  case 0x07:

  case 0x11:
    op_ld16_reg_imm(cpu, bus, &cpu->de);
    break;
  case 0x21:
    op_ld16_reg_imm(cpu, bus, &cpu->hl);
    break;
  case 0x31:
    op_ld16_reg_imm(cpu, bus, &cpu->sp);
    break;
  case 0x40:
    op_ld8_reg_reg(&cpu->b, cpu->b);
    break;
  case 0x41:
    op_ld8_reg_reg(&cpu->b, cpu->c);
    break;
  case 0x42:
    op_ld8_reg_reg(&cpu->b, cpu->d);
    break;
  case 0x43:
    op_ld8_reg_reg(&cpu->b, cpu->e);
    break;
  case 0x44:
    op_ld8_reg_reg(&cpu->b, cpu->h);
    break;
  case 0x45:
    op_ld8_reg_reg(&cpu->b, cpu->l);
    break;
  case 0x46:

    break;
  case 0x47:
    op_ld8_reg_reg(&cpu->b, cpu->a);
    break;
  case 0x48:
    op_ld8_reg_reg(&cpu->c, cpu->b);
    break;
  case 0x49:
    op_ld8_reg_reg(&cpu->c, cpu->c);
    break;
  case 0x4A:
    op_ld8_reg_reg(&cpu->c, cpu->d);
    break;
  case 0x4B:
    op_ld8_reg_reg(&cpu->c, cpu->e);
    break;
  case 0x4C:
    op_ld8_reg_reg(&cpu->c, cpu->h);
    break;
  case 0x4D:
    op_ld8_reg_reg(&cpu->c, cpu->l);
    break;
  case 0x4E:
    break;
  case 0x4F:
    op_ld8_reg_reg(&cpu->c, cpu->a);
    break;
  case 0x50:
    op_ld8_reg_reg(&cpu->d, cpu->b);
    break;
  case 0x51:
    op_ld8_reg_reg(&cpu->d, cpu->c);
    break;
  case 0x52:
    op_ld8_reg_reg(&cpu->d, cpu->d);
    break;
  case 0x53:
    op_ld8_reg_reg(&cpu->d, cpu->e);
    break;
  case 0x54:
    op_ld8_reg_reg(&cpu->d, cpu->h);
    break;
  case 0x55:
    op_ld8_reg_reg(&cpu->d, cpu->l);
    break;
  case 0x56:
    break;
  case 0x57:
    op_ld8_reg_reg(&cpu->d, cpu->a);
    break;
  case 0x58:
    op_ld8_reg_reg(&cpu->e, cpu->b);
    break;
  case 0x59:
    op_ld8_reg_reg(&cpu->e, cpu->c);
    break;
  case 0x5A:
    op_ld8_reg_reg(&cpu->e, cpu->d);
    break;
  case 0x5B:
    op_ld8_reg_reg(&cpu->e, cpu->e);
    break;
  case 0x5C:
    op_ld8_reg_reg(&cpu->e, cpu->h);
    break;
  case 0x5D:
    op_ld8_reg_reg(&cpu->e, cpu->l);
    break;
  case 0x5E:
    break;
  case 0x5F:
    op_ld8_reg_reg(&cpu->e, cpu->a);
    break;
  case 0x60:
    op_ld8_reg_reg(&cpu->h, cpu->b);
    break;
  case 0x61:
    op_ld8_reg_reg(&cpu->h, cpu->c);
    break;
  case 0x62:
    op_ld8_reg_reg(&cpu->h, cpu->d);
    break;
  case 0x63:
    op_ld8_reg_reg(&cpu->h, cpu->e);
    break;
  case 0x64:
    op_ld8_reg_reg(&cpu->h, cpu->h);
    break;
  case 0x65:
    op_ld8_reg_reg(&cpu->h, cpu->l);
    break;
  case 0x66:
    break;
  case 0x67:
    op_ld8_reg_reg(&cpu->h, cpu->a);
    break;
  case 0x68:
    op_ld8_reg_reg(&cpu->l, cpu->b);
    break;
  case 0x69:
    op_ld8_reg_reg(&cpu->l, cpu->c);
    break;
  case 0x6A:
    op_ld8_reg_reg(&cpu->l, cpu->d);
    break;
  case 0x6B:
    op_ld8_reg_reg(&cpu->l, cpu->e);
    break;
  case 0x6C:
    op_ld8_reg_reg(&cpu->l, cpu->h);
    break;
  case 0x6D:
    op_ld8_reg_reg(&cpu->l, cpu->l);
    break;
  case 0x6E:
    break;
  case 0x6F:
    op_ld8_reg_reg(&cpu->l, cpu->a);
    break;
  default:
    printf("Invalid Opcode Provided: %X", opcode);
  }
  return 0;
}
