/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** init
*/

#include <curses.h>
#include "tetris.h"
#include "my.h"

static void color_init(void)
{
    start_color();
    init_pair(0, 0, 0);
    init_pair(1, 1, 1);
    init_pair(2, 2, 2);
    init_pair(3, 3, 3);
    init_pair(4, 4, 4);
    init_pair(5, 5, 5);
    init_pair(6, 6, 6);
    init_pair(7, 7, 7);
}

void init_window(game_t *game)
{
    initscr();
    color_init();
    game->windows[BOARD] = subwin(stdscr, game->size_b.y+2, game->size_b.x+2,
    LINES / 2 - game->size_b.y / 2, COLS / 2 - game->size_b.x / 2);
    game->windows[TETRIMINO] = subwin(game->windows[BOARD], game->size_b.y,
    game->size_b.x, (LINES / 2 - game->size_b.y / 2) + 1,
    (COLS / 2 - game->size_b.x / 2) + 1);
    keypad(stdscr, TRUE);
    keypad(game->windows[TETRIMINO], TRUE);
    curs_set(0);
    noecho();
}