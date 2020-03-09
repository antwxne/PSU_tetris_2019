/*
** EPITECH PROJECT, 2019
** put nbr
** File description:
** put nbr
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int a;

    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
        my_put_nbr(nb);
    } else if (nb >= 10) {
        a = nb % 10;
        nb = nb / 10;
        a = a + 48;
        my_put_nbr(nb);
        my_putchar(a);
    } else {
        a = nb + 48;
        my_putchar(a);
    }
}
