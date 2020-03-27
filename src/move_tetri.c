/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** move_tetri
*/

#include <stdlib.h>
#include "struct.h"

char **move_left(char **board, size_tetri_t const pos, size_tetri_t const size)
{
    unsigned int y = pos.y;
    unsigned int x = pos.x;
    unsigned int count = 0;
    unsigned int count2 = 0;

    for (unsigned int i = y; count < size.y; count++)
        if (board[i][x] - 1 != ' ')
            return (board);
    for (count = 0; count < size.y; count++, y++) {
        for (count2 = 0; count2 < size.x; count2++, x++)
            board[y][x - 1] = board[y][x];
        x = pos.x;
    }
    return (board);
}