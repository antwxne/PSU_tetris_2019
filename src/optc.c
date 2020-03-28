/*
** EPITECH PROJECT, 2020
** optc
** File description:
** optc
*/

#include <term.h>
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <ncurses.h>
#include "tetris.h"
#include "struct.h"

static const struct option long_options [12] = {
        {"help", no_argument, NULL, 'h'},
        {"level=", required_argument, NULL, 'L'},
        {"key-left=", required_argument, NULL, 'l'},
        {"key-right=", required_argument, NULL, 'r'},
        {"key-turn=", required_argument, NULL, 't'},
        {"key-drop=", required_argument, NULL, 'd'},
        {"key-quit=", required_argument, NULL, 'q'},
        {"key-pause=", required_argument, NULL, 'p'},
        {"map-size=", required_argument, NULL, 'm'},
        {"without-next", no_argument, NULL, 'w'},
        {"debug", no_argument, NULL, 'D'},
        {0, 0, 0, 0}
};

void init_value(touch_t *touch)
{
    int terminal = 0;

    setupterm(NULL, 0, &terminal);
    touch->touching = malloc((sizeof(char *)) * 9);
    touch->change = malloc(sizeof(int) * 4);
    touch->change[0] = 0;
    touch->change[1] = 0;
    touch->change[2] = 0;
    touch->change[3] = 0;
    touch->touching[left] = tigetstr("kcub1");
    touch->touching[right] = tigetstr("kcuf1");
    touch->touching[turn] = tigetstr("kcuu1");
    touch->touching[drop] = tigetstr("kcud1");
    touch->touching[quit] = "q";
    touch->touching[pose] = "(space)";
    touch->touching[level] = "1";
    touch->touching[size] = "20*10";
    touch->print_debug = 0;
    touch->next_hide = 0;
}

static void choosing3(int opt, touch_t *touch)
{
    switch(opt) {
    case 'd':
        error_optarg(optarg);
        touch->touching[drop] = optarg;
        touch->change[3] = 1;
        break;
    case 'q':
        error_optarg(optarg);
        touch->touching[quit] = optarg;
        break;
    case 'p':
        error_optarg(optarg);
        touch->touching[pose] = optarg;
        break;
    case 'm':
        error_size(optarg);
        touch->touching[size] = optarg;
        break;
    }
}

static void choosing2(int opt, touch_t *touch)
{
    switch(opt) {
    case 'L':
        level_erro(optarg);
        touch->touching[level] = optarg;
        break;
    case 'l':
        error_optarg(optarg);
        touch->touching[left] = optarg;
        touch->change[0] = 1;
        break;
    case 'r':
        error_optarg(optarg);
        touch->touching[right] = optarg;
        touch->change[1] = 1;
        break;
    default:
        choosing3(opt, touch);
        break;
    }
}

static void choosing(int opt, touch_t *touch)
{
    switch(opt) {
    case 'h':
        helper();
        break;
    case 'D':
        touch->print_debug = 1;
        break;
    case 'w':
        touch->next_hide = 1;
        break;
    case 't':
        error_optarg(optarg);
        touch->touching[turn] = optarg;
        touch->change[2] = 1;
        break;
    default:
        choosing2(opt, touch);
        break;
    }
}

int find_arg(int ac, char **av, touch_t *touch, list_t **list)
{
    int opt = 0;
    int option_index = 0;
    char *string = "hwDL:l:r:t:d:q:p:m:";
    DIR *dir = opendir("./tetriminos");

    if (open_folder(list, dir) == -1 || list == NULL)
        return (-1);
    get_info(list);
    while (opt != -1) {
        opt = getopt_long(ac, av, string, long_options, &option_index);
        if (opt == -1 && touch->print_debug == 1)
            display_debug_mode(touch, *list);
        choosing(opt, touch);
    }
    return 0;
}
