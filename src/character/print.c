/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** print
*/

#include "my_rpg.h"

void print_enemies_front(int y, main_t *main, sfVector2i pos)
{
    sfFloatRect rect;
    map_t map = main->map.lvl[main->map.y][main->map.x];
    sfFloatRect player_rect = sfSprite_getGlobalBounds(main->assets.player);

    for (int i = 0; map.enemy[i] != NULL; i++) {
        if (map.enemy[i]->sprite != NULL) {
            sfSprite_setPosition(map.enemy[i]->sprite, (sfVector2f){
                map.enemy[i]->pos.x - pos.x, map.enemy[i]->pos.y - pos.y});
            rect = sfSprite_getGlobalBounds(map.enemy[i]->sprite);
            if (rect.top + rect.height >= y * 128 + 128 - pos.y &&
                rect.top + rect.height < y * 128 + 128 + 128 - pos.y &&
                rect.top + rect.height >= player_rect.top + player_rect.height){
                sfRenderWindow_drawSprite(
                                    main->window, map.enemy[i]->sprite, NULL);
            }
        }
    }
}

void print_enemies_behind(int y, main_t *main, sfVector2i pos)
{
    sfFloatRect player_rect = sfSprite_getGlobalBounds(main->assets.player);
    sfFloatRect rect;
    map_t map = MAP.lvl[MAP.y][MAP.x];

    for (int i = 0; map.enemy[i] != NULL; i++) {
        if (map.enemy[i]->sprite != NULL) {
            sfSprite_setPosition(map.enemy[i]->sprite, (sfVector2f){
                map.enemy[i]->pos.x - pos.x, map.enemy[i]->pos.y - pos.y});
            rect = sfSprite_getGlobalBounds(map.enemy[i]->sprite);
            if (rect.top + rect.height >= y * 128 + 128 - pos.y &&
                rect.top + rect.height < y * 128 + 128 + 128 - pos.y &&
                rect.top + rect.height < player_rect.top + player_rect.height) {
                sfRenderWindow_drawSprite(
                            main->window, map.enemy[i]->sprite, NULL);
            }
        }
    }
}

void print_pnj_behind(int y, main_t *main, sfVector2i pos)
{
    sfFloatRect player_rect = sfSprite_getGlobalBounds(main->assets.player);
    sfFloatRect rect;
    map_t map = MAP.lvl[MAP.y][MAP.x];

    for (int i = 0; map.pnj[i] != NULL; i++) {
        sfSprite_setPosition(map.pnj[i]->sprite, \
            V2F(map.pnj[i]->pos.x * 128 - CAM.cam_pos.x, \
                map.pnj[i]->pos.y * 128 - CAM.cam_pos.y));
        rect = sfSprite_getGlobalBounds(map.pnj[i]->sprite);
        if (rect.top + rect.height >= y * 128 + 128 - pos.y &&
            rect.top + rect.height < y * 128 + 128 + 128 - pos.y &&
            rect.top + rect.height < player_rect.top + player_rect.height) {
            sfRenderWindow_drawSprite(
                        main->window, map.pnj[i]->sprite, NULL);
        }
    }
}

void print_pnj_front(int y, main_t *main, sfVector2i pos)
{
    sfFloatRect rect;
    map_t map = MAP.lvl[MAP.y][MAP.x];
    sfFloatRect player_rect = sfSprite_getGlobalBounds(main->assets.player);

    for (int i = 0; map.pnj[i] != NULL; i++) {
        sfSprite_setPosition(map.pnj[i]->sprite, \
            V2F(map.pnj[i]->pos.x * 128 - CAM.cam_pos.x, \
                map.pnj[i]->pos.y * 128 - CAM.cam_pos.y));
        rect = sfSprite_getGlobalBounds(map.pnj[i]->sprite);
        if (rect.top + rect.height >= y * 128 + 128 - pos.y &&
            rect.top + rect.height < y * 128 + 128 + 128 - pos.y &&
            rect.top + rect.height >= player_rect.top + player_rect.height) {
            sfRenderWindow_drawSprite(
                                main->window, map.pnj[i]->sprite, NULL);
        }
    }
}

void print_character(sfSprite *sprite, int y, sfRenderWindow *window, \
                        sfVector2i pos)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(sprite);

    if (rect.top + rect.height >= y * 128 + 128 - pos.y &&
        rect.top + rect.height < y * 128 + 128 + 128 - pos.y) {
        sfRenderWindow_drawSprite(window, sprite, NULL);
    }
}