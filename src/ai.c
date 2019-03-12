/*
** EPITECH PROJECT, 2019
** ai.c
** File description:
** code for ai turn in matchstick
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void print_ai(int rand_match, int rand_line)
{
    my_putstr("AI removed ");
    my_put_nbr(rand_match);
    my_putstr(" match(es) frome line ");
    my_put_nbr(rand_line);
    write(1, "\n", 1);
}

int check_loose_ai(int **game, int line)
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
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return 1;
    }
    return -4;
}

int  player_ai_play(int match_mv, int line, int **game)
{
    int rand_line = 0;
    int rand_match = 0;

    rand_line = random() % line + 1;
    if (game[0][rand_line - 1] == 0)
        return player_ai_play(match_mv, line, game);
    rand_match = random() % game[0][rand_line - 1] + 1;
    if (rand_match > game[0][rand_line - 1] || rand_match > match_mv)
        return player_ai_play(match_mv, line, game);
    game[0][rand_line - 1] = game[0][rand_line - 1] - rand_match;
    print_ai(rand_match, rand_line);
    if (check_loose_ai(game, line) == 1)
        return 1;
    return -4;
}
