// ELEC2645 Unit 1.4 Activity 1 - Pointers
// Example using only one pointer to change values of multiple variables
#include <stdio.h>
int main(void)
{
    int a = 10;
    int b = 20;
    int c = 30;
    printf("Starting values: a = %d, b = %d, c = %d\n", a, b, c);
    // Lines beginning with ### show changing memory addresses.
    // ELEC2645 Bot ignores these because addresses vary each time the program runs.
    // %p expects a general-purpose void pointer when printing an address. 
    // So we need to cast the addresses to (void *) before printing to stop compiler warnings. 
    // We dont need to understand this yet, just know this is how to print addresses in C.
    printf("### Address of a: %p\n", (void *)&a);
    printf("### Address of b: %p\n", (void *)&b);
    printf("### Address of c: %p\n", (void *)&c);
    int *p = NULL; // start safe
    // Point to a
    p = &a;
    printf("### p stores:     %p\n", (void *)p);
    printf("### &a gives:     %p\n", (void *)&a);
    printf("### *p gives:     %d\n", *p);
    printf("p points to a: *p = %d\n", *p);
    *p = 15;
    printf("a changed to %d\n", a);
    // Point to b
    p = &b;
    printf("### p stores:     %p\n", (void *)p);
    printf("### &b gives:     %p\n", (void *)&b);
    printf("### *p gives:     %d\n", *p);
    printf("p now points to b: *p = %d\n", *p);
    *p = 25;
    printf("b changed to %d\n", b);
    // Point to c
    p = &c;
    printf("### p stores:     %p\n", (void *)p);
    printf("### &c gives:     %p\n", (void *)&c);
    printf("### *p gives:     %d\n", *p);
    printf("p now points to c: *p = %d\n", *p);
    *p = 35;
    printf("c changed to %d\n", c);
    printf("Values after changes: a = %d, b = %d, c = %d\n", a, b, c);


    // ========= Step 1: change a=60, b=108 with pointer p =========
    printf("Values before swap: a = %d, b = %d, c = %d\n", a, b, c);
    p = &a;
    *p = 60;
    p = &b;
    *p = 108;


    // ========= Step 2: swap a and c using the same pointer p =========
    int temp;
    p = &a;
    temp = *p;    // temp = a
    p = &c;
    *(&a) = *p;   // a = c
    *p = temp;    // c = temp（原来的a）


    // Print the final values of a, b and c
    printf("Final values: a = %d, b = %d, c = %d\n", a, b, c);
    return 0;
}
