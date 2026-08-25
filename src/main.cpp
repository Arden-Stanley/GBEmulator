#include "gb_memory.h"
#include <iostream>
#include <iomanip>

int main() {
	gb::Memory memory;
	memory.push(0xffff, 0xff);
	memory.print_hex(0xffff);

	return 0;
}