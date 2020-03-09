/*
** EPITECH PROJECT, 2019
** disp_starg
** File description:
** display the argument followed by '\n'
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void my_put_non_print(char *str);

void my_put_nbr(int nb);

void my_putchar(char c);

void my_putstr(char const *str);

void base_number(int nb, int base);

int disp_stdarg3(char *s, va_list list);

int disp_stdarg2(char *s, va_list list);

int disp_stdarg(char *s, ...)
{
    va_list list;

    va_start(list, s);
    if (s[0] == 'd' || s[0] == 'i') {
        my_put_nbr(va_arg(list, int));
        return (0);
    }
    if (s[0] == 's') {
        my_putstr(va_arg(list, char *));
        return (0);
    }
    if (s[0] == 'c') {
        my_putchar(va_arg(list, int));
        return (0);
    }
    disp_stdarg2(s, list);
}

int disp_stdarg2(char *s, va_list list)
{
    if (s[0] == 'b') {
        base_number(va_arg(list, unsigned int), 2);
        return (0);
    }
    if (s[0] == 'u') {
        base_number(va_arg(list, unsigned int), 10);
        return (0);
    }
    if (s[0] == 'o') {
        base_number(va_arg(list, unsigned int), 8);
        return (0);
    }
    disp_stdarg3(s, list);

}

int disp_stdarg3(char *s, va_list list)
{
    if (s[0] != 'd' || s[0] != 'i' || s[0] != 's' ||
        s[0] != 'c' || s[0] != 'b' || s[0] != 'u' || s[0] != 'o') {
        my_putchar('%');
        my_putstr(s);
    }va_end(list);
}
