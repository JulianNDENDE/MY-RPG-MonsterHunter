/*
** EPITECH PROJECT, 2021
** my csfml
** File description:
** rect_gestion
*/

#include "my_csfml.h"

void move_rect(sfSprite *sprite, int offset, int max_value)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite);

    rect.left += offset;
    if (rect.left > max_value) {
        rect.left = 0;
    }
    sfSprite_setTextureRect(sprite, rect);
}

void switch_anim(sfSprite *sprite, int y)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite);

    rect.top = y;
    sfSprite_setTextureRect(sprite, rect);
}