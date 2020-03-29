/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** remove_line
*/

#include <stdlib.h>
#include "struct.h"

static bool parse_line(char const *line)
{
    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] != '*')
            return (false);
    return (true);
}

static int parse_board(char const **board)
{
    int line = -1;

    for (int y = 0; board[y] != NULL; y++)
        if (parse_line((char const *) board[y])) {
            line = y;
            break;
        }
    return (line);
}

char **remove_line(char **board, game_t *game)
{
    int remove = parse_board((char const **) board);

    if (remove == -1)
        return (board);
    for (; remove > 0; remove--)
        for (int i = 0; board[remove][i] != '\0'; i++)
            board[remove][i] = board[remove - 1][i];
    game->score += 100;
    return (board);
}