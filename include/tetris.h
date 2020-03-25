/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetris
*/

#ifndef TETRIS_H_
#define TETRIS_H_

#include "struct.h"

int open_folder(list_t **list);
void get_info(list_t **list);
bool error_tetri(char *buff);
void display_tetriminos(list_t *list);
void sorting_list(list_t **list);
void init_value(touch_t *touch);
void find_arg(int ac, char **av, touch_t *touch);
void helper(void);
void display_debug_mode(touch_t *touch);
char *my_itoa(int nb);
void level_erro(char *optarg);
int my_str_isnum(char *str);
void error_optarg(char *optarg);

#endif /* !TETRIS_H_ */
