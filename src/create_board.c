/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** create_bord
*/

#include <stdlib.h>
#include <criterion/criterion.h>
/* #include "my.h" */

char *top_end_line(int length)
{
    char *dest = malloc(sizeof(char)*length+1);

    if (dest == NULL)
        return (NULL);
    dest[0] = '+';
    for (int i = 1; i < length - 1; i++)
        dest[i] = '-';
    dest[length - 1] = '+';
    dest[length] = 0;
    return (dest);
}

char *line(int length)
{
    char *dest = malloc(sizeof(char)*length+1);

    if (dest == NULL)
        return (NULL);
    dest[0] = '|';
    for (int i = 1; i < length - 1; i++)
        dest[i] = ' ';
    dest[length - 1] = '|';
    dest[length] = 0;
    return (dest);
}

char **create_board(int length, int height)
{
    char **board;

    if (length <= 0 || height <= 0)
        return (NULL);
    board = malloc(sizeof(char *)*(height+2));
    if (board == NULL)
        return (NULL);
    board[0] = top_end_line(length + 2);
    for (int i = 1; i < height + 1; i++)
        board[i] = line(length + 2);
    board[height + 1] = top_end_line(length + 2);
    board[height + 2] = NULL;
    return (board);
}