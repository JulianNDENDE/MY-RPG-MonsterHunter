/*
** EPITECH PROJECT, 2021
** my deffender
** File description:
** txt sprite
*/

#include "my_csfml.h"

sfText *create_text(const sfVector2f pos, const char *text, \
                    const unsigned int size, const sfFont *font)
{
    sfText *txt = sfText_create();

    if (txt == NULL || font == NULL)
        return NULL;
    sfText_setFont(txt, font);
    sfText_setCharacterSize(txt, size);
    sfText_setColor(txt, sfBlack);
    sfText_setPosition(txt, pos);
    sfText_setString(txt, text);
    return txt;
}

sfSprite *create_sprite(const sfVector2f pos, const sfVector2f size, \
                                            sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2u texture_size;

    if (sprite == NULL || texture == NULL)
        return NULL;
    texture_size = sfTexture_getSize(texture);
    sfSprite_setTexture(sprite, texture, 1);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, (sfVector2f) \
                    {size.x / texture_size.x, size.y / texture_size.y});
    return sprite;
}

sfRectangleShape *create_rectangleshape(sfFloatRect rect, sfColor color)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();

    sfRectangleShape_setPosition(rectangle, (sfVector2f){rect.left, rect.top});
    sfRectangleShape_setSize(rectangle, (sfVector2f){rect.width, rect.height});
    sfRectangleShape_setFillColor(rectangle, color);
    return rectangle;
}