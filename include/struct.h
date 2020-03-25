/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <stdbool.h>

enum keys{
    left,
    right,
    turn,
    drop,
    quit,
    pose,
    level,
    size,
};

typedef struct size {
    int x;
    int y;
} size_tetri_t;

typedef struct info {
    bool error;
    int color;
    struct stat *stat;
    size_tetri_t size;
    char *buffer;
    char *filepath;
    char *name;
    char *shape;
} info_t;

typedef struct touch
{
    enum keys key;
    char **touching;
    int *change;
    int print_debug;
    int next_hide;
}touch_t;

typedef struct list
{
    info_t info;
    struct list *next;
} list_t;

#endif /* !STRUCT_H_ */
