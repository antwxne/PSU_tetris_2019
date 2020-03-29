/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** manage_game
*/

#include <curses.h>
#include "tetris.h"
#include "struct.h"
#include "my.h"

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
        game->tetri[cur].pos = move_down((int const **)game->board,
            game->tetri[cur]);
    return (0);
}

static bool is_blocked(int const **board, tetrimino_t tetri)
{
    size_tetri_t check = move_down(board, tetri);

    if (check.x == tetri.pos.x && check.y == tetri.pos.y)
        return (true);
    return (false);
}

static tetrimino_t reload_tetri(game_t game, tetrimino_t tetri,
    list_t const *list)
{
    my_free_arr(tetri.shape, 0);
    tetri = loading_tetrimino(game, list, game.len_list);
    return (tetri);
}

void manage_game(game_t *game, list_t const *list)
{
    int cur = game->current;

    if (is_blocked((int const **)game->board, game->tetri[cur])) {
            update_board(game, game->tetri[cur]);
            game->tetri[cur] = reload_tetri(*game, game->tetri[cur], list);
            game->current = game->current == 0 ? 1 : 0;
        }
    game->board = remove_line(game->board, game);
}