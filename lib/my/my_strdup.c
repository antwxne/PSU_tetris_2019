/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** my_strdup
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *str)
{
    char *dest = malloc(sizeof(char) *(my_strlen(str) + 1));
    int i = 0;

    if (dest == NULL)
        return (NULL);
    for (; str[i] != 0; i++)
        dest[i] = str[i];
    dest[i] = 0;
    return (dest);
}