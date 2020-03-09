/*
** EPITECH PROJECT, 2020
** lib
** File description:
** free arr
*/

#include <stdlib.h>

void my_free_arr(char **arr, int start)
{
    for (; arr[start] != NULL; start++)
        free(arr[start]);
    free(arr);
}
