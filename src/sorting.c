/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** sorting
*/

#include <stdlib.h>
#include "struct.h"
#include "my.h"

static void swap(info_t *a, info_t *b)
{
    info_t temp = *a;

    *a = *b;
    *b = temp;
}

void sorting_list(list_t **list)
{
    bool sort;
    list_t *stop = NULL;
    list_t *temp;

    if (*list == NULL)
        return;
    do {
        sort = false;
        temp = *list;
        for (; temp->next != stop; temp = temp->next)
            if (my_strcmp(temp->info.name, temp->next->info.name) > 0) {
                swap(&temp->info, &temp->next->info);
                sort = true;
            }
        stop = temp;
    } while (sort);
}
