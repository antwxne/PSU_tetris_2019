/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** error_tetri
*/

#include "struct.h"

static bool check_first_line(char *line)
{
    int space = 0;

    for (int i = 0; line[i] != '\0' && line[i] != '\n'; i++) {
        if (line [i] != ' ' && (!(line[i] >= '0' && line[i] <= '9')) &&
            line[i] != '\n')
            return (false);
        if (line[i] == ' ')
            space += 1;
    }
    return (space == 2 ? true : false);
}

static bool check_shape(char *buff)
{
    char *shape;
    int i = 0;

    for (; buff[i] != '\n'; i++)
        if (buff[i] == '\0')
            return (false);
    shape = &buff[i + 2];
    for (int i = 0; shape[i] != '\0'; i++)
        if (shape[i] != ' ' && shape[i] != '*' && shape[i] != '\n')
            return (false);
    return (true);
}

bool error_tetri(char *buff)
{
    return (check_shape(buff) && check_first_line(buff) ? true : false);
}