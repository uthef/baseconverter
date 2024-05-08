#ifndef BASECONVERTER_H
#define BASECONVERTER_H

#include <string>

class BaseConverter {
public:
    enum Base {
        HEX = 16, DEC = 10, OCT = 8, BIN = 2
    };

    static std::string transform(std::string value, Base origBase, Base targetBase);
private:
    static unsigned long convertToDecimal(const char* hex, size_t n, unsigned int base);
    static std::string convertDecimal(unsigned long decimal, unsigned int base);
};

#endif // BASECONVERTER_H
