/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** open_folder
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "struct.h"
#include "my.h"

int open_file(list_t **list)
{
    char *filepath;
    size_t buff_size = 0;

    for (list_t *temp = *list; temp != NULL; temp = temp->next) {
        filepath = my_strcat("tetriminos/", temp->info.filepath);
        temp->info.fd = fopen(filepath, "r");
        free(filepath);
        if (temp->info.fd == NULL)
            return (-1);
        temp->info.buffer = NULL;
        getline(&temp->info.buffer, &buff_size, temp->info.fd);
    }
    return (0);
}

int check_name(char *name)
{
    int i = 0;
    char *checking = NULL;

    for (; name[i] != 0; i++)
        if (name[i] == '.') {
            checking = &name[i];
            break;
        }
    if (checking != NULL)
        if (my_strcmp(checking, ".tetrimino") == 0)
            return (1);
    return (0);
}

int read_folder(DIR *dir, list_t **list)
{
    list_t *element;
    struct dirent *dent;

    for (; (dent = readdir(dir)) != NULL;) {
        if (dent->d_type == 8 && check_name(dent->d_name)) {
            element = malloc(sizeof(*element));
            if (element == NULL)
                return (-1);
            element->info.filepath = dent->d_name;
            element->next = *list;
            *list = element;
        }
    }
    return (0);
}

int open_folder(list_t **list, DIR *dir)
{
    if (dir == NULL) {
        closedir(dir);
        return (-1);
    }
    if (read_folder(dir, list) == -1) {
        closedir(dir);
        return (-1);
    }
    return (open_file(list));
}
