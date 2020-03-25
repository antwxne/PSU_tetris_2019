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
void display_tetriminos(list_t *list);
void sorting_list(list_t **list);
void free_tetriminos(list_t *list);

#endif /* !TETRIS_H_ */
