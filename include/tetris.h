/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetris
*/

#ifndef TETRIS_H_
#define TETRIS_H_

#include <curses.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include "struct.h"

int open_folder(list_t **list, DIR *dir);
void get_info(list_t **list);
bool check_first_line(char *line);
bool check_shape(char **shape);
bool check_size(char **shape, size_tetri_t size);
void display_tetriminos(list_t *list);
void sorting_list(list_t **list);
void free_tetriminos(list_t *list);
void init_value(touch_t *touch);
int find_arg(int ac, char **av, touch_t *touch, list_t **list);
void helper(void);
void display_debug_mode(touch_t *touch, list_t *list);
char *my_itoa(int nb);
void level_erro(char *optarg);
int my_str_isnum(char *str);
void error_optarg(char *optarg);
void error_size(char *str);
void original_set(char *pos, char **keys, int change, int i);
void print_deb(touch_t *touch);
void all_print(touch_t *touch);
int key_press(void);
int game(touch_t touch, list_t *list);
int **create_board(int length, int height);
int block_tetri(WINDOW *w_tetri, tetrimino_t t);
void display_tetri_game(game_t game);
tetrimino_t loading_tetrimino(game_t game, list_t const *list,
    int const len_list);
size_tetri_t move_left(int const **board, tetrimino_t tetri);
size_tetri_t move_right(int const **board, tetrimino_t tetri);
size_tetri_t move_down(int const **board, tetrimino_t tetri);
int game_loop(game_t game, touch_t touch, list_t *list);
void init_window(game_t *game);
int switch_key(touch_t *touch, int get, game_t *game);
int manage_keys(game_t *game, touch_t *touch);
void check_wrong(int ac,char **av);
void check_wrong(int ac, char **av);
int manage_keys(game_t *game, touch_t *touch);
int len_list(list_t const *list);
void update_board(game_t *game, tetrimino_t tetri);
void manage_game(game_t *game, list_t const *list);
int **remove_line(int **board, game_t *game);

#endif /* !TETRIS_H_ */
