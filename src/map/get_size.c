/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** game
*/

#include "my_rpg.h"
#include <stdlib.h>

int get_width_max(char *str, int width)
{
    for (int index = 0; str[index] != '\0'; index++)
        if (width < index)
            width = index;
    return (width);
}

sfVector2i get_size_map(char **map)
{
    int height = 0;
    int width = 0;
    int width_max = 0;
    while (map[height] != NULL) {
        while (map[height][width] != '\0') {
            width_max = get_width_max(map[height], width_max);
            width++;
        }
        width = 0;
        height++;
    }
    return ((sfVector2i){width_max, height});
}