#include "baseconverter.h"
#include <string>


std::string BaseConverter::transform(std::string value, Base origBase, Base targetBase) {
    if (origBase == targetBase) {
        auto val = std::to_string(std::stoul(value));;
        return val;
    }

    unsigned long decimal = origBase == 10 ? std::stoul(value) : convertToDecimal(value.c_str(), value.length(), origBase);

    return convertDecimal(decimal, targetBase);
}

unsigned long BaseConverter::convertToDecimal(const char* hex, size_t n, unsigned int base) {
    unsigned long sum = 0;
    unsigned long j = 1;

    for (size_t i = n; i > 0; i--) {
        char chr = std::tolower(*(hex + (i - 1)));

        if (std::isspace(chr)) continue;

        int num = chr - '0';

        if (num >= 0 && num <= base - 1) {
            if (j == 0) return 0;
            sum += num * j;
            j *= base;
            continue;
        }
        else if (base <= 10) return 0;

        num = chr - 'a' + 10;

        if (num < 10 || num > base - 1) {
            return 0;
        }

        if (j == 0) return 0;
        sum += num * j;
        j *= base;
    }


    return sum;
}

std::string BaseConverter::convertDecimal(unsigned long decimal, unsigned int base) {
    std::string str;

    int i = 0;

    while (decimal > 0) {
        i++;
        auto rem = decimal % base;

        if (rem < 10) {
            str.insert(str.begin(), '0' + rem);

            if (base == 2 && i == 4) {
                i = 0;
                str.insert(str.begin(), ' ');
            }
        }
        else if (base > 10) {
            str.insert(str.begin(), 'a' + rem - 10);
        }

        decimal /= base;
    }

    if (base == 2 && (i != 0 || str.length() == 0)) {
        while (i != 4) {
            i++;
            str.insert(str.begin(), '0');
        }

        return str;
    }

    if (str.length() == 0) {
        str = "0";
    }

    return str;
}
