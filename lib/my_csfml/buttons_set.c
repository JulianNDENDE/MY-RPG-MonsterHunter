/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-damien.antoniou
** File description:
** buttons_set
*/

#include "my_csfml.h"

void button_move(button_t *button, sfVector2f vector)
{
    if (button->sprite)
        sfSprite_move(button->sprite, vector);
    if (button->txt)
        sfText_move(button->txt, vector);
    button->pos.x += vector.x;
    button->pos.y += vector.y;
    button->box.left = button->pos.x;
    button->box.top = button->pos.y;
}

void button_set_position(button_t *button, sfVector2f vector)
{
    if (button->sprite)
        sfSprite_setPosition(button->sprite, vector);
    if (button->txt)
        sfText_setPosition(button->txt, (sfVector2f) \
        {vector.x + (button->box.width / 10), vector.y});
    button->pos.x = vector.x;
    button->pos.y = vector.y;
    button->box.left = button->pos.x;
    button->box.top = button->pos.y;
}

void button_set_textsize(button_t *button, unsigned int *size,
sfColor *color, sfFont *font)
{
    if (size != NULL)
        sfText_setCharacterSize(button->txt, *size);
    if (color != NULL)
        sfText_setColor(button->txt, *color);
    if (font != NULL)
        sfText_setFont(button->txt, font);
}