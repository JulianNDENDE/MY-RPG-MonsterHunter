/*
** EPITECH PROJECT, 2020
** my compute power rec
** File description:
** return the power
*/

int my_power(int nb, int p)
{
    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    if (p > 0) {
        nb = nb * my_power(nb, p - 1);
        return (nb);
    }
}
