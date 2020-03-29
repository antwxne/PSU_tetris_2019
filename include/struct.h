/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <curses.h>
#include <stdbool.h>
#include <stdio.h>

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

enum window {
    BOARD,
    TETRIMINO,
};

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

typedef struct touch
{
    enum keys key;
    char **touching;
    int *change;
    int *keys;
    int print_debug;
    int next_hide;
}touch_t;

typedef struct list
{
    info_t info;
    struct list *next;
} list_t;

typedef struct tetrimino {
    char **shape;
    size_tetri_t size;
    size_tetri_t pos;
    int color;
} tetrimino_t;

typedef struct game {
    char **board;
    size_tetri_t size_b;
    size_tetri_t size_w;
    unsigned int score;
    unsigned int level;
    tetrimino_t *tetri;
    WINDOW **windows;
    int len_list;
    int current;
} game_t;

#endif /* !STRUCT_H_ */
