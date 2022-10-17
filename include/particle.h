/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** particle
*/

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include "my_csfml.h"
#include "structure.h"
#include "param.h"

#define CLASSIC_MEDIUM_RED      (spell_effect) {NULL, 8, sfRed}
#define SLOWY_MEDIUM_RED        (spell_effect) {&anim_slow, 8, sfRed}
#define BOUNCY_MEDIUM_RED       (spell_effect) {&anim_bounce, 8, sfRed}
#define EXPLODE_MEDIUM_RED      (spell_effect) {&anim_explode, 8, sfRed}
#define CLASSIC_LITLE_GREEN     (spell_effect) {NULL, 5, sfGreen}
#define BOUNCY_LITLE_GREEN      (spell_effect) {&anim_bounce, 5, sfGreen}
#define EXPLODE_MEDIUM_GREEN    (spell_effect) {&anim_explode, 8, sfGreen}
#define EXPLODE_LITLE_GREEN     (spell_effect) {&anim_explode, 5, sfGreen}
#define CLASSIC_LITLE_BROWN     (spell_effect) {NULL, 5, (sfColor) \
                                {139, 69, 19, 255}}
#define CLASSIC_MEDIUM_BROWN    (spell_effect) {NULL, 8, (sfColor) \
                                {139, 69, 19, 255}}
#define CLASSIC_MEDIUM_YELLOW   (spell_effect) {NULL, 8, (sfColor) \
                                {230, 230, 0, 255}}
#define CLASSIC_BIG_PURPLE      (spell_effect) {NULL, 11, (sfColor) \
                                {119, 51, 255, 255}}
#define CLASSIC_MEDIUM_PURPLE   (spell_effect) {NULL, 8, (sfColor) \
                                {119, 51, 255, 255}}
#define CLASSIC_LITLE_PURPLE    (spell_effect) {NULL, 5, (sfColor) \
                                {119, 51, 255, 255}}

#define PARTICLE(x, y, angle, speed, radius, color, anim, player) \
        particle_setup(create_particle((sfVector2f) {x, y}, color, radius), \
        (sfVector2f) {angle, speed}, anim, player)
#define ADD_PARTICLE(wait_list, spell) \
        add_command(wait_list, PARTICLE((spell).pos.x, (spell).pos.y, \
        (spell).angle, (spell).speed, (spell).type.size, \
        (spell).type.color, (spell).type.anim, (spell).player), (spell).wait);
#define SPAWN_CIRCLE(wait_list, x, y, first_angle, speed, \
                    nbr, type, player, wait) \
        particle_circle(wait_list, (spell_t) {(sfVector2f) {x, y}, \
                        first_angle, speed, nbr, 0, type, player, wait})
#define SPAWN_CIRCLE_RIFLE(wait_list, x, y, speed, p_nbr, c_nbr, \
                            type, wait, wait_pas) \
    for (int _i = 0; _i < c_nbr; _i++) \
        particle_circle(wait_list, (spell_t) {(sfVector2f) {x, y}, \
    ((360 / p_nbr) / c_nbr) * _i, speed, p_nbr, 0, type, \
                        sfFalse, wait + wait_pas * _i})
#define SPAWN_CIRCLE_RIFLE_REVERSE(wait_list, x, y, speed, p_nbr, c_nbr, \
                            type, wait, wait_pas) \
    for (int _i = 0; _i < c_nbr; _i++) \
        particle_circle(wait_list, (spell_t) {(sfVector2f) {x, y}, \
                        ((360 / p_nbr) / c_nbr) * _i * -1, speed, \
                        p_nbr, 0, type, sfFalse, wait + wait_pas * _i})
#define SPAWN_CIRCLE_ALT(wait_list, x, y, speed, p_nbr, c_nbr, \
                        type, wait, wait_pas) \
    for (int _j = 0; _j < c_nbr / 2; _j++) \
        for (int _i = 0; _i < 2; _i++) \
            particle_circle(wait_list, (spell_t) {(sfVector2f) {x, y}, \
            ((360 / p_nbr) / 2) * _i, speed, p_nbr, 0, type, sfFalse, \
            (wait + wait_pas * _j * 2) + wait_pas * _i})
#define SPAWN_SPRAY(wait_list, x, y, angle, speed, nbr, precision, type, wait)\
        particle_spray(wait_list, (spell_t) {(sfVector2f) {x, y}, angle, \
                        speed, nbr, precision, type, sfFalse, wait})
#define SPAWN_TARGET(wait_list, x, y, target_x, target_y, \
                    speed, type, player, wait) \
        particle_target(wait_list, (spell_t) {(sfVector2f) {x, y}, 0, speed, \
        0, 0, type, player, wait}, (sfVector2f) {target_x, target_y})
#define SPAWN_WOLOLO(wait_list, target_x, target_y, speed, nbr, type, wait) \
    for (size_t _i = 0; _i < nbr; _i++) \
        particle_target(wait_list, (spell_t) {(sfVector2f) \
        {target_x - 500 + rand() % 1000, \
        target_y - 500 + rand() % 1000}, 0, speed, \
        0, 0, type, sfFalse, wait}, (sfVector2f) {target_x, target_y})
#define SPAWN_DAMAGE(wait_list, x, y, damage, font) \
    particle_txt(wait_list, (spell_t) {(sfVector2f) {x - 50, y - 50}, -90, 5, \
        0, 0, SLOWY_MEDIUM_RED, sfTrue, 0}, my_getstr(damage), font)
#define SPAWN_TXT(wait_list, x, y, angle, speed, txt, type, font) \
        particle_txt(wait_list, (spell_t) {(sfVector2f) {x, y}, angle, speed, \
        0, 0, type, sfTrue, 0}, txt, font)

typedef struct particle
{
    sfCircleShape *shape;
    sfVector2f vector;
    sfVector2f pos;
    sfClock *life;
    sfTime life_time;
    sfText *txt;
    void (*anim)(struct particle *, list_l **particles);
    sfBool player;
    sfIntRect ***boxes;
} particle_t;

typedef struct command
{
    particle_t *particle;
    sfClock *clock;
    sfTime wait;
} command_t;

typedef struct spell_effect
{
    void (*anim)(particle_t *particle, list_l **command);
    int size;
    sfColor color;
} spell_effect;

typedef struct spell_asset
{
    sfVector2f pos;
    float angle;
    float speed;
    int proj_nbr;
    float precision;
    spell_effect type;
    sfBool player;
    int wait;
} spell_t;

void RenderWindow_drawParticles(sfRenderWindow *window, \
                                list_l *particles, sfVector2i);
void particle_update(list_l **wait_list, list_l **particles, \
                    sfTime clock_error);
void particle_freeall(list_l **particles, list_l **waiting_list);
void particle_free(particle_t **particle);
void anim_destroy(particle_t *particle, list_l **command);
void anim_bounce(particle_t *particle, list_l **command);
void anim_explode(particle_t *particle, list_l **command);
void anim_slow(particle_t *particle, list_l **command);
particle_t *particle_setup(particle_t *particle, sfVector2f assets, \
                    void (*anim)(particle_t *, list_l **), sfBool player);
particle_t *create_particle(sfVector2f pos, sfColor color, float radius);
void command_check(list_l **wait_list, list_l **particles, \
                    sfTime clock_error, sfIntRect ***boxes);
void add_command(list_l **wait_list, particle_t *particle, int wait);
void particle_circle(list_l **wait_list, spell_t spell);
void particle_spray(list_l **wait_list, spell_t spell);
void particle_target(list_l **wait_list, spell_t spell, sfVector2f target);
void particle_txt(list_l **wait_list, spell_t spell, \
                    const char *txt, sfFont *font);

#endif /* !PARTICLE_H_ */
