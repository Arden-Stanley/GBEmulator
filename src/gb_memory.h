#pragma once

#include <array>
#include <cstdint>
#include <iostream>
#include <format>

constexpr uint16_t NUM_ADDRS = 0xFFFF;

namespace gb {
	class Memory {
	public:
		Memory();
		~Memory() = default;
		void push(uint16_t addr, uint8_t data);
		uint8_t peak(uint16_t addr) const;
		void print_hex(uint16_t addr) const;
		void clear(uint16_t addr);
	private:
		std::array<uint8_t, NUM_ADDRS> _memory;
	};
}