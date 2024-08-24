#include "GreyscalePixel.h"
#include <exception>
#include <stdexcept>

GreyscalePixel::GreyscalePixel() : intensity(0) {}

GreyscalePixel::GreyscalePixel(unsigned int intensity) : intensity(intensity) {}

GreyscalePixel::~GreyscalePixel() = default;

unsigned int GreyscalePixel::getBrightness() const {
    return intensity;
}

unsigned int& GreyscalePixel::operator[](const char channel) {
    if (channel == 'i') {
        return intensity;
    } else {
        throw std::invalid_argument("Invalid channel");
    }
}