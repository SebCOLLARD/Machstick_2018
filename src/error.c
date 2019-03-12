/*
** EPITECH PROJECT, 2019
** error.c
** File description:
** error handling for matchstick
*/

#include <unistd.h>
#include <stdio.h>
#include "my.h"

int error_line(int line, char *line1)
{
    int nbr = 0;
    int idx = 0;

    while (line1[idx] != '\n') {
        if (line1[idx] < 48 || line1[idx] > 57) {
            my_putstr("Error: invalid output (positive number expected)\n");
            return 0;
        }
        idx++;
    }
    nbr = my_getnbr(line1);
    if (nbr > line || nbr < 1) {
        my_putstr("Error: this line is out of range\n");
        return 0;
    }
    return 1;
}

int error_match_ext(int nbr, int **game, int line)
{
    if (nbr > game[0][line - 1]) {
        my_putstr("Error: not enough matches on this line\n");
        return 0;
    }
    game[0][line - 1] = game[0][line - 1] - nbr;
    return 1;
}

int error_match(int match_mv, char *match, int **game, int line)
{
    int nbr = 0;
    int idx = 0;

    while (match[idx] != '\n') {
        if (match[idx] < 48 || match[idx] > 57) {
            my_putstr("Error: invalid output (positive number expected)\n");
            return 0;
        }
        idx++;
    }
    nbr = my_getnbr(match);
    if (nbr > match_mv) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(match_mv);
        my_putstr(" matches per turn\n");
        return 0;
    }
    return error_match_ext(nbr, game, line);
}

int error_handling(char **av)
{
    int line = 0;
    int m_rm = 0;
    int idx = 1;
    int idx2 = 0;

    while (av[idx] != NULL) {
        while (av[idx][idx2] != 0) {
            if (av[idx][idx2] < 48 || av[idx][idx2] > 57) 
                return 0;
            idx2++;
        }
        idx2 = 0;
        idx++;
    }
    line = my_getnbr(av[1]);
    m_rm = my_getnbr(av[2]);
    if (line <= 1 || line >= 100 || m_rm < 1)
        return 0;
    return 1;
}
