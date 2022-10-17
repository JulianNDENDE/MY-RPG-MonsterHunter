/*
** EPITECH PROJECT, 2020
** get str
** File description:
** put an int in a char
*/

#include <stdlib.h>

int my_power(int nb, int p);

int get_nbr_len(int a)
{
    int len = 0;

    while (a > 0) {
        a = a / 10;
        len++;
    }
    return (len);
}

int get_unsigned_len(unsigned int a)
{
    int len = 0;

    while (a > 0) {
        a = a / 10;
        len++;
    }
    return (len);
}

char *my_getstr(int nbr)
{
    int len = get_nbr_len(nbr);
    int print = 0;
    int j = len;
    int i = 0;
    char *dest = malloc(sizeof(char) * (len + 2));

    if (nbr <= 0) {
        dest[0] = '0';
        dest[1] = '\0';
    }
    while (i < j) {
        print = nbr / my_power(10, len - 1);
        dest[i] = print + 48;
        nbr = nbr - print * my_power(10, len - 1);
        len--;
        i++;
    }
    if (i != 0)
        dest[i] = '\0';
    return (dest);
}

char *my_get_unsigned_str(unsigned int nbr)
{
    int len = get_unsigned_len(nbr);
    unsigned int print = 0;
    int j = len;
    int i = 0;
    char *dest = malloc(sizeof(char) * (len + 2));

    if (nbr == 0) {
        dest[0] = '0';
        dest[1] = '\0';
    }
    while (i < j) {
        print = nbr / my_power(10, len - 1);
        dest[i] = print + 48;
        nbr = nbr - print * my_power(10, len - 1);
        len--;
        i++;
    }
    if (i != 0)
        dest[i] = '\0';
    return (dest);
}
