/*
** EPITECH PROJECT, 2020
** key
** File description:
** press
*/

#include <termios.h>
#include <unistd.h>
#include <stdlib.h>

int key_press(void)
{
    struct termios termios;
    char *str = 0;

    str = malloc(sizeof(char) * 1);
    if (str == NULL)
        return 84;
    tcgetattr(0, &termios);
    tcsetattr(0, ICANON, &termios);
    tcdrain(0);
    read(0, str, 1);
    return 0;
}
