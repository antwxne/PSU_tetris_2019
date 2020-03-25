/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** free_tetris
*/

#include <stdlib.h>
#include "struct.h"
#include "my.h"

void free_tetriminos(list_t *list)
{
    list_t *next;
    list_t *temp = list;

    while (temp != NULL) {
        free(temp->info.name);
        next = temp->next;
        my_free_arr(temp->info.shape, 0);
        free(temp);
        temp = next;
    }
}