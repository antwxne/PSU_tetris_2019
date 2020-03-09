/*
** EPITECH PROJECT, 2019
** get nbr
** File description:
** get nbr
*/

int norme(char const *str, int a, int i)
{
    while (str[i] >= 48 && str[i] <= 57) {
        a = a * 10 + (str[i] - 48);
        i++;
    }
    return (a);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int a = 0;
    int minus = 1;

    while (str[i] != 0) {
        if (str[i] == '-')
            minus = minus * (-1);
        if (str[i] >= 48 && str[i] <= 57) {
            a = norme(str, a, i);
            return (a * minus);
        } else
            i++;}
    return (0);
}
