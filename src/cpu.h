#ifndef CPU_H
#define CPU_H
#include "bus.h"
#include <stdint.h>

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

uint8_t cpu_step(CPU *cpu, Bus *bus);

#endif
