/*
** EPITECH PROJECT, 2020
** debug
** File description:
** mode
*/

#include "tetris.h"
#include "struct.h"
#include "my.h"

void print_deb(touch_t *touch)
{
    original_set("Left", touch->touching, touch->change[0], left);
    original_set("Right", touch->touching, touch->change[1], right);
    original_set("Turn", touch->touching, touch->change[2], turn);
    original_set("Drop", touch->touching, touch->change[3], drop);
}

void all_print(touch_t *touch)
{
    print_deb(touch);
    my_printf("\nKey Quit :  %s", touch->touching[quit]);
    my_printf("\nKey Pause :  %s", touch->touching[pose]);
    my_printf("\nNext :  ");
    if (touch->next_hide == 0)
        my_printf("Yes");
    else
        my_printf("No");
    my_printf("\nLevel :  %s", touch->touching[level]);
    my_printf("\nSize :  %s\n", touch->touching[size]);

}
