/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** init
*/

#include <stdlib.h>
#include "enemy.h"

void init_spe_enemy(enemy_t *enemy, int floor)
{
    if (floor == 2)
        enemy->pv = 200;
    else
        enemy->pv = 100;
    if (floor == 1)
        enemy->isaboss = 4;
    else
        enemy->isaboss = 0;
    enemy->speed = 0.8;
    enemy->pv_max = 100;
    enemy->coins = 0;
    enemy->atk_dmg = 10;
    enemy->next = 400;
    enemy->loop = 0;
}

enemy_t *init_enemy(const assets_t assets, int x, int y, int floor)
{
    enemy_t *enemy = malloc(sizeof(enemy_t) * 1);

    enemy->pos = (sfVector2f){x * 128, y *128};
    if (floor == 1)
        enemy->sprite = create_sprite(V2F(0, 0), V2F(128, 128), assets.enemy);
    else
        enemy->sprite = create_sprite(V2F(0, 0), V2F(128, 128), assets.mob);
    enemy->size = sfSprite_getGlobalBounds(enemy->sprite);
    enemy->clock = sfClock_create();
    init_spe_enemy(enemy, floor);
    enemy->move = V2F(0, 0);
    sfSprite_setOrigin(enemy->sprite, \
                        V2F(enemy->size.width / 2, enemy->size.height / 2));
    return enemy;
}

enemy_t **get_enemies(char **map, main_t *main)
{
    int nbr = 0;
    int i = 0;
    enemy_t **enemies;

    PARSE_MAP(map)
        if (map[y][x] == '*')
            nbr += 1;
    enemies = malloc(sizeof(enemy_t *) * (nbr + 1));
    enemies[nbr] = NULL;
    PARSE_MAP(map) {
        if (map[y][x] == '*') {
            enemies[i] = init_enemy(main->assets, x, y, main->map.floor);
            i += 1;
        }
    }
    return (enemies);
}