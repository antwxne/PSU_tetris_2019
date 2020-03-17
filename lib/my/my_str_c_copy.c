/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** my_str_c_copy
*/

#include <stdlib.h>

static int my_len_custom(char const *str, char c)
{
    int len = 0;

    for (; str[len] != c; len++);
    return (len);
}

char *my_str_c_copy(char const *str, char c)
{
    int len = my_len_custom(str, c);
    char *dest = malloc(sizeof(char) * (len + 1));
    int i = 0;

    if (dest == NULL)
        return (NULL);
    for (; str[i] != c; i++)
        dest[i] = str[i];
    dest[i] = 0;
    return (dest);
}