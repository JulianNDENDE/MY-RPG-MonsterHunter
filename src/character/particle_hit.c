/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** particle_hit
*/

#include "my_rpg.h"

int check_player_hit(main_t *main, particle_t *particle)
{
    sfFloatRect hitbox = sfCircleShape_getGlobalBounds(particle->shape);
    int damage = sfCircleShape_getRadius(particle->shape) * 2;

    if (sfFloatRect_intersects(&hitbox, &CHARACT.hitbox, NULL)) {
        CHARACT.pv -= damage;
        SPAWN_DAMAGE(&PROJ.wait_list, CHARACT.pos.x, \
                    CHARACT.pos.y, damage, main->assets.font);
        sfClock_destroy(particle->life);
        particle->life = NULL;
        return 1;
    }
    return 0;
}