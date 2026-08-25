#include "gb_memory.h"

namespace gb {
	Memory::Memory() : _memory() {}
	
	void Memory::push(uint16_t addr, uint8_t data) {
		_memory[addr - 1] = data;
	}

	uint8_t Memory::peak(uint16_t addr) const {
		return _memory[addr - 1];
	}

	void Memory::print_hex(uint16_t addr) const {
		uint8_t data = peak(addr);

		std::cout << "0x" << std::format("{:02X}", data) << std::endl;
	}

	void Memory::clear(uint16_t addr) {
		_memory[addr - 1] = 0x00;
	}
}