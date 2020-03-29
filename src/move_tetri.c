/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** move_tetri
*/

#include <curses.h>
#include <stdlib.h>
#include "struct.h"

size_tetri_t move_left(char const **board, tetrimino_t tetri)
{
    unsigned int count_y = 0;
    unsigned int count_x = 0;

    if (tetri.pos.x <= 0)
        return (tetri.pos);
    for (unsigned int y = tetri.pos.y; tetri.shape[count_y] != NULL;
        y++, count_y++) {
        for (unsigned int x = tetri.pos.x;
            tetri.shape[count_y][count_x] != '\0'; x++, count_x++)
            if (tetri.shape[count_y][count_x] == '*' &&
                board[y][x - 1] != ' ')
                return (tetri.pos);
        count_x = 0;
        }
    return ((size_tetri_t) {tetri.pos.y, tetri.pos.x - 1});
}

size_tetri_t move_right(char const **board, tetrimino_t tetri)
{
    unsigned int count_y = 0;
    unsigned int count_x = 0;

    if (tetri.pos.x + tetri.size.x == '\0')
        return (tetri.pos);
    for (unsigned int y = tetri.pos.y; tetri.shape[count_y] != NULL;
        y++, count_y++) {
        for (unsigned int x = tetri.pos.x;
            tetri.shape[count_y][count_x] != '\0'; x++, count_x++)
            if (tetri.shape[count_y][count_x] == '*' &&
                board[y][x + 1] != ' ')
                return (tetri.pos);
        count_x = 0;
        }
    return ((size_tetri_t) {tetri.pos.y, tetri.pos.x + 1});
}

size_tetri_t move_down(char const **board, tetrimino_t tetri)
{
    unsigned int count_y = 0;
    unsigned int count_x = 0;

    if (board[tetri.pos.y + tetri.size.y] == NULL)
        return ((size_tetri_t) {tetri.pos.y, tetri.pos.x});
    for (unsigned int y = tetri.pos.y; tetri.shape[count_y] != NULL;
        y++, count_y++) {
        for (unsigned int x = tetri.pos.x;
        tetri.shape[count_y][count_x] != '\0'; x++, count_x++)
            if (board[y + 1][x] != ' ')
                return (tetri.pos);
        count_x = 0;
        }
    return ((size_tetri_t) {tetri.pos.y + 1, tetri.pos.x});
}