/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** display_game
*/

#include <stdlib.h>
#include <curses.h>
#include "struct.h"

static void display_moving_tetri(game_t game)
{
    int cur = game.current;

    wattron(game.windows[TETRIMINO], COLOR_PAIR(game.tetri[cur].color));
    for (int i = 0; game.tetri[cur].shape[i] != NULL; i++)
        for (int x = 0; game.tetri[cur].shape[i][x] != '\0'; x++)
            if (game.tetri[cur].shape[i][x] != ' ')
                mvwprintw(game.windows[TETRIMINO], game.tetri[cur].pos.y+i,
                game.tetri[cur].pos.x + x, "%c", game.tetri[cur].shape[i][x]);
    wattroff(game.windows[TETRIMINO], COLOR_PAIR(game.tetri[cur].color));
}

static void display_board(game_t game)
{
    wattron(game.windows[BOARD], COLOR_PAIR(COLOR_WHITE));
    for (int y = 0; game.board[y] != NULL; y++)
        for (int x = 0; game.board[y][x] != '\0'; x++)
            if (game.board[y][x] != ' ')
                mvwprintw(game.windows[BOARD], 1+y, 1+x
                , "%c", game.board[y][x]);
    wattroff(game.windows[BOARD], COLOR_PAIR(COLOR_WHITE));
}

void display_tetri_game(game_t game)
{
    display_board(game);
    display_moving_tetri(game);
}