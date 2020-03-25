/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** class
*/

#include <stdlib.h>
#include <stdio.h>
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

    if (buff == NULL)
        return ((size_tetri_t){0 , 0});
    size.x = my_getnbr(buff);
    for (; buff[i] != ' '; i++);
    temp = &buff[i];
    size.y = my_getnbr(temp);
    return (size);
}

static inline char **get_shape(FILE *fd, size_tetri_t size)
{
    char **shape = malloc(sizeof(char *) * (size.y + 1));
    unsigned int i = 0;
    size_t buff_size = 0;

    if (shape == NULL)
        return (NULL);
    for (; i < size.y; i++) {
        shape[i] = NULL;
        getline(&shape[i], &buff_size, fd);
    }
    shape[i] = NULL;
    fclose(fd);
    return (shape);
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
        temp->info.error = check_first_line(temp->info.buffer);
        if (temp->info.error == true) {
            temp->info.size = get_size(temp->info.buffer);
            temp->info.color = get_color(temp->info.buffer);
            temp->info.shape = get_shape(temp->info.fd, temp->info.size);
            temp->info.error = check_shape(temp->info.shape);
        }
        free(temp->info.buffer);
    }
    sorting_list(list);
}