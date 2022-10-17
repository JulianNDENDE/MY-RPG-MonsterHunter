/*
** EPITECH PROJECT, 2020
** my str len
** File description:
** return the len of a string
*/

int my_strlen(char const *str)
{
    int rt = 0;

    for (int i = 0; str[i] != '\0'; i++)
        rt++;
    return (rt);
}

int my_arraylen(char **array)
{
    int i = 0;

    while (array[i] != 0)
        i++;
    return (i);
}