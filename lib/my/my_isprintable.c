/*
** EPITECH PROJECT, 2020
** my is printable
** File description:
** test if the char is printable
*/

int my_char_isprintable(char const c)
{
    if (c > 32 && c < 127)
        return (1);
    return (0);
}