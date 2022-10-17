/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** enemy_action
*/

#include <stdlib.h>
#include <math.h>
#include "structure.h"
#include "my_rpg.h"
#include "param.h"

static void simple_follow(enemy_t *enemy)
{
    if (enemy->move.x > 5)
        enemy->move.x = 5;
    if (enemy->move.x < -5)
        enemy->move.x = -5;
    if (enemy->move.y > 5)
        enemy->move.y = 5;
    if (enemy->move.y < -5)
        enemy->move.y = -5;
}

void follow_player(enemy_t *enemy, main_t *main)
{
    enemy->move.x = CHARACT.pos.x - enemy->pos.x;
    enemy->move.y = CHARACT.pos.y - enemy->pos.y;
    simple_follow(enemy);
    if (enemy->move.x * enemy->speed + enemy->pos.x > CHARACT.pos.x && \
            enemy->move.x > 0)
        enemy->move.x = enemy->move.x + \
            (enemy->move.x - enemy->move.x * enemy->speed);
    if (enemy->move.x * enemy->speed + enemy->pos.x < CHARACT.pos.x && \
            enemy->move.x < 0)
        enemy->move.x = enemy->move.x + \
            (enemy->move.x - enemy->move.x * enemy->speed);
    if (enemy->move.y * enemy->speed + enemy->pos.y > CHARACT.pos.y && \
            enemy->move.y > 0)
        enemy->move.y = enemy->move.y + \
            (enemy->move.y - enemy->move.y * enemy->speed);
    if (enemy->move.y * enemy->speed + enemy->pos.y < CHARACT.pos.y && \
            enemy->move.y < 0)
        enemy->move.y = enemy->move.y + \
            (enemy->move.y - enemy->move.y * enemy->speed);
}