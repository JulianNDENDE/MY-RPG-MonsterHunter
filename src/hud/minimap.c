/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** minimap
*/

#include "hud.h"
#include "param.h"
#include <stdlib.h>

void reload_minimap(minimap_t *map, int width, int height)
{
    FOR_FOR(width, height)
        if (map->minimap[y][x] != NULL) {
            sfRectangleShape_destroy(map->minimap[y][x]);
            map->minimap[y][x] = NULL;
        }
    map->x = width/2;
    map->y = height/2;
    map->minimap[height/2][width/2] = sfRectangleShape_create();
    sfRectangleShape_setSize(map->minimap[height/2][width/2], \
                            (sfVector2f){8, 8});
    sfRectangleShape_setFillColor(map->minimap[height/2][width/2], sfRed);
}

void update_minimap(minimap_t *map, int move_x, int move_y)
{
    if (!map)
        return;
    sfRectangleShape_setFillColor(map->minimap[map->y][map->x], sfBlue);
    map->x = map->x + move_x;
    map->y = map->y + move_y;
    if (map->minimap[map->y][map->x] == NULL) {
        map->minimap[map->y][map->x] = sfRectangleShape_create();
        sfRectangleShape_setSize(map->minimap[map->y][map->x], \
                                (sfVector2f){8, 8});
    }
    sfRectangleShape_setFillColor(map->minimap[map->y][map->x], sfRed);
}

void print_minimap(minimap_t *map, sfRenderWindow *window, config_t config)
{
    int count = 0;
    sfRenderWindow_drawRectangleShape(window, map->background, NULL);
    FOR_FOR(map->width, map->height)
        if (map->minimap[y][x] != NULL) {
            sfRectangleShape_setPosition(map->minimap[y][x], \
                            (sfVector2f){windowx - 130 + 11 * x, 11 + 10 * y});
            sfRenderWindow_drawRectangleShape(window, map->minimap[y][x], NULL);
            count += 1;
        }
    if (map->count != count)
        map->count = count;
}

static sfRectangleShape ***get_core(int width, int height)
{
    sfRectangleShape ***minimap = malloc(
                        sizeof(sfRectangleShape **) * (height + 1));

    for (int y = 0; y < height; y++) {
        minimap[y] = malloc(sizeof(sfRectangleShape *) * (width + 1));
        for (int x = 0; x < width; x++)
            minimap[y][x] = NULL;
    }
    minimap[height/2][width/2] = sfRectangleShape_create();
    sfRectangleShape_setSize(minimap[height/2][width/2], (sfVector2f){8, 8});
    sfRectangleShape_setFillColor(minimap[height/2][width/2], sfRed);
    return minimap;
}

minimap_t *init_minimap(int width, int height, main_t *main)
{
    minimap_t *map = malloc(sizeof(minimap_t));

    map->background = sfRectangleShape_create();
    sfRectangleShape_setSize(map->background, (sfVector2f) {120, 120});
    sfRectangleShape_setFillColor(map->background, (sfColor) {0, 0, 0, 100});
    sfRectangleShape_setPosition(map->background, \
                                (sfVector2f){main->windowx - 130, 10});
    map->minimap = get_core(width, height);
    map->x = width/2;
    map->y = height/2;
    map->width = width;
    map->height = height;
    map->count = 0;
    return (map);
}