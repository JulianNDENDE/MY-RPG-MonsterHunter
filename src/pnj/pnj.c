/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** pnj
*/

#include "my_rpg.h"

pnj_t *create_pnj(sfSprite *sprite, sfVector2f pos, \
                    dialogue_t *dialogue[2], config_t config)
{
    pnj_t *pnj = malloc(sizeof(pnj_t));

    pnj->sprite = sprite;
    pnj->first_dialogue = *dialogue[0];
    pnj->second_dialogue = *dialogue[0];
    if (dialogue[1] != NULL)
        pnj->second_dialogue = *dialogue[1];
    pnj->passed = sfFalse;
    pnj->pos = pos;
    sfSprite_setPosition(pnj->sprite, V2F(
                        pos.x * MAP_FORMAT, pos.y * MAP_FORMAT));
    return pnj;
}

int pnj_check(main_t *main, pnj_t **pnj, sfFloatRect character_box)
{
    sfFloatRect pnj_box;

    if (!sfKeyboard_isKeyPressed(main->config.keys.interact) || !pnj)
        return -1;
    for (int i = 0; pnj[i]; i++) {
        pnj_box = sfSprite_getGlobalBounds(pnj[i]->sprite);
        pnj_box = R2F(pnj_box.left - 100, pnj_box.top - 100, \
                    pnj_box.width + 200, pnj_box.height + 200);
        if (sfFloatRect_intersects(&pnj_box, &character_box, NULL)) {
            if (pnj[i]->passed == sfFalse)
                return dialogue(main->window, main, pnj[i]->first_dialogue);
            return dialogue(main->window, main, pnj[i]->second_dialogue);
        }
    }
    return -1;
}