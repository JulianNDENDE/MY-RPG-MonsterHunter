/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** get_fonc
*/

#include "my_rpg.h"
#include <stdlib.h>

void get_rect_teleporter(sfIntRect *rect, char value, \
                            sfVector2i pos, config_t config)
{
    if (value == '1')
        rect[0] = (sfIntRect){MAP_FORMAT * pos.x, MAP_FORMAT * pos.y + \
                            MAP_FORMAT / 6, MAP_FORMAT, MAP_FORMAT};
    if (value == '2')
        rect[1] = (sfIntRect){MAP_FORMAT * pos.x + MAP_FORMAT/2, \
                            MAP_FORMAT * pos.y, MAP_FORMAT, MAP_FORMAT};
    if (value == '3')
        rect[2] = (sfIntRect){MAP_FORMAT * pos.x, \
            MAP_FORMAT * pos.y + MAP_FORMAT / 3, MAP_FORMAT, MAP_FORMAT};
    if (value == '4')
        rect[3] = (sfIntRect){MAP_FORMAT * pos.x - MAP_FORMAT / 2, \
                            MAP_FORMAT * pos.y, MAP_FORMAT, MAP_FORMAT};
    if (value == 'I')
        rect[4] = (sfIntRect){MAP_FORMAT * pos.x, MAP_FORMAT * pos.y, \
                            MAP_FORMAT, MAP_FORMAT};
}

sfIntRect *get_teleporters(char **map, config_t config)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect) * 5);
    for (int i = 0; i < 5; i++)
        rect[i] = (sfIntRect){-1, -1, -1, -1};
    for (int y = 0; map[y] != NULL; y++) {
        for (int x = 0; map[y][x] != '\0'; x++) {
            get_rect_teleporter(rect, map[y][x], (sfVector2i){x, y}, config);
        }
    }
    return (rect);
}