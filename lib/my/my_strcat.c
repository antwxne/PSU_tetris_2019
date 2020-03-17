/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** my_strcat
*/

#include <stdlib.h>

int my_strlen(char *str);

char *my_strdup(char const *str);

char *my_strcat(char *str1, char *str2)
{
    int len_str1 = my_strlen(str1);
    int len_str2 = my_strlen(str2);
    char *dest = malloc(sizeof(char)*(len_str1+len_str2+1));
    int a = 0;

    if (dest == NULL)
        return (NULL);
    for (int i = 0; str1[i] != 0; i++, a++)
        dest[a] = str1[i];
    for (int i = 0; str2[i] != 0; a++, i++)
        dest[a] = str2[i];
    dest[a] = 0;
    return (dest);
}