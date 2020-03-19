/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** main
*/

#include <stdlib.h>
#include "tetris.h"
#include "my.h"

int main(void)
{
    list_t *list = NULL;
    int ret = open_folder(&list);
    if (ret == 0) {
        get_info(&list);
        display_tetriminos(list);
    }
    return (ret == 0 ? 0 : 84);
}
