/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** special_lvl
*/

#include <stdlib.h>
#include "map.h"
#include "enemy.h"

map_t **get_hub(void)
{
    char **maps[] = {parse_map(open_map("assets/maps/hub_m")),
                    parse_map(open_map("assets/maps/hub_l")),
                    parse_map(open_map("assets/maps/a1")),
                    parse_map(open_map("assets/maps/hub_r"))};
    map_t **lvl = malloc(sizeof(map_t *) * 4);
    for (int y = 0; y < 3; y++) {
        lvl[y] = malloc(sizeof(map_t) * 4);
        for (int x = 0; x < 3; x++) {
            lvl[y][x].map = NULL;
            lvl[y][x].passed = sfTrue;
            lvl[y][x].enemy = NULL;
            lvl[y][x].pnj = NULL;
            lvl[y][x].print_tp = 0;
        }
    }
    lvl[1][1].map = maps[0];
    lvl[1][0].map = maps[1];
    lvl[2][1].map = maps[2];
    lvl[1][2].map = maps[3];
    return (lvl);
}

map_t **get_boss_1(main_t *main)
{
    char **maps[] = {parse_map(open_map("assets/maps/boss_1")),
                    parse_map(open_map("assets/maps/pre_boss"))};
    map_t **lvl = malloc(sizeof(map_t *) * 3);
    for (int y = 0; y < 2; y++) {
        lvl[y] = malloc(sizeof(map_t) * 2);
        lvl[y][0].map = maps[y];
        lvl[y][0].passed = sfFalse;
        lvl[y][0].pnj = NULL;
        lvl[y][0].print_tp = 0;
        lvl[y][0].enemy = NULL;
    }
    lvl[1][0].passed = sfTrue;
    lvl[0][0].enemy = get_enemies(lvl[0][0].map, main);
    sfSprite_setTexture(lvl[0][0].enemy[0]->sprite, main->assets.boss, sfTrue);
    sfSprite_setTextureRect(lvl[0][0].enemy[0]->sprite, R2I(96, 0, 96, 96));
    sfSprite_setScale(lvl[0][0].enemy[0]->sprite, V2F(2, 2));
    lvl[0][0].enemy[0]->isaboss = 1;
    lvl[0][0].enemy[0]->pv = 2000;
    lvl[0][0].enemy[0]->pv_max = 2000;
    return (lvl);
}

map_t **get_boss_2(main_t *main)
{
    char **maps[] = {parse_map(open_map("assets/maps/boss_2")),
                    parse_map(open_map("assets/maps/pre_boss"))};
    map_t **lvl = malloc(sizeof(map_t *) * 3);
    for (int y = 0; y < 2; y++) {
        lvl[y] = malloc(sizeof(map_t) * 2);
        lvl[y][0].map = maps[y];
        lvl[y][0].passed = sfFalse;
        lvl[y][0].pnj = NULL;
        lvl[y][0].print_tp = 0;
        lvl[y][0].enemy = NULL;
    }
    lvl[1][0].passed = sfTrue;
    lvl[0][0].enemy = get_enemies(lvl[0][0].map, main);
    lvl[0][0].enemy[0]->isaboss = 2;
    lvl[0][0].enemy[0]->pv = 4000;
    lvl[0][0].enemy[0]->speed = 1.4;
    lvl[0][0].enemy[0]->pv_max = 4000;
    return (lvl);
}

map_t **get_boss_3(main_t *main)
{
    char **maps[] = {parse_map(open_map("assets/maps/boss_3")),
                    parse_map(open_map("assets/maps/pre_boss"))};
    map_t **lvl = malloc(sizeof(map_t *) * 3);
    for (int y = 0; y < 2; y++) {
        lvl[y] = malloc(sizeof(map_t) * 2);
        lvl[y][0].map = maps[y];
        lvl[y][0].passed = sfFalse;
        lvl[y][0].pnj = NULL;
        lvl[y][0].print_tp = 0;
        lvl[y][0].enemy = NULL;
    }
    lvl[1][0].passed = sfTrue;
    lvl[0][0].enemy = get_enemies(lvl[0][0].map, main);
    sfSprite_setTexture(lvl[0][0].enemy[0]->sprite, main->assets.boss, sfTrue);
    sfSprite_setTextureRect(lvl[0][0].enemy[0]->sprite, R2I(96, 0, 96, 96));
    sfSprite_setScale(lvl[0][0].enemy[0]->sprite, V2F(2, 2));
    lvl[0][0].enemy[0]->isaboss = 3;
    lvl[0][0].enemy[0]->pv = 8000;
    lvl[0][0].enemy[0]->pv_max = 8000;
    return (lvl);
}