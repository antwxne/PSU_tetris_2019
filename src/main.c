/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** main
*/

#include <stdlib.h>
#include "tetris.h"

void display(list_t *list)
{
    for (list_t *temp = list; temp != NULL; temp = temp->next)
        printf("name == %s\n", temp->buffer);
}

int main(void)
{
    list_t *list = NULL;
    int ret = open_folder(&list);
    display(list);
    return (ret == 0 ? 0 : 84);
}
