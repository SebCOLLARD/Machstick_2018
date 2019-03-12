/*
** EPITECH PROJECT, 2019
** print_game.c
** File description:
** print the game board
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"

int *build_game_board(int line)
{
    int idx = 0;
    int idx1 = 1;
    int *matches = malloc(sizeof(int) * line + 1);

    while (idx != line) {
        matches[idx] = idx1;
        idx1 = idx1 + 2;
        idx++;
    }
    matches[idx] = -1;
    return matches;
}

void print_star_line(int line)
{
    int idx = 0;
    int size = (line * 2 - 1) + 2;

    while (idx < size) {
        write(1, "*", 1);
        idx++;
    }
    write(1, "\n", 1);
}

void print_game_board(int *game, int line)
{
    int idx = 0;
    int idx2 = 0;
    int s = 0;
    char c;

    print_star_line(line);
    while (idx != line) {
        write(1, "*", 1);
        print_space(space_r(line, idx));
        s = idx * 2 + 1;
        while (idx2 < s) {
            c = idx2 < game[idx] ? '|' : ' ';
            write(1, &c, 1);
            idx2++;
        }
        print_space(space_r(line, idx));
        idx2 = 0;
        write(1, "*\n", 2);
        idx++;
    }
    print_star_line(line);
}
