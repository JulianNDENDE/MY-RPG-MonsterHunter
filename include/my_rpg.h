/*
** EPITECH PROJECT, 2021
** my deffender
** File description:
** my_deffender
*/

#ifndef DEFFENDER_H_
#define DEFFENDER_H_

#include <math.h>
#include "my_csfml.h"
#include "structure.h"
#include "particle.h"
#include "param.h"
#include "hud.h"
#include "map.h"
#include "enemy.h"
#include "pnj.h"

#define CHARACT_X (int) floor(CHARACT.pos.x / main->MAP_FORMAT)
#define CHARACT_Y (int) floor(CHARACT.pos.y / main->MAP_FORMAT)

typedef struct weapon
{
    void (*atk)(main_t *, struct weapon *weapon);
    void (*anim)(struct particle *, list_l **particles);
    int damage;
    sfTime cooldown;
    sfClock *timer;
} weapon_t;

int menu(main_t *main, sfRenderWindow *window);
void game(sfRenderWindow *window, main_t *main);
void anim_object(object_t *object, sfClock *clock);
object_t *init_object(sfTexture *texture, sfIntRect rect, int len, int time);
sfVector2i get_size_map(char **map);
void print_anim(sfVector2i pos_cam, int floor, sfVector2i pos, main_t *main);
void main_caract_move(keybind_t *move, main_t *main);
void print_character(sfSprite *sprite, int y, sfRenderWindow *window, \
                        sfVector2i pos);
void print_boxes(sfIntRect ***boxes, sfVector2i pos, sfRenderWindow *window);
void print_teleporters(sfIntRect *boxes, sfVector2i pos, \
                        sfRenderWindow *window);
void print_map(main_t *main, int floor, sfVector2i pos, character_t *player);
void print_enemies_behind(int y, main_t *main, sfVector2i pos);
void print_enemies_front(int y, main_t *main, sfVector2i pos);
sfIntRect ***get_boxes(char **map, int floor, config_t config);
sfIntRect *get_teleporters(char **map, config_t config);
void triger_cam(main_t *main);
void fighting_cam(main_t *main);
int get_width_max(char *str, int width);
int is_collide(sfIntRect *box, character_t *character, sfVector2f move);
int check_colide(main_t *, sfVector2f move);
void free_character(main_t *main);
void set_fade(main_t *main, sfBool bool);
void free_lvl(map_s *map, int width, int height);
void init_rdm(main_t *main);
int switch_map(main_t *main, sfVector2f move);
void launch_game(main_t *main);
void weapon_gun_atk(main_t *main, weapon_t *);
void weapon_gun_tek(main_t *main, weapon_t *);
void check_attack(main_t *main);
void get_textures_basic(main_t *main);
void get_textures_game(main_t *main);
void free_textures_basic(main_t *main);
void free_textures_game(main_t *main);
bonus_t *spawn_bonus(main_t *main);
void catch_bonus(main_t *main);
int particle_check_colision(main_t *main);
void enemy_check_colide(main_t *main, particle_t *particle);
void dash(main_t *main);
void realy_moov(main_t *main, sfVector2f move,
                info_move_t *info_m, config_t config);
void print_square(sfVector2i square, int floor, sfVector2i pos,
    main_t *main);
void update_all2(main_t *main);
void update_all1(main_t *main);
void update_anime(main_t *main);
int check_player_hit(main_t *main, particle_t *);
void change_character(main_t *main);
int check_pos(main_t *main);

#endif /* !DEFFENDER_H_ */
