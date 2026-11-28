#include "handler.hpp"

[[nodiscard]] tickReturn tickHandler(std::ifstream &file) {
	/*
	@params
		std::ifstream file - A MIDI filesteam with a tick byte ready to read
	@returns
		tickReturn - A struct with the total number of ticks for the current chunk and the number of bytes read
	*/
	uint8_t currentByte;
	tickReturn ticks{};
	do {
		file.read(reinterpret_cast<char*>(&currentByte), sizeof(currentByte));
		ticks.bytesRead += sizeof(currentByte);
		ticks.ticks <<= 7;
		ticks.ticks += static_cast<int>(0b0111'1111 & currentByte);
	} while (currentByte & 0b1000'0000);

	return ticks; //Consider passing in a reference this causes a copy to be made
}

[[nodiscard]] bool tickTranslate(const int rawData, int &tick) {
	/*
		@params
			int rawData - Value representing the raw delay data from a MIDI file 
			int tick - Current nunber of ticks for the chunk
		@returns
			bool -  An boolean that informs the caller if the byte that was just read 
					represents the end of the tick sequence (ie returns true if the next byte is no longer tick data) 
	*/
	tick <<= 7;
	tick += static_cast<int>(0b0111'1111 & rawData);

	if (rawData & 0b1000'0000) {
		return false;
	};

	return true;
};