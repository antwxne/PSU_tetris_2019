/*
** EPITECH PROJECT, 2020
** lib
** File description:
** clean binary
*/

int my_strlen(char const *str);

char *clean_bin(char *bin)
{
    int len = my_strlen(bin);

    for (; len >= 0; len--) {
        if (bin[len] == '0' && bin[len - 1] == '1') {
            bin[len] = 0;
            return (bin);
        }
    }
    return (bin);
}
