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
    int i = 0;
    
    init_value(&touch);
    if (find_arg(ac, av, &touch) == 84)
        return 84;
    key_press();
//    switch_key(&touch, i);
    return 0;
}
