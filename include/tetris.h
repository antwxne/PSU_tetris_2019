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

#endif /* !TETRIS_H_ */
