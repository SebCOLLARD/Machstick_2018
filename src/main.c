/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main function
*/

#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include "my.h"

int main(int ac, char **av)
{
    if (ac < 3 || ac > 3)
        return 84;
    if (error_handling(av) == 0)
        return 84;
    srandom(time(0));
    return endless_loop(my_getnbr(av[1]), my_getnbr(av[2]));
}
