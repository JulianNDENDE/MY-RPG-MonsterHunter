/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** print_map
*/

#include "my_rpg.h"

void print_tp(sfVector2i map_pos, sfVector2i pos, main_t *main)
{
    anim_object(MAP.object[3], main->global_clock);
    char type = 'I';
    if (MAP.map[map_pos.y][map_pos.x] == type && CURENT_MAP.print_tp == 1) {
        sfSprite_setPosition(MAP.object[3]->sprite, (sfVector2f) \
                    {map_pos.x * 128 - pos.x, map_pos.y * 128 - pos.y - 96});
        sfRenderWindow_drawSprite(main->window, \
                                    MAP.object[3]->sprite, NULL);
    }
}

void print_anim(sfVector2i map_pos, int floor, sfVector2i pos, main_t *main)
{
    anim_object(MAP.object[0], main->global_clock);
    anim_object(MAP.object[1], main->global_clock);
    anim_object(MAP.object[2], main->global_clock);
    char type = 'X';
    if ((floor == 0 || floor == 1) && MAP.map[map_pos.y][map_pos.x] == type) {
        sfSprite_setPosition(MAP.object[floor]->sprite, (sfVector2f) \
                    {map_pos.x * 128 - pos.x, (map_pos.y - 1) * 128 - pos.y});
        sfRenderWindow_drawSprite(main->window, \
                                    MAP.object[floor]->sprite, NULL);
    }
    if (floor == 2 && MAP.map[map_pos.y][map_pos.x] == type) {
        sfSprite_setPosition(MAP.object[2]->sprite, (sfVector2f) \
                        {map_pos.x * 128 - pos.x, map_pos.y * 128 - pos.y});
        sfRenderWindow_drawSprite(main->window, MAP.object[2]->sprite, NULL);
    }
}

void print_elem(main_t *main, int floor, sfVector2i pos, sfVector2i square)
{
    print_anim((sfVector2i) {square.x, square.y}, floor, pos, main);
    print_tp((sfVector2i) {square.x, square.y}, pos, main);
    if (MAP.lvl[MAP.y][MAP.x].enemy)
        print_enemies_behind(square.y, main, pos);
    if (MAP.lvl[MAP.y][MAP.x].pnj)
        print_pnj_behind(square.y, main, pos);
    print_character(main->assets.player, square.y, main->window, pos);
    if (MAP.lvl[MAP.y][MAP.x].enemy)
        print_enemies_front(square.y, main, pos);
    if (MAP.lvl[MAP.y][MAP.x].pnj)
        print_pnj_front(square.y, main, pos);
}