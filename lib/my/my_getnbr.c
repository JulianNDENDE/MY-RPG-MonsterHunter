/*
** EPITECH PROJECT, 2020
** my getnbr
** File description:
** keep the number in a str
*/

int my_power(int nb, int p);

long my_getnbr(char const *str)
{
    long nb = 0;
    int i = 0;
    int p = 0;

    while (str[i] == '-' || str[i] == '+' || str[i] > 47 && str[i] < 58) {
        if (str[i] == '\0' || i == 10)
            return (0);
        i++;
    }
    i--;
    while (i >= 0) {
        if (str[i] == '-')
            nb = nb * (-1);
        else
            nb = nb + (str[i] - 48)* my_power(10, p);
        i--;
        p++;
    }
    return (nb);
}
