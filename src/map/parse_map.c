/*
** EPITECH PROJECT, 2020
** GAME
** File description:
** GAME
*/

#include "my_rpg.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int get_len_line(char *str)
{
    int i = 0;
    while (str[i] != '\n' && str[i] != '\0') {
        i += 1;
    }
    return (i);
}

char *get_line(char *str)
{
    int i = 0;
    char *new_str = malloc(sizeof(char) * (get_len_line(str) + 1));
    while (str[i] != '\n' && str[i] != '\0') {
        new_str[i] = str[i];
        i += 1;
    }
    new_str[i] = '\0';
    return (new_str);
}

int get_nb_lines(char *map)
{
    int lines = 1;
    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == '\n')
            lines += 1;
    }
    return (lines);
}

char **parse_map(char *map)
{
    char **tab;
    int i = 0;
    int x = 0;
    int nb_lines = get_nb_lines(map);
    tab = malloc(sizeof(char *) * (nb_lines + 1));
    while (i < nb_lines) {
        tab[i] = get_line(&map[x]);
        x += get_len_line(&map[x]) + 1;
        i += 1;
    }
    tab[i] = NULL;
    return (tab);
}