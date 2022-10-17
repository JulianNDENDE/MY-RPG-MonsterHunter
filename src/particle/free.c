/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** free particles
*/

#include <stdlib.h>
#include "structure.h"

void particle_free(particle_t **particle)
{
    if ((*particle)->life)
        sfClock_destroy((*particle)->life);
    sfCircleShape_destroy((*particle)->shape);
    if ((*particle)->txt)
        sfText_destroy((*particle)->txt);
    free(*particle);
}

void wait_free(command_t **wait)
{
    if ((*wait)->clock) {
        sfClock_destroy((*wait)->clock);
        particle_free(&(*wait)->particle);
    }
    free(*wait);
}

void particle_freeall(list_l **particles, list_l **waiting_list)
{
    particle_t *particle = NULL;
    command_t *command = NULL;

    while (*particles) {
        particle = (*particles)->data;
        particle_free(&particle);
        delete_node(particles, 0);
    }
    *particles = NULL;
    while (*waiting_list) {
        command = (*waiting_list)->data;
        wait_free(&command);
        delete_node(waiting_list, 0);
    }
    *waiting_list = NULL;
}