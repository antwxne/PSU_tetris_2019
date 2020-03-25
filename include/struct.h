/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <stdbool.h>
#include <stdio.h>

typedef struct size {
    unsigned int y;
    unsigned int x;
} size_tetri_t;

typedef struct info {
    bool error;
    FILE *fd;
    int color;
    struct stat *stat;
    size_tetri_t size;
    char *buffer;
    char *filepath;
    char *name;
    char **shape;
} info_t;

typedef struct list
{
    info_t info;
    struct list *next;
} list_t;

#endif /* !STRUCT_H_ */
