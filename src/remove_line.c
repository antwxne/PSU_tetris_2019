/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** remove_line
*/

#include <stdlib.h>
#include "struct.h"

static bool parse_line(int const *line)
{
    for (int i = 0; line[i] != -1; i++)
        if (line[i] == 0)
            return (false);
    return (true);
}

static int parse_board(int const **board)
{
    int line = -1;

    for (int y = 0; board[y] != NULL; y++)
        if (parse_line((int const *) board[y])) {
            line = y;
            break;
        }
    return (line);
}

int **remove_line(int **board, game_t *game)
{
    int remove = parse_board((int const **) board);

    if (remove == -1)
        return (board);
    for (; remove > 0; remove--)
        for (int i = 0; board[remove][i] != -1; i++)
            board[remove][i] = board[remove - 1][i];
    game->score += 100;
    return (board);
}