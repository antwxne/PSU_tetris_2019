/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** create_bord
*/

#include <stdlib.h>

static char *create_line(int size)
{
    char *dest = malloc(sizeof(char) * (size + 1));
    unsigned int i = 0;

    if (dest == NULL)
        return (NULL);
    for (; i < size; i++)
        dest[i] = ' ';
    dest[i] = '\0';
    return (dest);
}

char **create_board(int length, int height)
{
    char **board;

    if (length <= 0 || height <= 0)
        return (NULL);
    board = malloc(sizeof(char *)*(height+1));
    if (board == NULL)
        return (NULL);
    for (int i = 1; i < height; i++)
        board[i] = create_line(length);
    board[height] = NULL;
    return (board);
}