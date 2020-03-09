/*
** EPITECH PROJECT, 2019
** sum_stdarg
** File description:
** returns the sum of the size of the last nb
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int my_strlen(char *str);

int sum_stdarg(int i, int nb, ...)
{
    int result = 0;
    va_list list;

    va_start(list, nb);
    if (i == 0) {
        for (; nb > 0; nb--)
            result = result + va_arg(list, int);
        va_end(list);
        return (result);
    } else if (i == 1) {
        for (; nb > 0; nb--)
            result = result+my_strlen(va_arg(list, char *));
        va_end(list);
        return (result);
    } else
        return (0);
}
