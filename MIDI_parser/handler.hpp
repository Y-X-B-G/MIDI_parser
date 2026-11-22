#pragma once
#include <ios>

struct tickReturn {
	int ticks;
	int bytesRead;
};

[[nodiscard]] tickReturn tickHandler(std::ifstream &file) {};