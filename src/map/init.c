/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** init
*/

#include <stdlib.h>
#include "my_rpg.h"

static char *maze[] = {".X.\0", "XXX\0", ".X.\0", NULL};
static char *boss[] = {"X\0", "X\0", NULL};
static map_t **(*get_boss[])(main_t *) = {
    &get_boss_1,
    &get_boss_2,
    &get_boss_3,
    NULL
};

object_t **init_all_objects(const assets_t assets)
{
    sfIntRect rect = (sfIntRect){0, 0, 64, 128};
    sfIntRect rect2 = (sfIntRect){0, 0, 32, 32};
    sfIntRect rect3 = (sfIntRect){0, 0, 64, 96};
    object_t **tab = malloc(sizeof(object_t) * 4);
    tab[0] = init_object(assets.tree1, rect, 10, 200);
    tab[1] = init_object(assets.tree2, rect, 10, 200);
    tab[2] = init_object(assets.rock1, rect2, 6, 200);
    tab[3] = init_object(assets.pillar, rect3, 5, 200);
    sfSprite_setScale(tab[0]->sprite, (sfVector2f){2, 2});
    sfSprite_setScale(tab[1]->sprite, (sfVector2f){2, 2});
    sfSprite_setScale(tab[2]->sprite, (sfVector2f){4, 4});
    sfSprite_setScale(tab[3]->sprite, (sfVector2f){2, 2});
    return (tab);
}

void init_map(main_t *main)
{
    MAP.object = init_all_objects(main->assets);
    sfSprite_setPosition(main->assets.player, (sfVector2f) \
                        {sfRenderWindow_getSize(main->window).x / 2 - 64, \
                        sfRenderWindow_getSize(main->window).y / 2 - 128});
    MAP.floor = 0;
    MAP.maze = maze;
    MAP.lvl = get_hub();
    MAP.x = 1;
    MAP.y = 1;
    MAP.map = MAP.lvl[1][1].map;
    MAP.teleporters = get_teleporters(MAP.map, main->config);
    MAP.boxes = get_boxes(MAP.map, MAP.floor, main->config);
}

void rdm_map(main_t *main)
{
    MAP.floor++;
    MAP.room = 0;
    MAP.x = 5;
    MAP.y = 5;
    MAP.maze = make_maze(10, 10);
    MAP.lvl = get_lvl(MAP.maze, MAP.floor, main);
    MAP.map = MAP.lvl[5][5].map;
    MAP.teleporters = get_teleporters(MAP.map, main->config);
    MAP.boxes = get_boxes(MAP.map, MAP.floor, main->config);
}

void boss_map(main_t *main)
{
    MAP.x = 0;
    MAP.y = 1;
    MAP.room = 0;
    MAP.maze = boss;
    MAP.lvl = get_boss[MAP.floor](main);
    MAP.map = MAP.lvl[1][0].map;
    MAP.teleporters = get_teleporters(MAP.map, main->config);
    MAP.boxes = get_boxes(MAP.map, MAP.floor, main->config);
}

void free_maps(main_t *main)
{
    PARSE_ARRAY(MAP.boxes)
        free(MAP.boxes[i]);
    free(MAP.boxes);
    free(main->map.map);
}