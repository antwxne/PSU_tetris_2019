/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** my_strcpy
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    int n = 0;

    while (src[i] != '\0') {
        dest[i] = src[n];
        i++;
        n++;
    }
    dest[n] = '\0';
    return (dest);
}
