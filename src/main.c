#include "bus.h"
#include "cpu.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  printf("Initializing...\n");
  CPU cpu;
  Bus bus;

  bus_write(&bus, 0x0000, 0x00);

  while (1) {
    cpu_step(&cpu, &bus);
  }
}
