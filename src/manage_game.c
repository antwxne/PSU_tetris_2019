/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** manage_game
*/

#include <curses.h>
#include "struct.h"

void display_tetri_game(game_t game)
{
    for (int i = 0; game.board[i] != NULL; i++)
        mvwprintw(game.windows[BOARD], 1 + i, 1, game.board[i]);
    wattron(game.windows[TETRIMINO], COLOR_PAIR(game.tetri.color));
    for (int i = 0; game.tetri.shape[i] != NULL; i++)
        mvwprintw(game.windows[TETRIMINO], game.tetri.pos.y+i, game.tetri.pos.x,
            game.tetri.shape[i]);
    wattroff(game.windows[TETRIMINO], COLOR_PAIR(game.tetri.color));
}