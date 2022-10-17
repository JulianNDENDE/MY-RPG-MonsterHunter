/*
** EPITECH PROJECT, 2020
** my char is num
** File description:
** tell if a char is a num
*/

int my_char_isnum(char const c)
{
    if (c > 47 && c < 58)
        return (1);
    else
        return (0);
}
