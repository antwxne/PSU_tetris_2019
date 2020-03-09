/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** ncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    for (; i <= n && s1[i] == s2[i]; i++);
    return (s1[i] - s2[i]);
}