/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** hub
*/

#include <math.h>
#include "my_rpg.h"

static char *sortie_hub[] = {
    "Sortir du hub",
    "Sage du village:",
    "Attention,",
    "Il y a de nombreux monstres la bas",
    "Soit sur d'etre pret avant de partir a l'aventure",
    NULL
};

static char *chien[] = {
    "chien",
    "Chien",
    "Wouf",
    NULL
};

void init_hub_pnj(main_t *main)
{
    MAP.lvl[1][1].pnj = malloc(sizeof(pnj_t) * 2);
    MAP.lvl[1][2].pnj = malloc(sizeof(pnj_t) * 2);
    MAP.lvl[1][1].pnj[0] = create_pnj(create_sprite(V2F(0, 0), \
        V2F(192, 256), main->assets.pnj1), \
        V2F(21, 4), (dialogue_t *[]) {
        create_dialogue(sortie_hub, NULL, main->assets.font, 1), NULL
        }, main->config);
    MAP.lvl[1][2].pnj[0] = create_pnj(create_sprite(V2F(0, 0), \
        V2F(192, 256), main->assets.pnj4), \
        V2F(21, 4), (dialogue_t *[]) {
        create_dialogue(chien, NULL, main->assets.font, 1), NULL
        }, main->config);
    sfSprite_setTextureRect(MAP.lvl[1][1].pnj[0]->sprite, R2I(32, 0, 32, 32));
    sfSprite_setTextureRect(MAP.lvl[1][2].pnj[0]->sprite, R2I(32, 32, 32, 32));
    MAP.lvl[1][1].pnj[1] = NULL;
    MAP.lvl[1][2].pnj[1] = NULL;
    init_cringe_guys(main);
}