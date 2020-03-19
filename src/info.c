/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** class
*/

#include <stdlib.h>
#include "struct.h"
#include "tetris.h"
#include "my.h"

static inline char *get_name(char *filepath)
{
    int i = 0;
    int len = 0;
    char *dest;

    for (; filepath[len] != '.'; len++);
    dest = malloc(sizeof(char) * (len + 1));
    if (dest == NULL)
        return (NULL);
    for (; filepath[i] != '.'; i++)
        dest[i] = filepath[i];
    dest[i] = '\0';
    return (dest);
}

static inline size_tetri_t get_size(char *buff)
{
    size_tetri_t size = {0, 0};
    char *temp;
    int i = 0;

    size.x = my_getnbr(buff);
    for (; buff[i] != ' '; i++);
    temp = &buff[i];
    size.y = my_getnbr(temp);
    return (size);
}

static inline char *get_shape(char *buff)
{
    char *temp;
    char *shape;
    int start = 0;
    int i = 0;

    for (; buff[start] != '\n'; start++);
    temp = &buff[start + 1];
    shape = malloc(sizeof(char) * (my_strlen(temp) + 1));
    if (shape == NULL)
        return (NULL);
    for (; temp[i] != '\0'; i++)
        shape[i] = temp[i];
    shape[i] = '\0';
    return (my_epur_str(shape));
}

static inline int get_color(char *buff)
{
    char *temp;
    int color;
    int i = 0;

    for (; buff[i] != ' '; i++);
    for (; buff[i] != ' '; i++);
    temp = &buff[i + 2];
    color = my_getnbr(temp);
    return (color);
}

void get_info(list_t **list)
{
    for (list_t *temp = *list; temp != NULL; temp = temp->next) {
        temp->info.name = get_name(temp->info.filepath);
        temp->info.error = error_tetri(temp->info.buffer);
        if (temp->info.error == true) {
            temp->info.size = get_size(temp->info.buffer);
            temp->info.color = get_color(temp->info.buffer);
            temp->info.shape = get_shape(temp->info.buffer);
        }
        free(temp->info.buffer);
    }
    sorting_list(list);
}