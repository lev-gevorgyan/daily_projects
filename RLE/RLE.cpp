#include "RLE.h"

std::string RLE::encode(const std::string & str) {
    std::string encoding;
    int count{};

    for (int i = 0; str[i]; ++i)
    {
        count = 1;
        while (str[i] == str[i + 1]) {
            ++count, ++i;
        }
        if(1 == count) encoding += str[i];
        else encoding += std::to_string(count) + str[i];
    }

    return encoding;
}

std::string RLE::decode(const std::string & str) {
    const size_t ASCII_0{48};
    const size_t ASCII_9{57};

    std::string decoding;

    for (size_t i{}; i < str.size(); ++i) {
        std::string count;
        while(str[i] >= ASCII_0 && str[i] <= ASCII_9) {
            count += str[i++];
        }
        if(!count.size()) decoding += str[i];
        size_t iCount{};
        iCount = std::atoi(count.c_str());
        for (int j{}; j < iCount; ++j) {
            decoding += str[i];
        }
    }

    return decoding;
}