// ELEC2645 Unit 1.4 Activity 6 - Debug Practice
// This multi-file program should read a name, convert it to uppercase
// and print an ELEC2645 Bot-style name badge.

#include <stdio.h>
#include "activity6_badge.h"

int main(void)
{
    struct Badge badge = {
        .name = "",
        .stars = 0
    };

    printf("Enter your name: ");

    // Is this input safe for the size of the name array?
    scanf("%s", badge.name);

    // This should modify the whole name in place.
    // Is the correct value being passed to the function?
    make_uppercase(badge.name[0]);

    // The function needs the address of the badge.
    print_badge(badge);

    return 0;
}
