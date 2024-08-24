#include <exception>
#include <stdexcept>
#include "RGBPixel.h"

RGBPixel::RGBPixel() : r(0), g(0), b(0) {}

RGBPixel::RGBPixel(unsigned int r, unsigned int g, unsigned int b) : r(r), g(g), b(b) {}

RGBPixel::~RGBPixel() = default;

unsigned int RGBPixel::getBrightness() const {
    return (r + g + b) / 3;
}

unsigned int& RGBPixel::operator[](const char channel) {
    switch (channel) {
        case 'r': return r;
        case 'g': return g;
        case 'b': return b;
        default: throw std::invalid_argument("Invalid channel");
    }
}