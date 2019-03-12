/*
** EPITECH PROJECT, 2019
** human.c
** File description:
** turn of human in matchstick
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "my.h"

void print_human(int match, int line)
{
    my_putstr("Player removed ");
    my_put_nbr(match);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}

int check_loose_h(int **game, int line)
{
    int idx = 0;
    int count = 0;

    while (idx != line) {
        if (game[0][idx] <= 0)
            count++;
        idx++;
    }
    if (count == line) {
        print_game_board(*game, line);
        my_putstr("You lost, too bad..\n");
        return 2;
    }
    return -4;
}

int player_human_play(int match_mv, int line, int **game)
{
    int idx = 1000000;
    int get = 0;
    size_t n = 0;
    char *match = NULL;
    char *line1 = NULL;

    my_putstr("Line: ");
    get = getline(&line1, &n, stdin);
    if (get < 0)
        return 0;
    if (error_line(line, line1) == 0)
        return player_human_play(match_mv, line, game);
    my_putstr("Matches: ");
    get = getline(&match, &n, stdin);
    if (get < 0)
        return 0;
    if (error_match(match_mv, match, game, my_getnbr(line1)) == 0)
        return player_human_play(match_mv, line, game);
    print_human(my_getnbr(match), my_getnbr(line1));
    idx = check_loose_h(game, line);
    return idx;
}
