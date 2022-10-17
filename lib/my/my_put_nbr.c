/*
** EPITECH PROJECT, 2020
** my_put_nbr.c
** File description:
** Rush2 Maxime HAYEK & Xavier DAVID
*/

#include <stddef.h>

void my_putchar(char c);

int my_getlen(int a)
{
    int len = 0;

    if (a > 0)
        while (a > 0) {
            a = a / 10;
            len++;
        }
    else
        while (a < 0) {
            a = a / 10;
            len++;
        }
    return (len);
}

int my_get_unsigned_len(unsigned int a)
{
    int len = 0;

    while (a < 0) {
        a = a / 10;
        len++;
    }
    return (len);
}

int my_put_unsigned_nbr(unsigned long nb)
{
    int dest;

    if (nb > 9)
        my_put_unsigned_nbr(nb / 10);
    dest = (nb % 10) + 48;
    my_putchar(dest);
    return (0);
}

int my_put_nbr(int nb)
{
    int dest;

    if (nb < 0) {
        nb = nb * (-1);
        my_putchar('-');
    }
    if (nb > 9)
        my_put_nbr(nb / 10);
    dest = (nb % 10) + 48;
    my_putchar(dest);
    return (0);
}
