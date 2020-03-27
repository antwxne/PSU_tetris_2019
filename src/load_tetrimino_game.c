/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** load_tetrimino_game
*/

#include <stdlib.h>
#include "struct.h"

static char **insert_in_board(game_t game, info_t const tetri)
{
    unsigned int const middle = (game.size_b.x / 2);
    unsigned int line = 1;
    unsigned int temp = middle;

    for (unsigned int y = 0; y < tetri.size.y ; y++, line++) {
        for (unsigned int x = 0; tetri.shape[y][x] != '\n'; x++, temp++)
            game.board[line][temp] = tetri.shape[y][x];
        temp = middle;
    }
    return (game.board);
}

static int check_allowed(game_t const game, size_tetri_t const size)
{
    unsigned int const start = (game.size_b.x / 2);
    unsigned int const end = (game.size_b.x / 2) + (size.x / 2);

    for (unsigned int y = 1; y < size.y; y++)
        for (unsigned x = start; x <= end; x++)
            if (game.board[y][x] != ' ')
                return (-1);
    return (0);
}

static int len_list(list_t *list)
{
    int len = 0;

    for (list_t *temp = list; temp != NULL; temp = temp->next)
        len++;
    return (len);
}

int load_tetri(game_t *game, list_t *list)
{
    list_t *temp = list;
    int len = len_list(list);
    int select = rand() % len;
    int check;

    for (int i = 0; i < select; temp = temp->next, i++);
    if (temp->info.error == false)
        load_tetri(game, list);
    if (check_allowed(*game, temp->info.size) == -1)
        return (-1);
    game->board = insert_in_board(*game, (info_t const) temp->info);
    return (0);
}