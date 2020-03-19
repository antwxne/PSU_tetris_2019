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
#include "struct.h"
#include "my.h"

char *load_buff(char *buff)
{
    char *dest = malloc(sizeof(char)*(my_strlen(buff) + 1));
    int i = 0;

    if (dest == NULL)
        return (NULL);
    for (; buff[i] != 0; i++)
        dest[i] = buff[i];
    dest[i] = 0;
    return (dest);
}

int open_file(list_t **list)
{
    int fd = 0;
    char buff[256];
    int size = 0;
    char *filepath;

    for (list_t *temp = *list; temp != NULL; temp = temp->next) {
        filepath = my_strcat("tetriminos/", temp->info.filepath);
        fd = open(filepath, O_RDONLY);
        free(filepath);
        if (fd == -1)
            return (-1);
        size = read(fd, buff, 255);
        if (size == -1)
            return (-1);
        buff[size] = 0;
        temp->info.buffer = load_buff(buff);
        if (temp->info.buffer == NULL)
            return (-1);
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
    struct stat sb;

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

int open_folder(list_t **list)
{
    DIR *dir = opendir("./tetriminos");

    if (dir == NULL) {
        closedir(dir);
        return (-1);
    }
    if (read_folder(dir, list) == -1)
        return (-1);
    return (open_file(list));
}
