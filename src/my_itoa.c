/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** my_itoa
*/

#include <stdlib.h>
#include "my.h"

char *my_revstr(char *str);

char *my_itoa(int nb)
{
    char *dest = malloc(sizeof(char) * 12);
    int i = 0;
    int bool = 0;

    if (nb < 0)
        bool = 1;
    while (nb != 0) {
        dest[i] = (nb%10)+'0';
        nb /= 10;
        i += 1;
    }
    if (bool == 1) {
        dest[i] = '-';
        i += 1;
    }
    dest[i] = '\0';
    return (my_revstr(dest));
}
