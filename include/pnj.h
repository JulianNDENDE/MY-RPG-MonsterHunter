/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** pnj
*/

#ifndef PNJ_H_
#define PNJ_H_

#include <stdlib.h>
#include "my_csfml.h"
#include "structure.h"

int dialogue(sfRenderWindow *window, main_t *main, dialogue_t dialogue);
pnj_t *create_pnj(sfSprite *sprite, sfVector2f pos, \
                    dialogue_t *dialogue[2], config_t config);
dialogue_t *create_dialogue(char **txt, dialogue_t **choices, \
                            sfFont *font, int rt_value);
int pnj_check(main_t *main, pnj_t **pnj, sfFloatRect character_box);
void init_cringe_guys(main_t *main);
void init_hub_pnj(main_t *main);

#endif /* !PNJ_H_ */
