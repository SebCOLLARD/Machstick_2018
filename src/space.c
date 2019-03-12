/*
** EPITECH PROJECT, 2019
** space.c
** File description:
** calcul and print sapce for the map
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"

int space_r(int line_max, int line)
{
    int space_r = 0;
    int matches_max = line_max * 2 - 1;
    int matches_origin = line * 2 - 1;

    space_r = (matches_max - matches_origin) / 2;
    return space_r - 1;
}

int space_l(int line, int matches, int space_r)
{
    int space_l = 0;

    space_l = (line * 2 - 1) - space_r - matches;
    return space_l;
}

void print_space(int space)
{
    while (space > 0) {
        write(1, " ", 1);
        space--;
    }
}
