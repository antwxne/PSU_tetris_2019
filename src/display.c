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

static int len_list(list_t const *list)
{
    int len = 0;

    for (list_t *temp = list; temp != NULL; temp = temp->next)
        len++;
    return (len);
}

void display_tetriminos(list_t *list)
{
    my_printf("Tetriminos : %d\n", len_list(list));
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