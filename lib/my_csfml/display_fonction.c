/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** display_fonction
*/

#include <stdlib.h>
#include "my_csfml.h"

void display_display(sfRenderWindow *window, display_t *display)
{
    PARSE_ARRAY(display->sprites)
        sfRenderWindow_drawSprite(window, display->sprites[i], NULL);
    PARSE_ARRAY(display->shapes)
        sfRenderWindow_drawRectangleShape(window, display->shapes[i], NULL);
    PARSE_ARRAY(display->texts)
        sfRenderWindow_drawText(window, display->texts[i], NULL);
    RenderWindow_drawAllButtons(window, display->buttons);
}

display_t *init_display(int sprite_nbr, int text_nbr, int shapes_nbr)
{
    display_t *display = malloc(sizeof(display_t));

    display->buttons = NULL;
    display->sprites = malloc(sizeof(sfSprite *) * (sprite_nbr + 1));
    display->sprites[sprite_nbr] = NULL;
    display->texts = malloc(sizeof(sfText *) * (text_nbr + 1));
    display->texts[text_nbr] = NULL;
    display->shapes = malloc(sizeof(sfRectangleShape *) * (shapes_nbr + 1));
    display->shapes[shapes_nbr] = NULL;
    return display;
}

void free_display(display_t *display)
{
    for (int i = 0; display->shapes[i]; i++)
        sfRectangleShape_destroy(display->shapes[i]);
    free(display->shapes);
    for (int i = 0; display->sprites[i]; i++)
        sfSprite_destroy(display->sprites[i]);
    free(display->sprites);
    for (int i = 0; display->texts[i]; i++)
        sfText_destroy(display->texts[i]);
    free(display->texts);
    free(display);
}