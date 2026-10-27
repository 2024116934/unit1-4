# ELEC2645 Unit 1.4 Activity 3: Pointers with Structs

Pointers to structures let you refer to a structure by its address rather than copying the whole object. When `p` points to a structure, its fields can be accessed using `p->field`, which is shorthand for `(*p).field`.

```c
struct Point { int x, y; };

struct Point pt = { .x = 3, .y = 4 };
struct Point *p = &pt;

printf("%d %d\n", p->x, p->y);
```

Passing a structure by pointer allows a function to inspect or modify the original structure without copying the entire structure.

Lines beginning with `###` provide extra explanation when the program runs but are ignored by ELEC2645 Bot.

## 1. Compile and run the code

Compile directly using GCC:

```bash
gcc activity3_pointers_structs.c -o activity3_pointers_structs.out
```

Alternatively, use Make:

```bash
make activity3_pointers_structs.out
```

Then run the program:

```bash
./activity3_pointers_structs.out
```

## 2. The activity

The program defines several snacks and demonstrates how pointers and the `->` operator can access their fields.

Follow the steps in `activity3_pointers_structs.c` to:

- read through the existing pointer and structure examples
- point `p` to the existing `pocky` structure and print it
- create `apply_discount()`, which receives a `struct Snack *` and a fixed discount in pence
- subtract 10p from Pocky's price and print it again
- point `p` to Hobnob, subtract 10p and print it again.

The prototype should be:

```c
void apply_discount(struct Snack *s, int discount_pence);
```

Inside the function, use `->` to modify the original snack:

```c
s->price_pence = s->price_pence - discount_pence;
```

The final checked lines should include:

```text
Snack: Pocky           | Type: biscuit  | Price: £1.40
Snack: Hobnob          | Type: biscuit  | Price: £1.09
```

## 3. Test your work

```bash
make test3
```
