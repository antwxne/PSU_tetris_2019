/*
** EPITECH PROJECT, 2020
** wrong
** File description:
** wrong
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void error(int i, char **av)
{
    if (av[i][1] != 'h' && av[i][1] != 'L' && av[i][1] != 'l' &&
        av[i][1] != 'r' && av[i][1] != 't' && av[i][1] != 'd' &&
        av[i][1] != 'q' && av[i][1] != 'p' && av[i][1] != 'm' &&
        av[i][1] != 'w' && av[i][1] != 'D')
        exit(84);
}

void check_wrong(int ac, char **av)
{
    if (ac != 1 && av[1][0] != '-')
        exit(84);
    for (int i = 0; i != ac; i++)
        if (av[i][0] == '-' && av[i][1] != '-')
            error(i, av);
}
