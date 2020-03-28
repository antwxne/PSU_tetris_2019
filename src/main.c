/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** main
*/
<<<<<<< HEAD
#include <time.h>
#include <stdio.h>
=======

#include <time.h>
>>>>>>> master
#include "tetris.h"

int main(int ac, char **av)
{
    touch_t touch;
    
    list_t *list = NULL;

    srand(time(NULL));
    init_value(&touch);
    if (ac == 1) {
        find_arg(ac, av, &touch, &list);
        game(touch, list);
    }
    else {
        if (find_arg(ac, av, &touch, &list) == 84)
            return 84;
        key_press();
        game(touch, list);
    }
    return 0;
}
