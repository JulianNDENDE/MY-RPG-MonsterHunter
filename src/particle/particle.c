/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** particle
*/

#include <stdlib.h>
#include "my_rpg.h"

void RenderWindow_drawParticles(sfRenderWindow *window, list_l *particles, \
                                sfVector2i cam)
{
    particle_t *particle;

    PARSE_LIST(particles) {
        particle = tmp->data;
        sfCircleShape_setPosition(particle->shape, (sfVector2f) \
                    {particle->pos.x - cam.x, particle->pos.y - cam.y});
        sfRenderWindow_drawCircleShape(window, particle->shape, NULL);
        if (particle->txt) {
            sfText_setPosition(particle->txt, (sfVector2f) \
                    {particle->pos.x - cam.x, particle->pos.y - cam.y});
            sfRenderWindow_drawText(window, particle->txt, NULL);
        }
    }
}

void particle_move(particle_t *particle, sfVector2f vector)
{
    particle->pos.x += vector.x;
    particle->pos.y += vector.y;
    sfCircleShape_move(particle->shape, particle->vector);
    if (particle->txt)
        sfText_move(particle->txt, particle->vector);
}

static void move_particle(list_l **wait_list, \
                        particle_t *particle, sfTime clock_error)
{
    sfColor color = sfCircleShape_getFillColor(particle->shape);

    if (particle->life && \
            (get_Milliseconds(particle->life, clock_error) > 250 || \
            particle->player)) {
        particle->anim(particle, wait_list);
        particle_move(particle, particle->vector);
        if (color.a < 200 && !particle->txt) {
            color.a = 200;
            sfCircleShape_setFillColor(particle->shape, color);
        }
    }
}

void particle_update(list_l **wait_list, list_l **particles, \
                    sfTime clock_error)
{
    particle_t *particle = NULL;
    int index = 0;

    for (list_l *tmp = *particles; tmp != NULL; index++) {
        particle = tmp->data;
        move_particle(wait_list, tmp->data, clock_error);
        tmp = tmp->next;
        particle->life_time.microseconds += clock_error.microseconds;
        if (!particle->life || get_Microseconds(particle->life, clock_error) \
                                > particle->life_time.microseconds) {
            particle_free(&particle);
            delete_node(particles, index);
            index--;
        }
    }
}

int particle_check_colision(main_t *main)
{
    particle_t *particle = NULL;

    PARSE_LIST(PROJ.particles) {
        particle = tmp->data;
        if (particle->life && !particle->player && !particle->txt && \
            get_Milliseconds(particle->life, main->clock_error) > 250) {
            if (check_player_hit(main, particle))
                return 1;
        }
        if (particle->player && CURENT_MAP.enemy != NULL)
            enemy_check_colide(main, particle);
    }
    return 0;
}