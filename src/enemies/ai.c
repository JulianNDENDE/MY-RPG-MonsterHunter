/*
** EPITECH PROJECT, 2021
** ai.c
** File description:
** ai move function
*/

#include <stdlib.h>
#include <math.h>
#include "structure.h"
#include "my_rpg.h"
#include "param.h"

int random_move(enemy_t *enemy)
{
    enemy->move.x = (rand() % 21) - 10;
    enemy->move.y = (rand() % 21) - 10;
    return (0);
}

void move_enemy(main_t *main, enemy_t *enemy)
{
    float temp = 0;
    if (enemy_check_colide_box(main, enemy) != 1) {
        enemy->pos.x = enemy->pos.x + enemy->move.x * enemy->speed;
        enemy->pos.y = enemy->pos.y + enemy->move.y * enemy->speed;
    } else {
        temp = enemy->move.x;
        enemy->move.x = 0;
        if (enemy_check_colide_box(main, enemy) != 1) {
            enemy->pos.y = enemy->pos.y + enemy->move.y * enemy->speed;
        }
        enemy->move.x = temp;
        temp = enemy->move.y;
        enemy->move.y = 0;
        if (enemy_check_colide_box(main, enemy) != 1)
            enemy->pos.x = enemy->pos.x + enemy->move.x * enemy->speed;
    }
}

void update_enemy_two(main_t *main, int enemy_left)
{
    if (enemy_left == 0) {
        CURENT_MAP.enemy = NULL;
        if (main->minimap == NULL ||
            (main->minimap->count != MAP.room && main->minimap->count == 10))
            CURENT_MAP.print_tp = 1;
        if (main->minimap != NULL)
            MAP.room = main->minimap->count;
    }
}

void update_ennemy(main_t *main)
{
    int enemy_left = 0;

    if (CURENT_MAP.passed == sfTrue)
        return;
    if (!CURENT_MAP.enemy) {
        main->bonus = spawn_bonus(main);
        CURENT_MAP.passed = sfTrue;
        return;
    }
    PARSE_ARRAY(CURENT_MAP.enemy) {
        if (CURENT_MAP.enemy[i]->sprite != NULL) {
            enemy_manager(CURENT_MAP.enemy[i], main);
            if (CURENT_MAP.enemy[i]->pv <= 0) {
                sfSprite_destroy(CURENT_MAP.enemy[i]->sprite);
                CURENT_MAP.enemy[i]->sprite = NULL;
            }
            enemy_left++;
        }
    }
    update_enemy_two(main, enemy_left);
}

void enemy_check_colide(main_t *main, particle_t *particle)
{
    sfFloatRect enemy;
    sfFloatRect hitbox = sfCircleShape_getGlobalBounds(particle->shape);
    int damage = sfCircleShape_getRadius(particle->shape) * 2;

    PARSE_ARRAY(CURENT_MAP.enemy) {
        if (CURENT_MAP.enemy[i]->sprite != NULL) {
            enemy = sfSprite_getGlobalBounds(CURENT_MAP.enemy[i]->sprite);
            if (sfFloatRect_intersects(&hitbox, &enemy, NULL)) {
                CURENT_MAP.enemy[i]->pv -= damage;
                SPAWN_DAMAGE(&PROJ.wait_list, enemy.left + CAM.cam_pos.x, \
                enemy.top + CAM.cam_pos.y, damage, main->assets.font);
                sfClock_destroy(particle->life);
                particle->life = NULL;
            }
        }
    }
}