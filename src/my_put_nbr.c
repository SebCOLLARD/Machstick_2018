/*
** EPITECH PROJECT, 2018
** my_putnbr
** File description:
** display nbr
*/

#include "my.h"

void my_put_nbr(int nb)
{
    int index = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
        my_put_nbr(nb);
    }
    else if ((nb / 10 ) > 0) {
        index = nb % 10;
        my_put_nbr(nb / 10);
        my_putchar(index + 48);
    }
    else
        my_putchar((nb % 10) + 48);
}
