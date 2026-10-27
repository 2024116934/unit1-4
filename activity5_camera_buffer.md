# ELEC2645 Unit 1.4 Activity 5: Camera Buffer Processing

An embedded camera stores an image as a block of pixel values called a **buffer**. Passing the buffer to a function allows the function to process the existing image directly without copying the whole image.

Although an image has a width and height, its pixels are often stored in a single 1D array:

```c
uint8_t image[PIXEL_COUNT];
```

`uint8_t` is an unsigned 8-bit integer with values from `0` (dark) to `255` (light), making it suitable for a grayscale pixel.

In a function parameter, these forms are equivalent:

```c
void invert_image(uint8_t image[], int length);
void invert_image(uint8_t *image, int length);
```

The `image[]` form makes it clear that the function expects an array. The pointer does not store the array length, so the number of pixels must be passed separately. Use `const` when a function should read the buffer without modifying it.

A 2D pixel position can be converted to a 1D array index using:

```c
int index = y * IMAGE_WIDTH + x;
```

## 1. Compile and run the code

Compile directly using GCC:

```bash
gcc activity5_camera_buffer.c -o activity5_camera_buffer.out
```

Alternatively, use Make:

```bash
make activity5_camera_buffer.out
```

Then run the compiled program:

```bash
./activity5_camera_buffer.out
```

## 2. The activity

Complete three functions in `activity5_camera_buffer.c`:

1. `find_brightest()` returns the largest pixel value without modifying the image.
2. `invert_image()` replaces every pixel with `255 - pixel`.
3. `threshold_image()` changes pixels below the threshold to `0` and all other pixels to `255`.

Use ordinary array indexing inside the functions. You do not need to use pointer arithmetic.

## 3. Test your work

```bash
make test5
```
