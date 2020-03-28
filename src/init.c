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
    init_pair(0, COLOR_BLACK, COLOR_BLACK);
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_GREEN, COLOR_GREEN);
    init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(4, COLOR_BLUE, COLOR_BLUE);
    init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(6, COLOR_CYAN, COLOR_CYAN);
    init_pair(7, COLOR_WHITE, COLOR_WHITE);
}

void init_window(WINDOW **te, WINDOW **w_tetri, game_t game)
{
    initscr();
    color_init();
    *w_tetri = subwin(stdscr, game.size_b.y + 2, game.size_b.x + 2,
    LINES / 2 - game.size_b.y / 2, COLS / 2 - game.size_b.x / 2);
    *te = subwin(*w_tetri, game.size_b.y, game.size_b.x,
    (LINES / 2 - game.size_b.y / 2) + 1, (COLS / 2 - game.size_b.x / 2) + 1);
    keypad(stdscr, TRUE);
    curs_set(0);
    noecho();
}