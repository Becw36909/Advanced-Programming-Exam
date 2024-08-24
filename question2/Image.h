#ifndef COSC1076_A3_IMAGE_H
#define COSC1076_A3_IMAGE_H

#include <vector>

#include "Pixel.h"
#include "RGBPixel.h"
#include "GreyscalePixel.h"

// Template class for Image
template<typename T>

class Image{
public:    
    //Construct an image with nRows (number of rows) and
    // nCols (number of columns).
    Image(int nRows, int nCols);

    //Deconstructor: should clear the image
    ~Image();

    // Get the pixel at (row, col)
    T& get(int row, int col);

    // Set the pixel at (row, col)
    void set(int row, int col, const T& pix);

private:

    // 2D vector to store the image
    std::vector<std::vector<T>> img;
    
};

#include "Image.cpp" // Include the implementation file

#endif //COSC1076_A3_IMAGE_H