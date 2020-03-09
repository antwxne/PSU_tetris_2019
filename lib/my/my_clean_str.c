/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_clean_str
*/

#include <stdlib.h>

int my_strlen(char const *str);

static char *my_clean_tab(char *str)
{
    char *dest = malloc(sizeof(char)*my_strlen(str)+1);
    int i = 0;

    if (dest == NULL)
        return (NULL);
    for (; str[i] != '\0'; i++) {
        if (str[i] == '\t')
            dest[i] = ' ';
        else
            dest[i] = str[i];
    }
    dest[i] = '\0';
    return (dest);
}

char *my_clean_str(char *str)
{
    str = my_clean_tab(str);
    char *dest = malloc(sizeof(char)*my_strlen(str)+1);
    int i = 0;

    for (; *str == ' '; str++);
    for (; *str != 0; str++, i++) {
        dest[i] = *str;
        if (str[0] == ' ' && str[1] == ' ') {
            for (; *str == ' '; str += 1);
            str -= 1;
        }
        if (str[0] == ' ' && (str[1] == '\0' || str[1] == '\n'))
            break;
    }
    dest[i] = 0;
    return (dest);
}