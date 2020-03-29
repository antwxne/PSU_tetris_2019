/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** create_bord
*/

#include <stdlib.h>

static int *create_line(unsigned int size)
{
    int *dest = malloc(sizeof(int) * (size + 1));
    unsigned int i = 0;

    if (dest == NULL)
        return (NULL);
    for (; i < size; i++)
        dest[i] = 0;
    dest[i] = -1;
    return (dest);
}

int **create_board(int length, int height)
{
    int **board;

    if (length <= 0 || height <= 0)
        return (NULL);
    board = malloc(sizeof(int *)*(height+1));
    if (board == NULL)
        return (NULL);
    for (int i = 0; i < height; i++)
        board[i] = create_line(length);
    board[height] = NULL;
    return (board);
}