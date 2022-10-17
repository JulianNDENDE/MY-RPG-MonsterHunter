/*
** EPITECH PROJECT, 2021
** my defender
** File description:
** animations
*/

#include "my_csfml.h"

void moveright_anim(button_t *button)
{
    sfVector2f move = {button->box.width / 4, 0};

    if (button->sprite)
        sfSprite_move(button->sprite, move);
    if (button->txt)
        sfText_move(button->txt, move);
}

void moveleft_anim(button_t *button)
{
    sfVector2f move = {button->box.width / -4, 0};

    if (button->sprite)
        sfSprite_move(button->sprite, move);
    if (button->txt) {
        sfText_move(button->txt, move);
    }
}

void red_anim(button_t *button)
{
    if (button->txt) {
        sfText_setColor(button->txt, sfRed);
    }
}

void displaytxt_anim(button_t *button)
{
    if (button->txt) {
        sfText_setColor(button->txt, sfBlack);
    }
}