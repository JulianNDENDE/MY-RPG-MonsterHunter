/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** patern
*/

#include <math.h>
#include <stdlib.h>
#include "structure.h"

void particle_circle(list_l **wait_list, spell_t spell)
{
    float pas = 360 / spell.proj_nbr;

    for (int i = 0; i < spell.proj_nbr; i++) {
        spell.angle += pas;
        ADD_PARTICLE(wait_list, spell);
    }
}

void particle_spray(list_l **wait_list, spell_t spell)
{
    int min = (spell.angle - spell.precision);
    int max = (spell.precision * 2) + min;
    int wait = spell.wait;

    for (int i = 0; i < spell.proj_nbr; i++) {
        spell.angle = RDM(min, max);
        spell.wait = RDM(wait, 500);
        ADD_PARTICLE(wait_list, spell);
    }
}

void particle_target(list_l **wait_list, spell_t spell, sfVector2f target)
{
    spell.angle = atanf((target.y - spell.pos.y) / (target.x - spell.pos.x));
    spell.angle = spell.angle * 180 / M_PI;
    if (target.x - spell.pos.x < 0)
        spell.angle += 180;
    ADD_PARTICLE(wait_list, spell);
}

void particle_txt(list_l **wait_list, spell_t spell, \
                    const char *txt, sfFont *font)
{
    particle_t *particle = PARTICLE(spell.pos.x, spell.pos.y, spell.angle, \
    spell.speed, spell.type.size, spell.type.color, spell.type.anim, sfFalse);

    sfCircleShape_setFillColor(particle->shape, sfTransparent);
    particle->life_time.microseconds = 1000000;
    particle->txt = create_text(particle->pos, txt, \
                                spell.type.size * 4, font);
    add_command(wait_list, particle, spell.wait);
}