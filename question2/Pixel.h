#ifndef COSC1076_A3_PIXEL_H
#define COSC1076_A3_PIXEL_H

//minimum and maximum values for pixel
#define PIX_MIN 0
#define PIX_MAX 255
/*                                           */
/* This is an abstract class that describe   */
/* the general concepts of a pixel           */
/*                                           */

class Pixel{
public:    

    // Pure virtual function to get the brightness of the pixel
    virtual unsigned int getBrightness() const = 0;

    // Pure virtual function to access a channel in the pixel
    virtual unsigned int& operator[](const char channel) = 0;

    virtual ~Pixel() = default; // Virtual destructor for polymorphic base class

private:
    
};

#endif //COSC1076_A3_PIXEL_H