/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** manage_game
*/

#include <curses.h>
#include "tetris.h"
#include "struct.h"

void display_tetri_game(game_t game)
{
    int cur = game.current;

    for (int i = 0; game.board[i] != NULL; i++)
        mvwprintw(game.windows[BOARD], 1 + i, 1, game.board[i]);
    wattron(game.windows[TETRIMINO], COLOR_PAIR(game.tetri[cur].color));
    for (int i = 0; game.tetri[cur].shape[i] != NULL; i++)
        mvwprintw(game.windows[TETRIMINO], game.tetri[cur].pos.y+i,
        game.tetri[cur].pos.x, game.tetri[cur].shape[i]);
    wattroff(game.windows[TETRIMINO], COLOR_PAIR(game.tetri[cur].color));
}

int manage_keys(game_t *game, touch_t *touch)
{
    int get_key = -1;
    int cur = game->current;

    wtimeout(game->windows[TETRIMINO], 1000 - game->level * 10);
    get_key = wgetch(game->windows[TETRIMINO]);
    switch_key(touch, get_key, game);
    if (get_key == touch->keys[quit])
        return (1);
    if (get_key == -1)
        game->tetri[cur].pos = move_down((char const **)game->board,
        game->tetri[cur].pos, game->tetri[cur].size);
    return (0);
}

bool is_blocked(char const **board, size_tetri_t pos, size_tetri_t size)
{
    if (board[pos.y + size.y] == NULL)
        return (false);
    for (unsigned int i = pos.x; board[pos.y + size.y][i] != '\0' &&
        i < size.x; i++)
        if (board[pos.y + size.y][i] != ' ')
            return (false);
    return (true);
}

// void manage_game(game_t *game, list_t const *list)
// {
//     if 
// }