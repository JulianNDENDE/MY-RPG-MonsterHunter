/*
** EPITECH PROJECT, 2021
** my_deffender
** File description:
** window
*/

#include "my_csfml.h"

sfRenderWindow *create_window(sfVector2f size, char *name)
{
    sfVideoMode mode = {size.x, size.y, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode,
                    name, sfClose, NULL);
    sfVector2i mpos = {0, 0};

    if (window == NULL)
        return NULL;
    sfRenderWindow_setPosition(window, mpos);
    sfRenderWindow_setFramerateLimit(window, 30);
    return (window);
}

int is_having_to_close(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return (1);
        }
    }
    return (0);
}