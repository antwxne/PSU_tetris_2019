/*
** EPITECH PROJECT, 2020
** optc
** File description:
** optc
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include "tetris.h"
#include "struct.h"

void init_value(touch_t *touch)
{
    touch->touching = malloc((sizeof(char*)) * 8);
    touch->touching[0] = "0";
    touch->touching[1] = "0";
    touch->touching[2] = "0";
    touch->touching[3] = "0";
    touch->touching[4] = "0";
    touch->touching[5] = "0";
    touch->touching[6] = "0";
    touch->touching[7] = "0";
    touch->print_debug = 0;
    touch->next_hide = 0;
}

void choosing(int opt, touch_t *touch)
{
    switch(opt) {
    case 'h':
        helper();
        break;
    case 'L':
        touch->touching[0] = optarg;
        break;
    case 'l':
        touch->touching[1] = optarg;
        break;
    case 'w':
        touch->next_hide = 1;
        break;
    case 'D':
        touch->print_debug = 1;
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
    init_value(touch);
    while (opt != -1) {
        opt = getopt_long(ac, av, string, long_options, &option_index);
        choosing(opt, touch);
    }
    if (opt == -1 && touch->print_debug == 1)
        display_debug_mode(touch);
}
