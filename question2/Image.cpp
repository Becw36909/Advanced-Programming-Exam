#include <exception>
#include <stdexcept>
#include "Image.h"

// Constructor
template<typename T>
Image<T>::Image(int nRows, int nCols) : img(nRows, std::vector<T>(nCols)) {}

// Destructor
template<typename T>
Image<T>::~Image() = default;

// Get the pixel at (row, col)
template<typename T>
T& Image<T>::get(int row, int col) {
    // Use size_type for comparison
    typename std::vector<std::vector<T>>::size_type numRows = img.size();
    typename std::vector<T>::size_type numCols = img.empty() ? 0 : img[0].size();
    
    if (row < 0 || col < 0 || static_cast<size_t>(row) >= numRows || static_cast<size_t>(col) >= numCols) {
        throw std::out_of_range("Index out of range");
    }
    return img[row][col];
}

// Set the pixel at (row, col)
template<typename T>
void Image<T>::set(int row, int col, const T& pix) {
    // Use size_type for comparison
    typename std::vector<std::vector<T>>::size_type numRows = img.size();
    typename std::vector<T>::size_type numCols = img.empty() ? 0 : img[0].size();
    
    if (row < 0 || col < 0 || static_cast<size_t>(row) >= numRows || static_cast<size_t>(col) >= numCols) {
        throw std::out_of_range("Index out of range");
    }
    img[row][col] = pix;
}

// Explicit instantiations (if needed)
// template class Image<RGBPixel>;
// template class Image<GreyscalePixel>;