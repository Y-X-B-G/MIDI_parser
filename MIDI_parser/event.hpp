#pragma once
#include <fstream>
#include <string>

// may need to fix this file later. this is for channel messages 8n-En NOT meta events.
struct eventReturn {
    std::string type;
    std::string dataname1;
    std::string dataname2;
    int databyte1;
    int databyte2; // set to -1 if only 1 data byte possibly?
};
