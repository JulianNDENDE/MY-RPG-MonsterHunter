/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** game
*/

#include "my_rpg.h"
#include <stdlib.h>

object_t *init_object(sfTexture *texture, sfIntRect rect, int len, int time)
{
    object_t *object = malloc(sizeof(object_t));
    object->sprite = sfSprite_create();
    sfSprite_setTexture(object->sprite, texture, sfFalse);
    sfSprite_setTextureRect(object->sprite, rect);
    object->previous = 0;
    object->now = 0;
    object->begin_sprite = rect.left;
    object->time = time;
    object->len = len;
    return (object);
}

void anim_object(object_t *object, sfClock *clock)
{
    sfIntRect rect = sfSprite_getTextureRect(object->sprite);
    object->now = sfTime_asMilliseconds((
            sfClock_getElapsedTime(clock)));
    if (object->now - object->previous > object->time) {
        if (rect.left > rect.width * (object->len - 2))
            rect.left = object->begin_sprite;
        else
            rect.left += rect.width;
        sfSprite_setTextureRect(object->sprite, rect);
        object->previous = object->now;
    }
}