#include "handler.hpp"

int main() // testing commit
{
	return 0;
}

[[nodiscard]] tickReturn tickHandler(std::ifstream &file) {
	uint8_t currentByte;
	tickReturn ticks{};
	do {
		file.read(reinterpret_cast<char*>(&currentByte), sizeof(currentByte));
		ticks.bytesRead += sizeof(currentByte);
		ticks.ticks <<= 7;
		ticks.ticks += static_cast<int>(0b0111'1111 & currentByte);
	} while (currentByte & 0b1000'0000);

	return ticks; //Consider passing in a reference this causes a copy to be made
};