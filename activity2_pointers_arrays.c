// ELEC2645 Unit 1.4 Activity 2 - Pointers and Arrays

#include <stdio.h>

// Function prototype for minmax
// the 'const' keyword indicates that the function will not modify the input array, this is a good practice but not strictly necessary
// data[] is equivalent to *data in function parameters, we are using array notation for clarity
void minmax(const int data[], int n, int *out_min, int *out_max);

// Function prototype for square_array would go here
// remember to use 'void' return type since we are modifying the array in place
// we do not need 'const' since we will be changing the array elements
// and we must pass the size of the array as well


int main(void)
{
    int arr[] = { 7, -3, 12, 0, 5, 5, -10, 42, 3 };
    int len = sizeof arr / sizeof arr[0];

    int minv = 0, maxv = 0;

    minmax(arr, len, &minv, &maxv);

    printf("Original Array: min = %d, max = %d\n", minv, maxv);
   // step 1 : understand how the minmax function works and why we pass pointers for output, and why we must pass the size of the array

   // Step 2: add square_array() to modify each element in place,
   // then call it before calculating the new minimum and maximum.


   // step 3 : call minmax again on the modified array

   minmax(arr, len, &minv, &maxv);

   // step 4 : print the new min and max values after squaring

   printf("Squared Array: min = %d, max = %d\n", 0, 0); // replace 0, 0 with actual minv and maxv when ready


    return 0;
}


// Finds the minimum and maximum values in an array of integers.
// Parameters:
//   data: pointer to the first element of the integer array - constant to prevent modification
//   n: number of elements in the array
//   out_min: pointer to where min will be stored
//   out_max: pointer to where max will be stored
void minmax(const int data[], int n, int *out_min, int *out_max)
{
   // Validate input - check for non postive size and null pointers
   if (n == 0 || data == NULL || out_min == NULL || out_max == NULL) {
        printf("minmax: invalid input\n");
        return;
    }

    // we know the array has at least one element but we dont know the array size
    // if we tried sizeof(data) here, it would give us the size of the pointer, not the array
    int mn = data[0];
    int mx = data[0];

    // we do not know the size of the array within the function,
    // so we must rely on the provided size parameter n
    for (int i = 1; i < n; ++i) {
        if (data[i] < mn) mn = data[i]; // update minimum if current element is smaller
        if (data[i] > mx) mx = data[i];
    }

    // store the results in the provided output pointers
    // we cant return multiple values directly, so we use pointers to modify the caller's variables
    *out_min = mn;
    *out_max = mx;
}



// Squares each element of an integer array in place.
// Parameters:
//   data: pointer to the first element of the integer array
//   n: number of elements in the array
