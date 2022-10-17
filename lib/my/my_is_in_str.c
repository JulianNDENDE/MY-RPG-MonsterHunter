/*
** EPITECH PROJECT, 2020
** is in str
** File description:
** searsh if the char is in the str
*/

int my_is_in_str(const char c, const char *str)
{
    for (int a = 0; str[a] != '\0'; a++) {
        if (c == str[a])
            return (a);
    }
    return (-1);
}