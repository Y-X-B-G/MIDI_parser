#pragma once
#include <fstream>
#include <iostream>

struct tickReturn {
	int ticks;
	int bytesRead;
};

[[nodiscard]] tickReturn tickHandler(std::ifstream &file);

[[nodiscard]] bool tickTranslate(const int rawData, int &tick);