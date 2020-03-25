/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** main
*/

#include <stdlib.h>
#include "tetris.h"
#include "my.h"

int main(int ac, char **av)
{
    touch_t touch;
/*    list_t *list = NULL;
    int ret = open_folder(&list);
    if (ret == 0) {
        get_info(&list);
        display_tetriminos(list);
    }
    return (ret == 0 ? 0 : 84);*/
    init_value(&touch);
    find_arg(ac, av, &touch);
    return 0;
}
