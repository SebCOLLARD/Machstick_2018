/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** Display string
*/

#include "my.h"

void my_putstr(char *str)
{
    int i = 0;

    while (str [i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    };
}
