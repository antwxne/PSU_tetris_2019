/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** main
*/

#include "tetris.h"
#include "my.h"

int main(void)
{
    list_t *list = NULL;
    DIR *dir = opendir("./tetriminos");
    int ret = open_folder(&list, dir);

    if (ret == 0) {
        get_info(&list);
        display_tetriminos(list);
        free_tetriminos(list);
    }
    closedir(dir);
    return (ret == 0 ? 0 : 84);
}
