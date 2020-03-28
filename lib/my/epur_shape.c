/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** epur_shape
*/

#include <stdlib.h>

int my_strlen(char *str);

static char *adjust_str(char *str)
{
    int len = my_strlen(str);
    char *dest = malloc(sizeof(char) * (len + 2));
    unsigned int i = 0;

    if (dest == NULL)
        return (NULL);
    for (; str[i] != '\0'; i++)
        dest[i] = str[i];
    dest[i] = '\0';
    free(str);
    return (dest);
}

static char *clear_end(char *line)
{
    int end = my_strlen(line);

    for (; end >= 0 && line[end] != '*'; end--)
        line[end] = '\0';
    return (adjust_str(line));
}

char **epur_shape(char **shape)
{
    for (unsigned int i = 0; shape[i] != NULL; i++)
        shape[i] = clear_end(shape[i]);
    return (shape);
}