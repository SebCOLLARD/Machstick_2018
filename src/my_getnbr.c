/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** getnbr
*/

#include <unistd.h>
#include <stdio.h>

int my_getnbr(char *str)
{
    int i = 0;
    int a = 0;

    while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57) {
        a = a + str[i] - 48;
        a = a * 10;
        i = i + 1;
    }
    a = a / 10;
    return (a);
}
