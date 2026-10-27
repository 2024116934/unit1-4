# ELEC2645 Unit 1.4 Activity 1: Pointers

Pointers are variables that store the memory address of another variable. The `&` operator obtains the address of a variable, while dereferencing a pointer with `*` lets you read or modify the value stored at that address.

Although this example is deliberately simple, pointers become particularly useful when functions need to modify existing data directly, such as processing a camera image buffer without copying it.

```c
int x = 5;
int *p = &x;

*p = 42;
printf("x = %d\n", x);
```

The `%p` format specifier displays an address:

```c
printf("### Address of x: %p\n", (void *)&x);
printf("### p stores:     %p\n", (void *)p);
```

After `p = &x`, these addresses should match. The expression `*p` accesses the value stored at that address. The exact addresses may change each time the program runs, so lines beginning with `###` are shown to you but ignored by ELEC2645 Bot.

## 1. Compile and run the code

Compile directly using GCC:

```bash
gcc activity1_pointers.c -o activity1_pointers.out
```

Alternatively, use Make:

```bash
make activity1_pointers.out
```

Then run the program:

```bash
./activity1_pointers.out
```

## 2. The activity

The starter program uses one pointer, `p`, to access three variables: `a`, `b` and `c`.

Follow the steps in `activity1_pointers.c` to:

- change `a` to `60` using `p`;
- change `b` to `108` using `p`;
- swap the values of `a` and `c` using pointers.

The final line should be:

```text
Final values: a = 35, b = 108, c = 60
```

## 3. Test your work

```bash
make test1
```
