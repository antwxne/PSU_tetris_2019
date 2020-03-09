/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** my_strcmp
*/

int my_strcmp(char const *str1, char const *str2)
{
    int i = 0;

    for (;str1[i] == str2[i] && str1[i] != 0 && str2[i] != 0; i++);
    return (str1[i] - str2[i]);
}
