/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** main
*/

#include "tetris.h"
#include "my.h"

int main(int ac, char **av)
{
    touch_t touch;

    init_value(&touch);
    find_arg(ac, av, &touch);
    return 0;
}
