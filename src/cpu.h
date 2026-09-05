#ifndef CPU_H
#define CPU_H
#include "bus.h"
#include <stdint.h>
#include <stdio.h>

typedef struct {
  union {
    uint16_t af;
    struct {
      uint8_t f;
      uint8_t a;
    };
  };
  union {
    uint16_t bc;
    struct {
      uint8_t c;
      uint8_t b;
    };
  };
  union {
    uint16_t de;
    struct {
      uint8_t e;
      uint8_t d;
    };
  };
  union {
    uint16_t hl;
    struct {
      uint8_t l;
      uint8_t h;
    };
  };
  uint16_t sp;
  uint16_t pc;
} CPU;

// naming convention: op_[operation]_[dest]_[src]
static void op_ld8_reg_imm(CPU *cpu, Bus *bus, uint8_t *reg);
static void op_ld16_reg_imm(CPU *cpu, Bus *bus, uint16_t *reg);
static void op_ld8_reg_reg(uint8_t *reg_dest, uint8_t reg_src);
static void op_ld8_mem_reg(Bus *bus, uint16_t addr, uint8_t data);
static void op_ld8_reg_mem(Bus *bus, uint16_t addr, uint8_t *reg);
static void op_ld8_mem_imm(CPU *cpu, Bus *bus, uint16_t addr);
static void op_inc8_reg(uint8_t *reg);
static void op_inc16_reg(uint16_t *reg);
static void op_inc8_mem(Bus *bus, uint16_t addr);
static void op_dec8_reg(uint8_t *reg);
static void op_dec16_reg(uint16_t *reg);
static void op_dec8_mem(Bus *bus, uint16_t addr);

uint8_t cpu_step(CPU *cpu, Bus *bus);

#endif
