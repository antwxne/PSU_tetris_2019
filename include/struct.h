/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct size {
    int x;
    int y;
} size_tetri_t;

typedef struct list
{
    int error;
    struct stat *stat;
    struct size size;
    char *buffer;
    char *filepath;
    char *name;
    char *shape;
    struct list *next;
} list_t;

#endif /* !STRUCT_H_ */
