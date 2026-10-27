// ELEC2645 Unit 1.4 Activity 5 - Camera Buffer Processing
#include <stdio.h>
#include <stdint.h> // Needed for the uint8_t type
// Define the dimensions of the image buffer.
// This example uses a small 4 x 3 image containing 12 pixels.
//
// #define tells the preprocessor to replace these names with their
// values before the program is compiled. This allows the image
// dimensions to be changed in one place.
#define IMAGE_WIDTH 4
#define IMAGE_HEIGHT 3
#define PIXEL_COUNT (IMAGE_WIDTH * IMAGE_HEIGHT)
// Function prototypes.
//
// The pointer does not contain the array length, so the number of
// pixels must also be passed to each function.
//
// const means that the function can read the image but cannot
// change its pixel values.
void print_image(const uint8_t image[], int length);
uint8_t find_brightest(const uint8_t image[], int length);
// These functions do not use const because they modify the
// original image buffer.
void invert_image(uint8_t image[], int length);
void threshold_image(uint8_t image[], int length, uint8_t threshold);
int main(void)
{
    // Create a sample image buffer with 12 pixels.
    //
    // Although the image is 4 x 3, its pixels are stored in one
    // continuous 1D array in memory. Each row is shown on a new
    // line below to make the 2D arrangement easier to see.
    uint8_t image[PIXEL_COUNT] = {
        0, 25, 80, 120,
        150, 180, 200, 220,
        240, 250, 100, 50
    };
    printf("Original image:\n");
    print_image(image, PIXEL_COUNT);
    // This function reads the image but does not modify it.
    uint8_t brightest = find_brightest(image, PIXEL_COUNT);
    printf("Brightest pixel: %u\n", brightest);
    // This function modifies the existing image buffer directly.
    invert_image(image, PIXEL_COUNT);
    printf("Inverted image:\n");
    print_image(image, PIXEL_COUNT);
    // Apply a threshold of 100 to the already inverted image.
    threshold_image(image, PIXEL_COUNT, 100);
    printf("Threshold image:\n");
    print_image(image, PIXEL_COUNT);
    return 0;
}
void print_image(const uint8_t image[], int length)
{
    for (int i = 0; i < length; i++)
    {
        // %u is used to print unsigned integers such as uint8_t.
        printf("%u", image[i]);
        // Add a space between pixels, but not after the final pixel.
        if (i < length - 1)
        {
            printf(" ");
        }
    }
    printf("\n");
}

// Find and return the largest pixel value.
uint8_t find_brightest(const uint8_t image[], int length)
{
    uint8_t max_val = image[0];
    for(int i = 1; i < length; i++)
    {
        if(image[i] > max_val)
        {
            max_val = image[i];
        }
    }
    return max_val;
}

// new pixel = 255 - old pixel
void invert_image(uint8_t image[], int length)
{
    for(int i = 0; i < length; i++)
    {
        image[i] = 255 - image[i];
    }
}

// Pixels < threshold → 0
// Pixels >= threshold → 255
void threshold_image(uint8_t image[], int length, uint8_t threshold)
{
    for(int i = 0; i < length; i++)
    {
        if(image[i] >= threshold)
        {
            image[i] = 255;
        }
        else
        {
            image[i] = 0;
        }
    }
}
