/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** get_fonc
*/

#include "my_rpg.h"
#include <stdlib.h>

void get_rect_tree(sfVector2i p, sfIntRect *rect, int floor, config_t config)
{
    if (floor == 0)
        *rect = (sfIntRect){p.x * MAP_FORMAT + 30, MAP_FORMAT / \
            2 + p.y * MAP_FORMAT + 20, MAP_FORMAT - 60, MAP_FORMAT / 2 - 10};
    if (floor == 1)
        *rect = (sfIntRect){p.x * MAP_FORMAT + 40, MAP_FORMAT / \
            2 + p.y * MAP_FORMAT + 20, MAP_FORMAT - 60, MAP_FORMAT / 2 - 10};
    if (floor == 2)
        *rect = (sfIntRect){p.x * MAP_FORMAT, p.y * MAP_FORMAT + MAP_FORMAT / \
            4, MAP_FORMAT - 5, MAP_FORMAT - MAP_FORMAT / 4};
}

sfIntRect get_rect(int i, config_t config, sfVector2i pos)
{
    int f = MAP_FORMAT;
    sfIntRect rects[] = {
        (sfIntRect){pos.x * f, f / 2 + pos.y * f, f, f / 2},
        (sfIntRect){pos.x * f, pos.y * f, f, f},
        (sfIntRect){pos.x * f, pos.y * f , f / 3, f},
        (sfIntRect){pos.x * f + f * 2/3, pos.y * f, f - f * 2/3, f},
        (sfIntRect){pos.x * f, pos.y * f, f, f},
        (sfIntRect){pos.x * f, pos.y * f, f, f},
        (sfIntRect){pos.x * f, pos.y * f, f, f},
        (sfIntRect){pos.x * f, pos.y * f, f, f},
        (sfIntRect){pos.x * f, pos.y * f, f / 3, f},
        (sfIntRect){pos.x * f + f * 2/3, pos.y * f, f - f * 2/3, f},
        (sfIntRect){pos.x * f, pos.y * f + f / 2, f / 3, f / 2},
        (sfIntRect){pos.x * f + f * 2/3, pos.y * f + f / 2, 1 / 3 * f, f / 2},
        (sfIntRect){pos.x * f, pos.y * f, f, f},
        (sfIntRect){pos.x * f + f * 2/3, pos.y * f, f - f * 2/3, f},
        (sfIntRect){pos.x * f, f / 2 + pos.y * f, f, f / 2},
        (sfIntRect){pos.x * f, pos.y * f , f / 3, f}
    };
    return (rects[i]);
}

void get_rect_box(sfVector2i pos, sfVector2i type, \
                    sfIntRect *rect, config_t config)
{
    char *types = "dlhqbfABipgc1234";
    *rect = (sfIntRect) {-1, -1, -1, -1};
    if (type.x == 'X')
        get_rect_tree((sfVector2i) {pos.x, pos.y}, rect, type.y, config);
    for (int i = 0; types[i] != '\0'; i++) {
        if (type.x == types[i])
            *rect = get_rect(i, config, pos);
    }
}

sfIntRect ***get_boxes(char **map, int floor, config_t config)
{
    sfVector2i size_map = get_size_map(map);
    sfIntRect ***collisions = malloc(sizeof(sfIntRect **) * (size_map.y + 1));

    for (int y = 0; y < size_map.y; y++) {
        collisions[y] = malloc(sizeof(sfIntRect *) * (size_map.x + 2));
        for (int x = 0; x <= size_map.x; x++) {
            collisions[y][x] = malloc(sizeof(sfIntRect) * 1);
            get_rect_box((sfVector2i) {x, y}, (sfVector2i) {map[y][x], floor},
                        collisions[y][x], config);
        }
        collisions[y][size_map.x + 1] = NULL;
    }
    collisions[size_map.y] = NULL;
    return (collisions);
}