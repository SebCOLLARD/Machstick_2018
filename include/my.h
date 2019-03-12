/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** header include
*/

#ifndef MY_H_
# define MY_H_

#include <stdio.h>

int *build_game_board(int line);
void print_star_line(int line);
void print_game_board(int *game, int line);
int error_handling(char **av);
int my_getnbr(char *str);
int space_r(int line_max, int stick);
int space_l(int line, int matches, int space_r);
void print_space(int space);
int player_human_play(int match_mv, int line, int **game);
int error_line(int line, char *line1);
int error_match(int match_mv, char *match, int **game, int line);
void my_putchar(char c);
void my_put_nbr(int nb);
void my_putstr(char *str);
int endless_loop(int line, int match_mv);
int player_ai_play(int match_mv, int line, int **game);
int error_match_ext(int nbr, int **game, int line);

#endif
