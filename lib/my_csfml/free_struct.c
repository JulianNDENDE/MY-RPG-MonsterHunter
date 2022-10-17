/*
** EPITECH PROJECT, 2021
** my csfml
** File description:
** free_struct
*/

#include "my_csfml.h"
#include <stdlib.h>

void free_button(button_t *button)
{
    if (button->sprite)
        sfSprite_destroy(button->sprite);
    if (button->txt)
        sfText_destroy(button->txt);
    free(button);
}