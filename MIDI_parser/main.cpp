#include "handler.hpp"
#include <iostream>

int main()
{
	std::cout << "Select Mode" << std::endl;
	std::cout << "Input 0 for file reading" << std::endl;
	std::cout << "Input 1 for tick reading" << std::endl;

	static int mode{0};
	std::cin >> mode;

	switch (mode) {
	case 0:
		//Haven't written this yet
		break;
	default:
		//Loop for each chunk
		while (true) {
			int totalTick{ 0 };
			bool diffChunk{ false };
			//Loop for each tick
			do {
				int currentHex{ 0 };
				std::cout << "Please input hex value: ";
				std::cin >> std::hex >> currentHex;
				diffChunk = tickTranslate(currentHex, totalTick);
			} while (!diffChunk);
			std::cout << "Ticks: " << totalTick << std::endl;
		}
		break;
	}
	return 0;
}