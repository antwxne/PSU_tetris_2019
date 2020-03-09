/*
** EPITECH PROJECT, 2019
** base
** File description:
** display int number into base number
*/

void redirect_all_std(void);

void my_putchar(char c);

void base_number(unsigned int nb, int base)
{
    int a;

    if (nb >= base) {
        a = nb%base;
        nb = nb/base;
        a = a+48;
        base_number(nb, base);
        my_putchar(a);
    } else {
        a = nb+48;
        my_putchar(a);
    }
}
