#ifndef ACTIVITY6_BADGE_H
#define ACTIVITY6_BADGE_H

#define MAX_NAME 20

struct Badge
{
    char name[MAX_NAME];
    int stars;
};

// There is a problem with the parameter type.
void make_uppercase(char letter);

// There is a problem with this prototype.
void print_badge(struct Badge badge);

#endif
