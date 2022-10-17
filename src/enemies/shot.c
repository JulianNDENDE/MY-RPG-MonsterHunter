/*
** EPITECH PROJECT, 2021
** shot.c
** File description:
** shot ai function
*/

#include <stdlib.h>
#include <math.h>
#include "structure.h"
#include "my_rpg.h"
#include "param.h"

int normal_shoot(main_t *main, enemy_t *enemy)
{
    SPAWN_TARGET(&PROJ.wait_list, enemy->pos.x, enemy->pos.y, CHARACT.pos.x, \
                CHARACT.pos.y, 15, CLASSIC_MEDIUM_YELLOW, sfFalse, 0);
    if (main->map.floor != 0)
        enemy->next = 500;
    else
        enemy->next = 1500;
    return (0);
}

int shoot(main_t *main, enemy_t *enemy)
{
    SPAWN_TARGET(&PROJ.wait_list, enemy->pos.x, enemy->pos.y, CHARACT.pos.x, \
                CHARACT.pos.y, 15, CLASSIC_MEDIUM_YELLOW, sfFalse, 0);
    SPAWN_TARGET(&PROJ.wait_list, enemy->pos.x, enemy->pos.y, \
                CHARACT.pos.x + 50, CHARACT.pos.y + 50, 15, \
                CLASSIC_MEDIUM_RED, sfFalse, 5);
    SPAWN_TARGET(&PROJ.wait_list, enemy->pos.x, enemy->pos.y, \
                CHARACT.pos.x - 50, CHARACT.pos.y - 50, 15, \
                CLASSIC_MEDIUM_RED, sfFalse, 5);
    SPAWN_TARGET(&PROJ.wait_list, enemy->pos.x, enemy->pos.y, \
                CHARACT.pos.x + 100, CHARACT.pos.y + 100, 15, \
                CLASSIC_MEDIUM_RED, sfFalse, 10);
    SPAWN_TARGET(&PROJ.wait_list, enemy->pos.x, enemy->pos.y, \
                CHARACT.pos.x - 100, CHARACT.pos.y - 100, 15, \
                CLASSIC_MEDIUM_RED, sfFalse, 10);
    enemy->next = 500;
    return (0);
}

int spray_shoot(main_t *main, enemy_t *enemy)
{
    int angle = atanf((CHARACT.pos.y - enemy->pos.y) / \
                    (CHARACT.pos.x - enemy->pos.x));
    angle = angle * 180 / M_PI;
    if (CHARACT.pos.x - enemy->pos.x < 0)
        angle += 180;
    SPAWN_SPRAY(&PROJ.wait_list, enemy->pos.x + 70, \
                enemy->pos.y + 30, angle, 10, 10, 40, \
                CLASSIC_MEDIUM_BROWN, 0);
    enemy->next = 1000;
    return (0);
}

int boss_shoot(main_t *main, enemy_t *enemy)
{
    SPAWN_CIRCLE_RIFLE(&PROJ.wait_list, enemy->pos.x, enemy->pos.y, \
                        3, 5, 11, CLASSIC_MEDIUM_YELLOW, 0, 500);
    SPAWN_CIRCLE_RIFLE_REVERSE(&PROJ.wait_list, enemy->pos.x, enemy->pos.y, \
                                3, 5, 11, CLASSIC_MEDIUM_RED, 0, 500);
    enemy->next = 1500;
    return (0);
}

int boss_nova(main_t *main, enemy_t *enemy)
{
    SPAWN_TARGET(&PROJ.wait_list, CHARACT.pos.x + 150, CHARACT.pos.y + 150, \
                CHARACT.pos.x + 100, CHARACT.pos.y + 100, 3, \
                CLASSIC_MEDIUM_PURPLE, sfFalse, 0);
    SPAWN_TARGET(&PROJ.wait_list, CHARACT.pos.x - 150, CHARACT.pos.y - 150, \
                CHARACT.pos.x - 100, CHARACT.pos.y - 100, 3, \
                CLASSIC_MEDIUM_PURPLE, sfFalse, 0);
    SPAWN_TARGET(&PROJ.wait_list, CHARACT.pos.x + 150, CHARACT.pos.y - 150, \
                CHARACT.pos.x + 100, CHARACT.pos.y - 100, 3, \
                CLASSIC_MEDIUM_PURPLE, sfFalse, 0);
    SPAWN_TARGET(&PROJ.wait_list, CHARACT.pos.x - 150, CHARACT.pos.y + 150, \
                CHARACT.pos.x - 100, CHARACT.pos.y + 100, 3, \
                CLASSIC_MEDIUM_PURPLE, sfFalse, 0);
    SPAWN_WOLOLO(&PROJ.wait_list, (int)CHARACT.pos.x, (int)CHARACT.pos.y, \
                30, 100, CLASSIC_LITLE_PURPLE , 2000);
    enemy->next = 2000;
    return (0);
}