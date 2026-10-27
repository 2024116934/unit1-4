// ELEC2645 Unit 1.4 Activity 4 Dynamic Memory Allocation in C
// This program demonstrates dynamic memory allocation, resizing, and deallocation.

#include <stdio.h>
#include <stdlib.h> // For malloc, realloc, free

int main(void) {

    // Step 1: Follow the code through to understand how dynamic memory allocation works and how the array is created and then resized

    // first get number of elements from the user
    // check that they are valid - an integer between 2 and 100

    // you can check scanf("%d", &n) return value to see if input was valid
    // it will be 1 if valid (in this case an integer was read), 0 if not
    // 
    // check that the number is positive and also check that the number is not too large 
    // to avoid malloc failing - we could create 1TB array by accident!

    int n;

    printf("Enter number of elements: ");

    int scanf_result = scanf("%d", &n);

    if (scanf_result != 1)
    {
        printf("Invalid input.\n");
        return 1; // Exit with an error code
    }

    if (n < 2 || n > 100)
    {
        printf("Please enter a number between 2 and 100.\n");
        return 1; // Exit with an error code
    }

    // allocate memory for n integers
    // malloc returns a pointer to the allocated memory which is the size we requested
    // int *array means we want a pointer to an integer which we are calling array
    // malloc(n * sizeof(int)) allocates enough memory for n integers as we specify the size in bytes

    int *array = malloc(n * sizeof(int));
    // always check that malloc succeeded, pointer will be NULL if it failed (which works like false in conditions)
    if (!array) {
        printf("Initial malloc failed.\n");
        return 1; // exit with error code
    }

    // Fill this array with square of the index i.e array[0] = 0, array[1] = 1, array[2] = 4, etc.
    for (int i = 0; i < n; ++i) {
        array[i] = i * i;
    }

    // Sum original array
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += array[i];
    }

    // Print original array 
    printf("\nOriginal array:\n");
    for (int i = 0; i < n; ++i) {
        printf("array[%d] = %d\n", i, array[i]);
    }

    // Print sum of original array
    printf("Sum = %d\n", sum);

    // Resize the array to double the size
    int new_size = n * 2;

    // this works in a similar way to malloc but resizes the existing memory block
    // it returns a pointer to the resized memory block which may be at a different location
    // If realloc() fails, it returns NULL and leaves the original block unchanged.
    // Use a temporary pointer so that we do not lose the address stored in array.
    // and it doesnt overwrite any existing data in the original block
    int *temp = realloc(array, new_size * sizeof(int));

    // check realloc succeeded and if not free original memory and exit
    if (!temp) {
        printf("Realloc failed.\n");
        free(array); // release original memory to avoid memory leak
        return 1;
    }
    // point array to the resized memory block
    array = temp;

    // Fill new part with with squares too
    for (int i = n; i < new_size; ++i) {
        array[i] = i * i;
    }

    // Sum this resized array
    int new_sum = 0;
    for (int i = 0; i < new_size; ++i) {
        new_sum += array[i];
    }

    // Print resized array 
    printf("\nResized array:\n");
    for (int i = 0; i < new_size; ++i) {
        printf("array[%d] = %d\n", i, array[i]);
    }

    // Print sum of resized array
    printf("New sum = %d\n", new_sum);


    // Step 2: Follow the pattern above to create a new array which is half the size of the original array i.e n/2

    int half_size = n / 2;
    int half_sum = 0;

    // Allocate memory for half the size using malloc.
    // This currently allocates enough memory for the smallest possible
    // half-sized array of 1.
    //
    // Change it so that it allocates exactly enough memory for
    // half_size integers.
    int *array_half = malloc(1 * sizeof(int));

    // Remember to ALWAYS check that malloc succeeded.
    if (array_half == NULL)
    {
        printf("Half array malloc failed.\n");
        free(array);
        return 1;
    }

    // Step 3: Fill this new "half" array with the squares of the indices
    // as before and compute the sum.
    // You can copy from the original array or recalculate.


    // Print half array
    printf("\nHalf array:\n");
    for (int i = 0; i < half_size; ++i) {
        printf("array_half[%d] = %d\n", i, array_half[i]);
    }

    // Step 4: Print the sum of this half array.
    // This line must be exact for the automated tests to work.
    printf("Half array sum = %d\n", half_sum);

    // Free the allocated memory when we are finished with it.
    // YOU MUST ALWAYS DO THIS TO AVOID MEMORY LEAKS.
    free(array);

    // Remember to free the half array too!


    return 0;
}