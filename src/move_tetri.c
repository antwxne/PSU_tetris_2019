/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** move_tetri
*/

#include <curses.h>
#include <stdlib.h>
#include "struct.h"

size_tetri_t move_left(char const **board, size_tetri_t pos)
{
    if (pos.x <= 0)
        return ((size_tetri_t) {pos.y, pos.x});
    for (int i = 0; board[i] != NULL; i++)
        if (board[i][pos.x - 1] != ' ')
            return ((size_tetri_t) {pos.y, pos.x});
    return ((size_tetri_t) {pos.y, pos.x - 1});
}

size_tetri_t move_right(char const **board, size_tetri_t pos, size_tetri_t size)
{
    for (int i = 0; board[i] != NULL; i++)
        if (board[i][pos.x + size.x] != ' ')
            return ((size_tetri_t) {pos.y, pos.x});
    return ((size_tetri_t) {pos.y, pos.x + 1});
}

size_tetri_t move_down(char const **board, size_tetri_t s_b, size_tetri_t pos,
    size_tetri_t size)
{
    if (pos.y + size.y + 1 > s_b.y)
        return ((size_tetri_t) {pos.y, pos.x});
    for (unsigned int i = pos.x; board[pos.y + size.y][i] != '\0' &&
        i < size.x; i++)
        if (board[pos.y + size.y + 1][i] != ' ')
            return ((size_tetri_t) {pos.y, pos.x});
    return ((size_tetri_t) {pos.y + 1, pos.x});
}