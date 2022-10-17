/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** pause
*/

#include <stdlib.h>
#include "my_rpg.h"

static void set_button_size(button_t *button)
{
    int unsigned size = 25;

    button_set_textsize(button, &size, NULL, NULL);
    button->txt_display = 0;
}

list_l *set_inventory(main_t *main)
{
    int i = -1;
    sfTexture *tmp;
    list_l *bonus = NULL;

    for (i = -1; CHARACT.bonus[i + 1]; i++);
    if (i == -1)
        return NULL;
    for (int y = 0; y < 7 && i >= 0; y++) {
        for (int x = 0; x < 4 && i >= 0; x++) {
            tmp = sfTexture_copy(sfSprite_getTexture(
                                CHARACT.bonus[i]->sprite));
            ADD_BUTTON(bonus, main->windowx - 290 + 70 * x, \
            (main->windowy / 5 + 10) + 74 * y, 64, 64, &displaytxt_anim, \
                        tmp, CHARACT.bonus[i]->name);
            set_button_size(bonus->data);
            i--;
        }
    }
    return bonus;
}