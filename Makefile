##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compilator for my_ls
##

SRC		=	src/print_game.c	\
			src/my_getnbr.c		\
			src/error.c		\
			src/space.c		\
			src/my_putchar.c	\
			src/my_putstr.c		\
			src/my_put_nbr.c	\
			src/endless_loop.c	\
			src/human.c		\
			src/ai.c

SRC_M		=	src/main.c

SRC_T		=	tests/tests_print.c

OBJ		=	$(SRC:.c=.o)

OBJ_M		=	$(SRC_M:.c=.o)

CFLAGS		=	-g -W -Wall -Werror -I./include

CFLAGS_T	=	-lcriterion --coverage -I./include

NAME		=	matchstick

NAME_T		=	unit_test

all:		$(NAME)

$(NAME):	$(OBJ) $(OBJ_M)
		gcc -o $(NAME) $(OBJ) $(OBJ_M)

tests_run:
		gcc -o $(NAME_T) $(SRC) $(SRC_T) $(CFLAGS_T)
		./$(NAME_T)

clean:
		rm -f $(OBJ) $(OBJ_M) *.gc*

fclean:		clean
		rm -f $(NAME) $(NAME_T)

re:		fclean all
