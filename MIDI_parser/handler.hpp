#pragma once
#include <fstream>

struct tickReturn {
	int ticks;
	int bytesRead;
};

[[nodiscard]] tickReturn tickHandler(std::ifstream &file) {};