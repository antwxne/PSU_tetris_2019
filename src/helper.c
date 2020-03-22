/*
** EPITECH PROJECT, 2020
** help
** File description:
** helper
*/

#include <stdio.h>
#include <stdlib.h>

void helper(void)
{
    printf("Usage:  ./tetris [option]\n");
    printf("Options:\n");
    printf("--help                Display this help\n");
    printf("-L --level={num}      Start Tetris at level num (def: 1)\n");
    printf("-l --key-left={K}     Move the tetrimino LEFT using the K key (def: left arrow)\n");
    printf("-r --key-right={K}    Move the tetrimino RIGHT using the K key (def: right arrow)\n");
    printf("-t --key-turn={K}     TURN the tetrimino clockwise 90d using the K key (def: top arrow)\n");
    printf("-d --key-drop={K}     DROP the tetrimino using the K key (def: down arrow)\n");
    printf("-q --key-quit={K}     QUIT the game using the K key (def: 'q' key)\n");
    printf("-p --key-pause={K}    PAUSE/RESTART the game using the K key (def: space bar)\n");
    printf("--map-size={row,col}  Set the numbers of rows and columns of the map (def: 20,10)\n");
    printf("-w --without-next     Hide next tetrimino (def: false)\n");
    printf("-D --debug            Debug mode (def: false)\n");
}
