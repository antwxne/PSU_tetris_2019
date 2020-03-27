/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetris
*/

#ifndef TETRIS_H_
#define TETRIS_H_

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
int game(touch_t touch, list_t *list);
char **create_board(int length, int height);

#endif /* !TETRIS_H_ */
