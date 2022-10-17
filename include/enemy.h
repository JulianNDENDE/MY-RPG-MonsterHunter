/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** enemy
*/

#ifndef ENEMY_H_
#define ENEMY_H_

#include "structure.h"

enemy_t **get_enemies(char **map, main_t *main);
void update_ennemy(main_t *main);
int shoot(main_t *main, enemy_t *enemy);
int spray_shoot(main_t *main, enemy_t *enemy);
void enemy_manager(enemy_t *enemy, main_t *main);
int is_enemy_collide(sfIntRect *box, enemy_t *character, sfVector2f move);
int loop_ennemy(main_t *main);
void move_enemy(main_t *main, enemy_t *enemy);
int enemy_check_colide_box(main_t *main, enemy_t *enemy);
int random_move(enemy_t *enemy);
void follow_player(enemy_t *enemy, main_t *main);
int boss_shoot(main_t *main, enemy_t *enemy);
int boss_nova(main_t *main, enemy_t *enemy);
int normal_shoot(main_t *main, enemy_t *enemy);

#endif /* !ENEMY_H_ */
