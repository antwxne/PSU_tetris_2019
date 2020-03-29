/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** update_board
*/

#include <stdlib.h>
#include "struct.h"

void update_board(game_t *game, tetrimino_t tetri)
{
    unsigned int count_y = 0;
    unsigned int count_x = 0;

    for (unsigned int y = tetri.pos.y; tetri.shape[count_y] != NULL;
        y++, count_y++) {
        for (unsigned int x = tetri.pos.x;
            tetri.shape[count_y][count_x] != '\0'; x++, count_x++) {
            if (tetri.shape[count_y][count_x] == '*')
                game->board[y][x] = tetri.color;
            else
                game->board[y][x] = 0;
            }
        count_x = 0;
    }
}