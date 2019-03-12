/*
** EPITECH PROJECT, 2019
** endless_loop.c
** File description:
** endless loop for matchstick game 
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"

int endless_loop(int line, int match_mv)
{
    int idx = -1;
    int idx2 = -2;
    int *game = build_game_board(line);

    while (42) {
        print_game_board(game, line);
        my_putstr("\nYour turn:\n");
        idx = player_human_play(match_mv, line, &game);
        if (idx == 0)
            return 0;
        if (idx == 2)
            return 2;
        print_game_board(game, line);
        my_putstr("\nAI's turn...\n");
        idx2 = player_ai_play(match_mv, line, &game);
        if (idx2 == 1)
            return 1;
    }
    free(game);
    return 0;
}
