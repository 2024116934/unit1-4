# ELEC2645 Unit 1.4 Activity 4: Dynamic Memory

Dynamic memory allows a program to request memory while it is running. The standard library provides:

- `malloc()` to allocate memory
- `realloc()` to change the size of an existing allocation
- `free()` to release memory when it is no longer needed

For example:

```c
int *values = malloc(number_of_values * sizeof(int));

if (values == NULL) {
    // Allocation failed
}

free(values);
```

The amount of memory required depends on both the number of elements and the size of each element:

```c
number_of_elements * sizeof(element_type)
```

Dynamic allocation is common in general-purpose C. In embedded systems, fixed-size or statically allocated buffers are often preferred because their memory use is more predictable. However, it is still important to understand dynamic allocation because you will encounter it in other C programs and libraries.

## 1. Compile and run the code

Compile the program directly using GCC:

```bash
gcc activity4_dynamic_memory.c -o activity4_dynamic_memory.out
```

Alternatively, use Make:

```bash
make activity4_dynamic_memory.out
```

Then run the compiled program:

```bash
./activity4_dynamic_memory.out
```

Enter an integer between `2` and `100`.

## 2. The activity

The existing program demonstrates how to:

- allocate an array using `malloc()`
- check that the allocation succeeded
- fill the array with square numbers
- increase its size using `realloc()`
- calculate and print the sum
- release the allocated memory using `free()`

Your task is to complete the second part of the program, which creates another dynamically allocated array with half as many elements.

The starter code currently allocates enough memory for only one integer:

```c
int *array_half = malloc(1 * sizeof(int));
```

This allows the starter program to compile, but it does not provide enough memory when `half_size` is greater than `1`.

Change the allocation so that it requests enough memory for exactly `half_size` integers:

```c
int *array_half = malloc(half_size * sizeof(int));
```

You must then:

1. check that the allocation succeeded
2. fill the half-sized array with the required square values
3. calculate the sum of the half-sized array
4. print the sum using the existing `printf()` statement
5. release the half-sized array using `free()`

For an input of `10`, the half-sized array contains five elements:

```text
0 1 4 9 16
```

The final result should therefore include:

```text
Half array sum = 30
```

## 3. Test your work

Run:

```bash
make test4
```

ELEC2645 Bot tests the program using several different array sizes. Keep the final output statement unchanged so the test can find the result.
