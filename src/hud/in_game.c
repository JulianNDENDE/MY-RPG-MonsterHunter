/*
** EPITECH PROJECT, 2021
** HUD
** File description:
** in_game
*/

#include <stdlib.h>
#include "hud.h"

void set_color_lifebar(sfRectangleShape *bar, float life, float lifemax)
{
    sfVector2f ratio = {life, lifemax};
    float red = (255 - ((ratio.x / ratio.y) * 255)) * 2;
    float green = (ratio.x / (ratio.y / 2)) * 255;
    float blue = 0;

    if (red > 255)
        red = 255;
    if (green > 255)
        green = 255;
    sfRectangleShape_setFillColor(bar, sfColor_fromRGB(red, green, blue));
}

void update_live_bar(display_t *game, int life, int life_max)
{
    sfVector2f scale = {300, 18};
    char *txt = my_strcat(my_strcat(my_getstr(life), " / "), \
        my_getstr(life_max));

    if (life < 0)
        life = 0;
    sfRectangleShape_setSize(game->shapes[0], (sfVector2f) \
        {scale.x * ((double) life / (double) life_max), scale.y});
    set_color_lifebar(game->shapes[0], life, life_max);
    sfText_setString(game->texts[life_txt], txt);
    free(txt);
}

void update_stamina_bar(display_t *game, int stamina, int stamina_max)
{
    sfVector2f scale = {250, 10};
    if (stamina < 0)
        stamina = 0;
    sfRectangleShape_setSize(game->shapes[1], (sfVector2f) \
        {scale.x * ((double) stamina / (double) stamina_max), scale.y});
    sfRectangleShape_setFillColor(game->shapes[1],
        (sfColor){128, 128, 128, 255});
    if (stamina > stamina_max)
        sfRectangleShape_setFillColor(game->shapes[1],
            (sfColor){255, 215, 0, 255});
    else if (stamina > 15)
        sfRectangleShape_setFillColor(game->shapes[1], sfBlue);
}

void update_boss_bar(main_t *main, int life, int life_max)
{
    sfVector2f scale = {main->windowx / 2, 18};
    char *txt = my_strcat(my_strcat(my_getstr(life), " / "), \
        my_getstr(life_max));

    if (life < 0)
        life = 0;
    sfRectangleShape_setSize(main->boss_hud->shapes[0], (sfVector2f) \
        {scale.x * ((double) life / (double) life_max), scale.y});
    set_color_lifebar(main->boss_hud->shapes[0], life, life_max);
    sfText_setString(main->boss_hud->texts[0], txt);
    free(txt);
}