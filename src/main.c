/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** main
*/

#include "tetris.h"

int main(int ac, char **av)
{
    touch_t touch;
    
    list_t *list = NULL;

    srand(time(NULL));
    init_value(&touch);
    if (find_arg(ac, av, &touch, &list) == 84)
        return 84;
    key_press();
//    switch_key(&touch, i);
    game(touch, list);
    return 0;
}
