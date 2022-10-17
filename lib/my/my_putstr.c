/*
** EPITECH PROJECT, 2020
** my put str
** File description:
** print a string
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int i = 0;

    if (str == 0) {
        my_putstr("(null)");
        return 0;
    }
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return i;
}
