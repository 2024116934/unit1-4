#include <stdio.h>
#include "activity6_badge.h"

// 函数声明
void make_uppercase(char *letter);
void print_badge(struct Badge *badge);

int main(void)
{
    struct Badge b;
    strcpy(b.name, "elec2645 student");
    make_uppercase(b.name);
    print_badge(&b);
    return 0;
}
