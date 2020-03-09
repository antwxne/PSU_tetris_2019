/*
** EPITECH PROJECT, 2019
** put str
** File description:
** put str
*/

#include <unistd.h>

int my_strlen(char const *str);

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}
