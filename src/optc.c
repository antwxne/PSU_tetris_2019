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

void init_value(touch_t *touch)
{
    int terminal = 0;

    setupterm(NULL, 0, &terminal);
    touch->touching = malloc((sizeof(char *)) * 9);
    touch->touching[left] = "0";
    touch->touching[right] = "0";
    touch->touching[turn] = "";
    touch->touching[drop] = "0";
    touch->touching[quit] = "q";
    touch->touching[pose] = "0";
    touch->touching[level] = "1";
    touch->touching[size] = "20*10";
    printf("%s\n", tigetstr("kcub1"));
    touch->print_debug = 0;
    touch->next_hide = 0;
}

void choosing2(int opt, touch_t *touch)
{
    switch(opt) {
    case 'L':
        touch->touching[level] = optarg;
        break;
    }
}

void choosing(int opt, touch_t *touch)
{
    if (opt == -1 && touch->print_debug == 1)
        display_debug_mode(touch);
    switch(opt) {
    case 'h':
        helper();
        break;
    case 'D':
        touch->print_debug = 1;
        break;
    case 'w':
        touch->next_hide = 0;
        break;
    default:
        choosing2(opt, touch);
        break;
    }
}

void find_arg(int ac, char **av, touch_t *touch)
{
    int opt = 0;
    int option_index = 0;
    char *string = "hwDL:l:r:t:d:q:p:m:";
    struct option long_options [] = {
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
        {"debug", no_argument, NULL, 'D'}
    };

    while (opt != -1) {
        opt = getopt_long(ac, av, string, long_options, &option_index);
        choosing(opt, touch);
    }
}
