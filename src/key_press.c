/*
** EPITECH PROJECT, 2020
** key
** File description:
** press
*/

#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include "my.h"
#include "tetris.h"
#include "struct.h"

int key_press(void)
{
    struct termios termios;
    char *str = 0;

    str = malloc(sizeof(char) * 1);
    if (str == NULL)
        return 84;
    tcgetattr(0, &termios);
    termios.c_lflag &= ~ICANON;
    termios.c_lflag &= ~INPCK;
    termios.c_lflag &= ~IXOFF;
    termios.c_lflag &= ~ECHO;
    tcsetattr(0, TCSADRAIN, &termios);
    read(0, str, 1);
    return 0;
}

void egal_key(touch_t *touch, int i)
{
    touch->keys[i] = touch->touching[i][2];
    if (touch->keys[i] == 'D')
        touch->keys[i] = KEY_LEFT;
    if (touch->keys[i] == 'C')
        touch->keys[i] = KEY_RIGHT;
    if (touch->keys[i] == 'A')
        touch->keys[i] = KEY_UP;
    if (touch->keys[i] == 'B')
        touch->keys[i] = KEY_DOWN;
}

void take_key(touch_t *touch)
{
    int i = 0;

    touch->keys = malloc(sizeof(int) * 6);
    for ( ; i <= 5; i++) {
        if (touch->touching[i][0] == 27)
            egal_key(touch, i);
        else if (my_strcmp(touch->touching[i], "(space)") == 0)
        touch->keys[i] = KEY_BACKSPACE;
        else
            touch->keys[i] = touch->touching[i][0];
    }
}

int switch_key(touch_t *touch, int get, game_t *game)
{
    int cur = game->current;

    take_key(touch);
    if (get == touch->keys[left])
        game->tetri[cur].pos = move_left((char const **)game->board,
        game->tetri[cur]);
    if (get == touch->keys[right])
        game->tetri[cur].pos = move_right((char const **)game->board,
        game->tetri[cur]);
    if (get == touch->keys[drop])
        game->tetri[cur].pos = move_down((char const **)game->board,
                                         game->tetri[cur]);
    return 0;
}
