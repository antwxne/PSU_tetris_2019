/*
** EPITECH PROJECT, 2020
** debug
** File description:
** mode
*/

#include "tetris.h"
#include "struct.h"

void print_deb(touch_t *touch)
{
    original_set("Left", touch->touching, touch->change[0], left);
    original_set("Right", touch->touching, touch->change[1], right);
    original_set("Turn", touch->touching, touch->change[2], turn);
    original_set("Drop", touch->touching, touch->change[3], drop);
}
