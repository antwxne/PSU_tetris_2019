/*
** EPITECH PROJECT, 2019
** ncat
** File description:
** ncat
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int n = 0;
    int i = 0;

    while (dest[i] != '\0') {
        i++;
    }
    while (n < nb) {
        dest[i] = src[n];
        i++;
        n++;
    }
    return (dest);
}
