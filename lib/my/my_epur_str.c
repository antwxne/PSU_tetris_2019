/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** my_epur_str
*/

#include <stdlib.h>

int my_strlen(char const *str);

static char *adjust(char *str)
{
    int len = my_strlen(str);
    char *dest = malloc(sizeof(char) * (len + 1));
    int i = 0;

    if (dest == NULL)
        return (NULL);
    for (; str[i] != '\0'; i++)
        dest[i] = str[i];
    dest[i] = '\0';
    free(str);
    return (dest);
}

static char *cp_clean(char *str, int len)
{
    char *dest = malloc(sizeof(char)*(len + 1));
    int index = 0;

    if (dest == NULL)
        return (NULL);
    for (int a = 0; a < len ; a++, index++) {
        if (str[a] == '\n') {
            dest[index] = '\n';
            index += 1;
            for (; str[a] == '\n'; a++);
        }
        dest[index] = str[a];
    }
    dest[index] = '\0';
    return (dest);
}

static char *remove_back(char *str, int i)
{
    int len = i;

    for (; i >= 0; i--)
        if (str[i] == '\n' || str[i] == '\0') {
            i -= 1;
            for (; str[i] == ' ' && i >= 0; i--)
                str[i] = '\n';
        }
    return (adjust(cp_clean(str, len)));
}

char *my_epur_str(char *str)
{
    int len = my_strlen(str);
    char *dest = malloc(sizeof(char) * (len + 1));
    int i = 0;

    if (dest == NULL)
        return (NULL);
    for (; str[i] != '\0'; i++)
        dest[i] = str[i];
    free(str);
    dest[i] = '\0';
    return (remove_back(dest, i));
}