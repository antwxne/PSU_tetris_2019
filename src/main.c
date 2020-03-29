/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** main
*/

#include <time.h>
#include <stdio.h>
#include <time.h>
#include "tetris.h"

int main(int ac, char **av)
{
    touch_t touch;

    list_t *list = NULL;

    srand(time(NULL));
    init_value(&touch);
    check_wrong(ac, av);
    if (find_arg(ac, av, &touch, &list) == 84)
        return 84;
    if (game(touch, list) == 84)
        return 84;
    return 0;
}
