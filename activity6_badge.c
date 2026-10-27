#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "activity6_badge.h"

// Convert the input string to uppercase (modifies in place)
void make_uppercase(char *letter)
{
    int length = strlen(letter);
    for (int i = 0; i < length; i++)
    {
        letter[i] = toupper(letter[i]);
    }
}

// Print the badge using the Badge struct pointer
void print_badge(struct Badge *badge)
{
    badge->stars = strlen(badge->name) + 18;
    // Top border
    for (int i = 0; i < badge->stars; i++)
    {
        printf("*");
    }
    printf("\n");

    // Badge content line
    printf("* d[o_0]b %-*s *\n",
           badge->stars - 11,
           badge->name);

    // Bottom border
    for (int i = 0; i < badge->stars; i++)
    {
        printf("*");
    }
    printf("\n");
}
