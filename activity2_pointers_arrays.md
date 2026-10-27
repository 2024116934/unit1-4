# ELEC2645 Unit 1.4 Activity 2: Pointers with Arrays

When an array is passed to a function, the function receives the address of its first element. This allows the function to read or modify the original array, but the pointer does not contain the array length, so the length must be passed separately.

In a function parameter, these two forms are equivalent:

```c
void process(int data[], int length); // this one is more obvious that an array is expected
void process(int *data, int length);
```

Use `const` when a function should read an array without modifying it:

```c
void minmax(const int data[], int length, int *out_min, int *out_max);
```

## 1. Compile and run the code

Compile directly using GCC:

```bash
gcc activity2_pointers_arrays.c -o activity2_pointers_arrays.out
```

Alternatively, its better to use Make:

```bash
make activity2_pointers_arrays.out
```

Then run the compiled program:

```bash
./activity2_pointers_arrays.out
```

## 2. The activity

First, follow `minmax()` to understand:

- why the array length is passed separately;
- why pointers are used for the minimum and maximum outputs;
- why `const` is used for the input array.

Then add a function called `square_array()` that modifies every array element in place. Call it before using `minmax()` for the second time.

The final output should include:

```text
Original Array: min = -10, max = 42
Squared Array: min = 0, max = 1764
```

Modifying an array in place avoids copying all of its data, which is useful for large buffers like those we will use for the LCD displays later in the course.

## 3. Test your work

```bash
make test2
```
