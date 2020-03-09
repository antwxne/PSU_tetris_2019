/*
** EPITECH PROJECT, 2019
** revstr
** File description:
** revstr
*/

int counter(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_revstr(char *str)
{
    int i = 0;
    int n;
    char s;

    n = counter(str) - 1;
    while (i < n) {
        s = str[i];
        str[i] = str[n];
        str[n] = s;
        i = i + 1;
        n = n - 1;
    }
    return (str);
}
