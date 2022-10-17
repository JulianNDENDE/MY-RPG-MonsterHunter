/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** weapon
*/

#include "my_rpg.h"

void weapon_gun_atk(main_t *main, weapon_t *weapon)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(main->window);
    spell_effect effect = {weapon->anim, weapon->damage / 2, sfBlue};

    mouse.x += CAM.cam_pos.x;
    mouse.y += CAM.cam_pos.y;
    if (get_Microseconds(weapon->timer, main->clock_error) \
            >= weapon->cooldown.microseconds) {
        SPAWN_TARGET(&PROJ.wait_list, CHARACT.pos.x, CHARACT.pos.y,
                mouse.x, mouse.y, 50, effect, sfTrue, 0);
        sfClock_restart(weapon->timer);
    }
}

void weapon_gun_tek(main_t *main, weapon_t *weapon)
{
    spell_effect effect = {weapon->anim, weapon->damage / 2, sfBlue};

    if (get_Microseconds(weapon->timer, main->clock_error) \
            >= weapon->cooldown.microseconds) {
        SPAWN_CIRCLE(&PROJ.wait_list, CHARACT.pos.x, CHARACT.pos.y, \
                    0, 15, 20, effect, sfTrue, 0);
        sfClock_restart(weapon->timer);
    }
}

void check_attack(main_t *main)
{
    weapon_t *weapon_1 = CHARACT.weapon_atk;
    weapon_t *weapon_2 = CHARACT.weapon_tek;

    if (sfMouse_isButtonPressed(sfMouseLeft))
        weapon_1->atk(main, weapon_1);
    if (sfMouse_isButtonPressed(sfMouseRight))
        weapon_2->atk(main, weapon_2);
}