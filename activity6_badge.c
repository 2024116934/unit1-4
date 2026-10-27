#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "activity6_badge.h"

// This function should modify the original name string.
// I think the parameter type is wrong, and the loop is not quite right either...
void make_uppercase(char letter)
{
    int length = strlen(letter);


    for (int i = 0; i <= length; i++)
    {
        letter[i] = toupper(letter[i]);
    }
}

// This function receives a pointer to the original Badge structure.
// There are several problems with how its fields are accessed.
void print_badge(struct Badge *badge)
{
    badge.stars = strlen(badge.name) + 18;

    // Print the top border.
    for (int i = 0; i <= badge.stars; i++)
    {
        printf("*");
    }

    printf("\n");

    // Print the name inside the badge.
    printf("* d[o_0]b %-*s *\n",
           badge.stars - 11,
           badge.name);

    // Print the bottom border.
    for (int i = 0; i < badge.stars; i++)
    {
        printf("*");
    }

    printf("\n");
}
