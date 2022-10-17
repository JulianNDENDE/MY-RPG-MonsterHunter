/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** bonus
*/

#include "my_rpg.h"

static bonus_t bonus_list[] = {
    (bonus_t){"Bounce\natk", 0, &anim_bounce, 0, NULL, \
                                0, 0, 0, 0, 0, NULL, NULL},
    (bonus_t){"Explode\natk", 0, &anim_explode, 0, NULL, \
                                0, 0, 0, 0, 0, NULL, NULL},
    (bonus_t){"speed\n+2", 0, NULL, 0, NULL, 2, 0, 0, 0, 0, NULL, NULL},
    (bonus_t){"speed\n+4", 0, NULL, 0, NULL, 4, 0, 0, 0, 0, NULL, NULL},
    (bonus_t){"speed\n+6", 0, NULL, 0, NULL, 6, 0, 0, 0, 0, NULL, NULL},
    (bonus_t){"tank", 10, NULL, 10, NULL, -10, 100, 100, 0, 0, NULL, NULL},
    (bonus_t){"atk\n+2", 2, NULL, 0, NULL, 0, 0, 0, 0, 0, NULL, NULL},
    (bonus_t){"atk\n+4", 4, NULL, 0, NULL, 0, 0, 0, 0, 0, NULL, NULL},
    (bonus_t){"atk +4,\ntek -2", 4, NULL, -2, NULL, 0, 0, 0, 0, 0, NULL, NULL},
    (bonus_t){"tek\n+2", 0, NULL, 2, NULL, 0, 0, 0, 0, 0, NULL, NULL},
    (bonus_t){"tek\n+4", 0, NULL, 4, NULL, 0, 0, 0, 0, 0, NULL, NULL},
    (bonus_t){"tek +4,\natk -2", -2, NULL, 4, NULL, 0, 0, 0, 0, 0, NULL, NULL},
    (bonus_t){"heal\n10", 0, NULL, 0, NULL, 0, 10, 0, 0, 0, NULL, NULL},
    (bonus_t){"heal\n30", 0, NULL, 0, NULL, 0, 30, 0, 0, 0, NULL, NULL},
    (bonus_t){"heal\n40", 0, NULL, 0, NULL, 0, 40, 0, 0, 0, NULL, NULL},
    (bonus_t){"heal\n50", 0, NULL, 0, NULL, 0, 50, 0, 0, 0, NULL, NULL},
    (bonus_t){"full\n heal", 0, NULL, 0, NULL, 0, 1000, 0, 0, 0, NULL, NULL},
    (bonus_t){"better\n heart", 0, NULL, 0, NULL, 0, 25, 25, 0, 0, NULL, NULL},
    (bonus_t){"heal\n20", 0, NULL, 0, NULL, 0, 20, 0, 0, 0, NULL, NULL},
    (bonus_t){"max\n stamina 15", 0, NULL, 0, NULL, \
                                0, 0, 0, 0, 15, NULL, NULL},
    (bonus_t){"max\n stamina 30", 0, NULL, 0, NULL, \
                                0, 0, 0, 0, 30, NULL, NULL},
    (bonus_t){"stamina\n", 0, NULL, 0, NULL, 0, 0, 0, 200, 0, NULL, NULL}
};

bonus_t *spawn_bonus(main_t *main)
{
    bonus_t *bonus = NULL;

    if (RDM(0, 5) == 0)
        return NULL;
    do {
        bonus = &bonus_list[RDM(0, 22)];
        for (size_t i = 0; CHARACT.bonus[i]; i++) {
            if (i >= 21)
                return NULL;
            if (my_str_is_identical(CHARACT.bonus[i]->name, bonus->name)) {
                bonus = NULL;
                break;
            }
        }
    } while (!bonus);
    bonus->sprite = create_sprite(V2F(0, 0), V2F(32, 32), main->assets.bonus);
    bonus->pos = malloc(sizeof(sfVector2f));
    bonus->pos->x = CHARACT.pos.x;
    bonus->pos->y = CHARACT.pos.y;
    return bonus;
}

void buff_chararcter(bonus_t bonus, character_t *character)
{
    weapon_t *weapon;

    weapon = character->weapon_atk;
    weapon->damage += bonus.atk;
    if (bonus.atk_anim)
        weapon->anim = bonus.atk_anim;
    weapon = character->weapon_tek;
    weapon->damage += bonus.tek;
    if (bonus.tek_anim)
        weapon->anim = bonus.tek_anim;
    character->speed += bonus.speed;
    character->pv += bonus.pv;
    character->pv_max += bonus.pv_max;
    if (character->pv > character->pv_max)
        character->pv = character->pv_max;
    character->stamina = bonus.stamina + character->stamina;
    character->maxstamina = bonus.max_stamina + character->maxstamina;
}

void catch_bonus(main_t *main)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(main->bonus->sprite);
    sfFloatRect player = sfSprite_getGlobalBounds(CHARACT.sprite);
    int index = 0;

    if (!sfKeyboard_isKeyPressed(sfKeyE))
        return;
    if (sfFloatRect_intersects(&player, &rect, NULL)) {
        for (index = 0; CHARACT.bonus[index]; index++);
        CHARACT.bonus[index] = main->bonus;
        CHARACT.bonus[index + 1] = NULL;
        buff_chararcter(*main->bonus, &CHARACT);
        SPAWN_TXT(&PROJ.wait_list, main->bonus->pos->x - 50, \
                main->bonus->pos->y - 50, -90, 5, main->bonus->name, \
                SLOWY_MEDIUM_RED, main->assets.font);
        main->bonus = NULL;
        update_live_bar(main->game, CHARACT.pv, CHARACT.pv_max);
    }
}