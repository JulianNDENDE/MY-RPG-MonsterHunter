/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** enemy_action
*/

#include <stdlib.h>
#include <math.h>
#include "my_rpg.h"

static int (*fptrb[])(main_t *main, enemy_t *enemy) = {
    &shoot,
    &boss_shoot,
    &shoot,
    &boss_shoot,
    &spray_shoot,
    NULL
};

static int (*fptrbtb[])(main_t *main, enemy_t *enemy) = {
    &shoot,
    &boss_shoot,
    &boss_nova,
    &boss_nova,
    NULL
    };

static int (*fptrbt[])(main_t * main, enemy_t * enemy) = {
    &shoot,
    &boss_shoot,
    &boss_nova,
    &spray_shoot,
    &boss_shoot,
    &boss_nova,
    NULL
};

static int (*fptr[])(main_t * main, enemy_t * enemy) = {
    &normal_shoot,
    &normal_shoot,
    &normal_shoot,
    &spray_shoot,
    NULL
};

int enemy_check_colide_box(main_t *main, enemy_t *enemy)
{
    int x = floor(enemy->pos.x / main->MAP_FORMAT);
    int y = floor(enemy->pos.y / main->MAP_FORMAT);

    for (int index = 0; index < 3; index++) {
        for (int tg = 0; tg < 3; tg++) {
            if (is_enemy_collide(CAM.box[abs(y - 1) + index][abs(x - 1) + tg],
                        enemy, enemy->move) == 1)
            return (1);
        }
    }
    return (0);
}

int is_enemy_collide(sfIntRect *box, enemy_t *character, sfVector2f move)
{
    float left = character->pos.x - (character->size.width / 2);
    float down = character->pos.y + (character->size.height / 2);
    sfFloatRect rect = {box->left, box->top, box->width, box->height};
    sfFloatRect player_box = (sfFloatRect){
        left + move.x * character->speed, down - 2 + move.y * character->speed,
        character->size.width, 2};

    if (box == NULL || box->top == -1)
        return (0);
    if (sfFloatRect_intersects(&rect, &player_box, NULL))
        return 1;
    return (0);
}

void attackchoice(enemy_t *enemy, int (***choice)(main_t *main, enemy_t *enemy))
{
    *choice = fptr;
    if (enemy->isaboss == 1)
        *choice = fptrb;
    if (enemy->isaboss == 2)
        *choice = fptrbt;
    if (enemy->isaboss == 3)
        *choice = fptrbtb;
}

void enemy_manager(enemy_t *enemy, main_t *main)
{
    int (**choice)(main_t * main, enemy_t * enemy);

    attackchoice(enemy, &choice);
    if (enemy->isaboss != 4)
        follow_player(enemy, main);
    if (main->map.floor != 0 && enemy->isaboss == 0)
        enemy->speed = 1.5;
    move_enemy(main, enemy);
    if (get_Milliseconds(enemy->clock, main->clock_error) > enemy->next) {
        if (enemy->isaboss == 4)
            random_move(enemy);
        if (choice[++enemy->loop] == NULL)
            enemy->loop = 0;
        choice[enemy->loop](main, enemy);
        sfClock_restart(enemy->clock);
    }
}