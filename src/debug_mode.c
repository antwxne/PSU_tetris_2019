/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** debug_mode
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
    if (new == 4 && !(optarg[0] == '^' && optarg[1] == 'E'))
        exit(84);
}

void original_set(char *pos, char **keys, int change, int i)
{
    if (change == 0) {
        my_printf("\nKey %s :  ^E%s", pos, &keys[i][1]);
    }
    else if (my_strcmp(keys[i], " ") == 0)
        my_printf("\nkey %s :  (space)", pos);
    else
        my_printf("\nKey %s :  %s", pos, keys[i]);
}

void display_debug_mode(touch_t *touch)
{
    list_t *list = NULL;
    int ret = open_folder(&list);

    my_printf("*** DEBUG MODE ***");
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
    if (ret == 0) {
        get_info(&list);
        display_tetriminos(list);
    }
    printf("Press any key to start Tetris\n");
}
