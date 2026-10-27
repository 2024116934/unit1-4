// structs_arrow_price.c
#include <stdio.h>
#define MAX_NAME 24
#define MAX_TYPE 16
struct Snack
{
   char name[MAX_NAME];
   char type[MAX_TYPE]; // e.g. "biscuit", "crisps", "cake" an Enum would be better but we are keeping it simple
   int price_pence;     // price in pence, e.g. 125 = £1.25
};
// Function to print snack details given a pointer to a Snack struct
// using 'const' because we are not modifying the snack here
void print_snack(const struct Snack *s);
// Function to apply a fixed discount in pence to a snack via pointer
// Prototype
void apply_discount(struct Snack *s, int discount_pence);

int main(void)
{
   // Step 1: follow the code through to understand how it uses structs, pointers, functions
   // and the '->' operator
   // Direct objects (use '.' because these are not pointers).
   // Initialised via designated initialisers; would need strncpy to change the text later.
   struct Snack hobnob = {
       .name = "Hobnob",
       .type = "biscuit",
       .price_pence = 99};
   struct Snack crisps = {
       .name = "Salt & Vinegar",
       .type = "crisps",
       .price_pence = 125};
   struct Snack cake = {
       .name = "Victoria Sponge",
       .type = "cake",
       .price_pence = 250};
   // Create a pointer and point it at hobnob first
   struct Snack *p = &hobnob;
   // Lines beginning with ### are useful explanations but are ignored by ELEC2645 Bot.
   puts("### Welcome to the Snack Inspector (Struct edition) -d[o_0]b");
   puts("### First, the pointer inspects what it points at:");
   print_snack(p);
   // Modify through the pointer
   p->price_pence += 20; // a cheeky price rise
   puts("### After a price change via pointer:");
   print_snack(p);
   // Repoint to a different object
   p = &crisps;
   puts("### Pointer retargeted to a different snack:");
   print_snack(p);
   // Repoint again to cake and apply a fixed price reduction
   p = &cake;
   p->price_pence -= 50; // special offer
   puts("### Now pointing at cake with a special offer applied:");
   print_snack(p);
   // Show '.' vs '->' side by side
   puts("### Direct access (.) vs pointer access (->):");
   printf("### Direct:  hobnob.name = %s, hobnob.price = £%d.%02d\n",
          hobnob.name, hobnob.price_pence / 100, hobnob.price_pence % 100);
   printf("### Pointer: p->name     = %s, p->price  = £%d.%02d\n",
          p->name, p->price_pence / 100, p->price_pence % 100);
   // Step 2: A new struct Snack object for "Pocky" has already been created
   puts("### Adding a new snack 'Pocky':");
   struct Snack pocky = {
       .name = "Pocky",
       .type = "biscuit",
       .price_pence = 150};
   // Step 3: Point p to the new "Pocky" object and print its details
   p = &pocky;
   print_snack(p);
   // Step 4: Create a function to subtract a fixed discount in pence
   // from a snack via a pointer. Apply a 10p discount to Pocky,
   // then print the details again to show the reduced price.
   apply_discount(p, 10);
   puts("### After applying a 10p discount to Pocky:");
   print_snack(p);
   // Step 5: Apply a 10p discount to Hobnob via pointer and print its details
   p = &hobnob;
   apply_discount(p, 10);
   puts("### After applying a 10p discount to Hobnob:");
   print_snack(p);
   return 0;
}
// Function definition to print snack details
void print_snack(const struct Snack *s)
{
   // Using -> because s is a pointer
   // -15 and -8 in the format specifiers are for alignment
   // this means left-align within a field of that width
   // %02d ensures two digits with leading zero if needed i.e. 9 -> 09
   printf("Snack: %-15s | Type: %-8s | Price: £%d.%02d\n",
          s->name, s->type, s->price_pence / 100, s->price_pence % 100);
}
// apply_discount() function definition
void apply_discount(struct Snack *s, int discount_pence)
{
    s->price_pence -= discount_pence;
}
