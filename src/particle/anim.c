/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** anim
*/

#include <math.h>
#include <stdlib.h>
#include "structure.h"

void anim_destroy(particle_t *particle, list_l **command)
{
    int x = particle->pos.x / 128;
    int y = particle->pos.y / 128;

    if (x < 0 || y < 0 || \
        particle->boxes[y] == NULL || particle->boxes[y][x] == NULL) {
        sfClock_destroy(particle->life);
        particle->life = NULL;
        return;
    }
    if (!particle->txt && particle->boxes[y][x]->left != -1)
        if (sfIntRect_contains(particle->boxes[y][x], \
                    particle->pos.x, particle->pos.y)) {
            sfClock_destroy(particle->life);
            particle->life = NULL;
    }
    if (command && !*command)
        *command = NULL;
}

static void check(particle_t *particle, int x, int y)
{
    sfIntRect rect_x = (sfIntRect) {
        particle->boxes[y][x]->left + 5, particle->boxes[y][x]->top - 5, \
        particle->boxes[y][x]->width - 5, particle->boxes[y][x]->height + 5};
    sfIntRect rect_y = (sfIntRect) {
        particle->boxes[y][x]->left - 5, particle->boxes[y][x]->top + 5, \
        particle->boxes[y][x]->width + 5, particle->boxes[y][x]->height - 5};
    float radius = sfCircleShape_getRadius(particle->shape);

    if (radius <= 0)
        radius = 1;
    if (sfIntRect_contains(&rect_x, particle->pos.x, \
                            particle->pos.y + particle->vector.y)) {
        particle->vector.y *= -1;
        sfCircleShape_setRadius(particle->shape, radius - 1);
    }
    if (sfIntRect_contains(&rect_y, particle->pos.x + particle->vector.x, \
                            particle->pos.y)) {
        particle->vector.x *= -1;
        sfCircleShape_setRadius(particle->shape, radius - 1);
    }
}

void anim_bounce(particle_t *particle, list_l **command)
{
    int x = particle->pos.x / 128;
    int y = particle->pos.y / 128;

    if (x < 0 || y < 0 || \
        particle->boxes[y] == NULL || particle->boxes[y][x] == NULL) {
        sfClock_destroy(particle->life);
        particle->life = NULL;
        return;
    }
    check(particle, x, y);
    if (y - 1 >= 0)
        check(particle, x, y - 1);
    if (command && !*command)
        *command = NULL;
}

void anim_explode(particle_t *particle, list_l **command)
{
    int x = particle->pos.x / 128;
    int y = particle->pos.y / 128;

    if (x < 0 || y < 0 || \
        particle->boxes[y] == NULL || particle->boxes[y][x] == NULL) {
        sfClock_destroy(particle->life);
        particle->life = NULL;
        return;
    }
    if (particle->boxes[y][x]->left != -1 || \
        (--y >= 0 && particle->boxes[y][x]->left != -1))
        if (sfIntRect_contains(particle->boxes[y][x],
                particle->pos.x + particle->vector.x,
                particle->pos.y + particle->vector.y)) {
            SPAWN_CIRCLE(command, particle->pos.x, particle->pos.y, \
            0, 8, 10, CLASSIC_MEDIUM_RED, particle->player, 0);
            sfClock_destroy(particle->life);
            particle->life = NULL;
        }
}

void anim_slow(particle_t *particle, list_l **command)
{
    particle->vector.x -= particle->vector.x * 0.05;
    particle->vector.y -= particle->vector.y * 0.05;
    anim_destroy(particle, command);
    if (command && !*command)
        *command = NULL;
}