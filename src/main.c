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
    int ret;

    init_value(&touch);
    find_arg(ac, av, &touch);
    ret = display_debug_mode(&touch);
    return (ret == 0 ? 0: 84);
}
