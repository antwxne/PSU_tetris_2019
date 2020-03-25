/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** display
*/

#include <stdlib.h>
#include "tetris.h"
#include "my.h"

static void display_tetri(char **tetri)
{
    for (int i = 0; tetri[i] != NULL; i++)
        my_putstr(tetri[i]);
}

void display_tetriminos(list_t *list)
{
    for (list_t *temp = list; temp != NULL; temp = temp->next) {
        my_putstr("Tetriminos :  ");
        my_printf("Name %s :  ", temp->info.name);
        if (!(temp->info.error))
            my_putstr("Error\n");
        else {
            my_printf("Size %d*%d :  Color %d :\n",
            temp->info.size.x, temp->info.size.y,
            temp->info.color);
            display_tetri(temp->info.shape);
        }
    }
}