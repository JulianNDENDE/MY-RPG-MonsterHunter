/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** init
*/

#include <stdlib.h>
#include "my_rpg.h"

weapon_t *init_weapon(void (*atk)(main_t *, weapon_t *), \
        void (*anim)(particle_t *, list_l **), int damage, int cooldown)
{
    weapon_t *weapon = malloc(sizeof(weapon_t));

    weapon->atk = atk;
    weapon->cooldown.microseconds = cooldown * 1000;
    weapon->anim = anim;
    weapon->damage = damage;
    weapon->timer = sfClock_create();
    return weapon;
}

void init_character_attack(main_t *main, sfVector2f resize)
{
    CHARACT.weapon_atk = init_weapon(&weapon_gun_atk, &anim_destroy,
        main->PLAYER_ATK, 300);
    CHARACT.weapon_tek = init_weapon(&weapon_gun_tek, &anim_destroy,
        main->PLAYER_TEK, 3000);
    CHARACT.invicibility_time.microseconds = 1000000;
    CHARACT.hitbox = (sfFloatRect){CHARACT.pos.x - (CHARACT.size.x / 2),
        CHARACT.pos.y + (CHARACT.size.y / 2) - 2, CHARACT.size.x, 2};
    CHARACT.bonus[0] = NULL;
    CHARACT.visual_box = create_rectangleshape(CHARACT.hitbox, sfRed);
    main->bonus = NULL;
    sfSprite_setOrigin(CHARACT.sprite, resize);
    sfSprite_setPosition(main->assets.player, (sfVector2f){
        main->windowx / 2, main->windowy / 2});
    update_live_bar(main->game, CHARACT.pv, CHARACT.pv_max);
}

void init_character(main_t *main)
{
    sfFloatRect size = sfSprite_getLocalBounds(main->assets.player);
    sfVector2f resize = {(size.width / 2), (size.height / 2)};

    CHARACT.size = (sfVector2f) {size.width, size.height};
    CHARACT.sprite = main->assets.player;
    CHARACT.speed = main->PLAYER_SPEED;
    CHARACT.pos = (sfVector2f){2662, 1800};
    CHARACT.pv = main->PLAYER_HEALTH;
    CHARACT.pv_max = main->PLAYER_HEALTH;
    CHARACT.clock = sfClock_create();
    CHARACT.dashclock = sfClock_create();
    CHARACT.dashing = 0;
    CHARACT.stamina = 30;
    CHARACT.maxstamina = 30;
    CHARACT.previous = 0;
    init_character_attack(main, resize);
}

void free_character(main_t *main)
{
    sfSprite_destroy(CHARACT.sprite);
    sfClock_destroy(CHARACT.clock);
    sfClock_destroy(CHARACT.dashclock);
}