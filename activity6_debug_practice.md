# ELEC2645 Unit 1.4 Activity 6: Debug Practice


But there are some problems with the code! We have implemented structs, functions, and user input, but something is not quite right. Your task is to debug the code so that it works as expected. Happy bug hunting!

## 1. Compile and run the code

Both C source files must be compiled together which is easiest using Make which already has the extra compiler flags to help find problems:

```bash
make activity6_debug_practice.out
```

Once the program compiles, run it using:

```bash
./activity6_debug_practice.out
```

## 2. The activity

The corrected program should:

1. read a name safely;
2. convert the complete name to uppercase in place;
3. calculate the required badge width;
4. print matching top and bottom borders;
5. print the uppercase name inside the badge.

The starter code contains problems involving:

- function prototypes;
- arrays passed to functions;
- modifying a string in place;
- structure pointers;
- the `->` operator;
- the address operator `&`;
- input buffer sizes;
- loop boundaries.

Start with the compiler messages. Once the code builds, run it and inspect the badge output carefully.

## 3. Test your work

```bash
make test6
```
