/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** manage_game
*/

#include <curses.h>
#include "struct.h"

void display_tetri(WINDOW *w_tetri, game_t game)
{
    wattron(w_tetri, COLOR_PAIR(game.tetri.color));
    for (int i = 0; game.tetri.shape[i] != NULL; i++)
        mvwprintw(w_tetri, game.tetri.pos.y + i, game.tetri.pos.x,
            game.tetri.shape[i]);
    wattroff(w_tetri, COLOR_PAIR(game.tetri.color));

}

int block_tetri(WINDOW *w_tetri, tetrimino_t t)
{
    chtype *str;

    mvwinchstr(w_tetri, t.pos.y + t.size.y, 1, str);
    wprintw(stdscr, "%s end", str);
    return (0);
}