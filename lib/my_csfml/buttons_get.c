/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-damien.antoniou
** File description:
** buttons_get
*/

#include "my_csfml.h"

sfVector2f button_get_position(button_t *button)
{
    return sfSprite_getPosition(button->sprite);
}