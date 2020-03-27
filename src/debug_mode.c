/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** debug_mode
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curses.h>
#include "my.h"
#include "tetris.h"
#include "struct.h"

void error_size(char *str)
{
    int i = 0;

    while (str[i] != 0) {
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == ',') {
            if (str[i] == ',')
                str[i] = '*';
            i += 1;
        }
        else
            exit(84);
    }
}

void level_erro(char *optarg)
{
    int new = 0;

    if (my_str_isnum(optarg) == 0)
        exit(84);
    new = my_getnbr(optarg);
    if (new <= 0)
        exit(84);
}

void error_optarg(char *optarg)
{
    int new = my_strlen(optarg);

    if (new != 1 && new != 4)
        exit(84);
    if (new == 4 && !(optarg[0] == '2' && optarg[1] == '7'))
        exit(84);
    if (optarg[0] == '2' && optarg[1] == '7') {
        optarg[0] = '^';
        optarg[1] = 'E';
    }
}

void original_set(char *pos, char **keys, int change, int i)
{
    if (change == 0)
        my_printf("\nKey %s :  ^E%s", pos, &keys[i][1]);
    else if (my_strcmp(keys[i], " ") == 0)
        my_printf("\nkey %s :  (space)", pos);
    else
        my_printf("\nKey %s :  %s", pos, keys[i]);
}

void display_debug_mode(touch_t *touch, list_t *list)
{
    my_printf("*** DEBUG MODE ***");
    all_print(touch);
    display_tetriminos(list);
    my_printf("Press any key to start Tetris\n");
}
