/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** actions_list
*/

#include <stdlib.h>
#include "structure.h"

void add_command(list_l **wait_list, particle_t *particle, int wait)
{
    command_t *command = malloc(sizeof(command_t));

    command->clock = sfClock_create();
    command->wait.microseconds = 1000 * wait;
    command->particle = particle;
    add_nod(wait_list, command);
}

static void check(command_t *command, list_l **particles, \
                    sfTime clock_error, sfIntRect ***boxes)
{
    if (get_Milliseconds(command->clock, clock_error) > \
        sfTime_asMilliseconds(command->wait)) {
        sfClock_destroy(command->clock);
        command->clock = NULL;
        command->particle->life = sfClock_create();
        command->particle->boxes = boxes;
        add_nod(particles, command->particle);
    }
}

void command_check(list_l **wait_list, list_l **particles, \
                    sfTime clock_error, sfIntRect ***boxes)
{
    int index = 0;
    command_t *command = NULL;

    for (list_l *tmp = *wait_list; tmp != NULL; index++) {
        command = tmp->data;
        check(tmp->data, particles, clock_error, boxes);
        tmp = tmp->next;
        if (!command->clock) {
            free(command);
            delete_node(wait_list, index);
            index--;
        }
    }
}