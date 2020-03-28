/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** load_tetrimino_game
*/

#include <stdlib.h>
#include "struct.h"
#include "my.h"

static int len_shape(char **shape)
{
    int len = 0;

    for (; shape[len] != NULL; len++);
    return (len);
}

static char **create_new_shape(char **shape)
{
    char **dest = malloc(sizeof(char *) *(len_shape(shape) + 1));
    int i = 0;

    if (dest == NULL)
        return (NULL);
    for (; shape[i] != NULL; i++)
        dest[i] = my_strdup(shape[i]);
    dest[i] = NULL;
    return (dest);
}

tetrimino_t loading_tetrimino(game_t game, list_t const *list,
    int const len_list)
{
    int random = 0;
    tetrimino_t tetri = {0};

    for (list_t const *temp = list; 1; temp = list) {
        random = rand() % len_list;
        for (int i = 0; i < random && temp != NULL; i++, temp = temp->next);
        if (temp  != NULL)
            if (temp->info.error) {
                tetri.shape = create_new_shape(temp->info.shape);
                tetri.size = temp->info.size;
                tetri.color = temp->info.color;
                tetri.pos.y = 0;
                tetri.pos.x = (game.size_b.x / 2) - 1;
                break;
            }
    }
    return (tetri);
}