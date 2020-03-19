/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** display
*/

#include <stdlib.h>
#include "tetris.h"
#include "my.h"

void display_tetriminos(list_t *list)
{
    for (list_t *temp = list; temp != NULL; temp = temp->next) {
        my_putstr("Tetriminos :  ");
        my_printf("Name %s :  ", temp->info.name);
        if (!(temp->info.error))
            my_putstr("Error\n");
        else
            my_printf("Size %d*%d :  Color %d :\n%s",
            temp->info.size.x, temp->info.size.y,
            temp->info.color, temp->info.shape);
    }
}