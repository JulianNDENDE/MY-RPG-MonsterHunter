/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** init
*/

#include <stdlib.h>
#include "math.h"
#include "structure.h"

particle_t *create_particle(sfVector2f pos, sfColor color, float radius)
{
    particle_t *particle = malloc(sizeof(particle_t));

    color.a = 25;
    particle->shape = sfCircleShape_create();
    particle->anim = &anim_destroy;
    particle->boxes = NULL;
    particle->txt = NULL;
    particle->life_time.microseconds = 10000000;
    sfCircleShape_setPosition(particle->shape, pos);
    sfCircleShape_setRadius(particle->shape, radius);
    sfCircleShape_setOrigin(particle->shape, (sfVector2f) {radius, radius});
    sfCircleShape_setFillColor(particle->shape, color);
    particle->vector = (sfVector2f) {0, 0};
    particle->life = NULL;
    particle->pos = pos;
    return particle;
}

particle_t *particle_setup(particle_t *particle, sfVector2f assets, \
                    void (*anim)(particle_t *, list_l **), sfBool player)
{
    if (anim)
        particle->anim = anim;
    particle->vector.x = cos((assets.x * (M_PI * 2)) / 360) * assets.y;
    particle->vector.y = sin((assets.x * (M_PI * 2)) / 360) * assets.y;
    particle->player = player;
    return particle;
}