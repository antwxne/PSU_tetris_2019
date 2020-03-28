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

void loading_tetrimino(game_t *game, list_t const *list,
    int const len_list)
{
    int random;

    for (list_t *temp = list; 1;) {
        random = rand() % len_list;
        for (int i = 0; i < random; i++, temp = temp->next);
        if (temp->info.error) {
            game->tetri.shape = create_new_shape(temp->info.shape);
            game->tetri.size = temp->info.size;
            game->tetri.color = temp->info.color;
            game->tetri.pos.y = 0;
            game->tetri.pos.x = (game->size_b.x / 2) - 1;
            break;
        }
    }
}