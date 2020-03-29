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
    for (int y = 0; game.board[y] != NULL; y++)
        for (int x = 0; game.board[y][x] != -1; x++)
            if (game.board[y][x] != 0) {
                wattron(game.windows[BOARD], COLOR_PAIR(game.board[y][x]));
                mvwprintw(game.windows[BOARD], 1+y, 1+x
                , "%d", game.board[y][x]);
                wattroff(game.windows[BOARD], COLOR_PAIR(game.board[y][x]));
            }
}

static void display_next(game_t game)
{
    int cur = game.current == 0 ? 1 : 0;

    mvwprintw(game.windows[NEXT], 1, game.size_b.x / 2 - 2, "NEXT");
    wattron(game.windows[NEXT], COLOR_PAIR(game.tetri[cur].color));
    for (int i = 0; game.tetri[cur].shape[i] != NULL; i++)
        for (int x = 0; game.tetri[cur].shape[i][x] != '\0'; x++)
            if (game.tetri[cur].shape[i][x] != ' ')
                mvwprintw(game.windows[NEXT], 2 + i,
                game.tetri[cur].pos.x + x, "%c", game.tetri[cur].shape[i][x]);
    wattroff(game.windows[NEXT], COLOR_PAIR(game.tetri[cur].color));
}

static void display_info(game_t game)
{
    mvwprintw(game.windows[INFO], 1, 25 - 2, "INFOS");
    mvwprintw(game.windows[INFO], 8, 25 - 2, "LEVEL : %u", game.level);
    mvwprintw(game.windows[INFO], 16, 25 - 2, "SCORE : %u", game.score);
}

void display_tetri_game(game_t game)
{
    display_board(game);
    display_moving_tetri(game);
    display_next(game);
    display_info(game);
}