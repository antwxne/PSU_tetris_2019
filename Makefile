##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	= 	src/main.c					\
		src/open_folder.c 			\
		src/info.c 					\
		src/error_tetri.c 			\
		src/display.c 				\
		src/sorting.c 				\
		src/free_tetris.c 			\
		src/optc.c					\
		src/helper.c				\
		src/debug_mode.c			\
		src/print_debug.c			\
		src/game.c 					\
		src/game_loop.c 			\
		src/create_board.c 			\
		src/load_tetrimino_game.c 	\
		src/move_tetri.c 			\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Wall

CPPFLAGS	=	-I./include

LDFLAGS	=	-L./lib -lmy -lncurses

NAME	=	tetris

CC	=	gcc

all:	$(NAME)

$(NAME): $(OBJ)
	make -C lib/my/
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

debug:	CFLAGS += -g3
debug:	re

tests_run: SRC += tests/tests_tetris.c
tests_run: SRC := $(filter-out src/main.c, $(SRC))
tests_run: NAME := unit_tests
tests_run:
	make -C lib/my/
	$(CC) -o $(NAME) $(SRC) $(LDFLAGS) -lcriterion --coverage -I./include
	./$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(NAME_TESTS)
	make fclean -C lib/my/

re: fclean all

.PHONY: all fclean re clean $(NAME) tests_run debug
