/*
** EPITECH PROJECT, 2020
** count lignes and colums
** File description:
** return nbr of lignes or nbr of colums
*/

int count_x(char *buff)
{
    int x = 0;

    while (buff[x] != '\n')
        x++;
    return (x);
}

int count_y(char *buff)
{
    int y = 0;
    int i = 0;

    while (buff[i] != '\0') {
        if (buff[i] == '\n')
            y++;
        i++;
    }
    return (y);
}