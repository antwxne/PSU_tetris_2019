/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** error_tetri
*/

#include "struct.h"

bool check_size(char **shape, size_tetri_t size)
{
    unsigned int get_y = 0;
    unsigned int get_x = 0;
    unsigned int i = 0;

    for (; shape[get_y] != NULL; get_y++) {
        for ( i = 0; shape[get_y][i]; i++);
    get_x = get_x < i ? i : get_x;
    }
    return (get_x - 1 == size.x && get_y == size.y ? true : false);
}

bool check_first_line(char *line)
{
    int space = 0;

    if (line == NULL)
        return (false);
    for (int i = 0; line[i] != '\0'; i++) {
        if (line [i] != ' ' && (!(line[i] >= '0' && line[i] <= '9')) &&
            line[i] != '\n')
            return (false);
        if (line[i] == ' ')
            space += 1;
    }
    return (space == 2 ? true : false);
}

bool check_shape(char **shape)
{
    if (shape == NULL)
        return (false);
    for (unsigned int y = 0; shape[y] != NULL; y++)
        for (unsigned int x = 0; shape[y][x] != '\0'; x++)
            if (shape[y][x] != ' ' && shape[y][x] != '*' && shape[y][x] != '\n')
                return (false);
    return (true);
}