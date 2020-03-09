/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_printf
*/

#include <stdio.h>
#include <stdarg.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void my_putchar(char c);

void my_putstr(char const *str);

void my_put_nbr(int nb);

int disp_stdarg(char *s, ...);

void my_printf(char *str, ...)
{
    va_list list;
    char flag[1];

    va_start(list, str);
    for (int i  = 0; str[i] != 0; i++) {
        if (str[i] == '%') {
            flag[0] = str[i+1];
            disp_stdarg(flag, va_arg(list, void *));
            i += 1;
        } else
            my_putchar(str[i]);
    }
    va_end(list);
}
