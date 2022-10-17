/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** switch_map
*/

#include "my_rpg.h"

static int switch_map4(main_t *main, sfVector2f move)
{
    if (is_collide(&MAP.teleporters[1], &CHARACT, move) == 1\
                    && MAP.maze[MAP.y][MAP.x + 1] == 'X') {
        if (CURENT_MAP.passed == sfFalse || main->bonus)
            return 1;
        MAP.map = MAP.lvl[MAP.y][++MAP.x].map;
        update_all1(main);
        CHARACT.pos = (sfVector2f) {MAP.teleporters[3].left + \
        MAP.teleporters[3].width + 50, MAP.teleporters[3].top + \
        MAP.teleporters[0].height / 2};
        if (main->hub == sfFalse)
            update_minimap(main->minimap, 1, 0);
        update_all2(main);
    }
    return 0;
}

static int switch_map3(main_t *main, sfVector2f move)
{
    if (is_collide(&MAP.teleporters[2], &CHARACT, move) == 1\
                && MAP.maze[MAP.y + 1] && MAP.maze[MAP.y + 1][MAP.x] == 'X') {
        if (CURENT_MAP.passed == sfFalse || main->bonus)
            return 1;
        MAP.map = MAP.lvl[++MAP.y][MAP.x].map;
        update_all1(main);
        CHARACT.pos = (sfVector2f) {MAP.teleporters[0].left + \
        MAP.teleporters[0].width / 2, MAP.teleporters[0].top + \
        MAP.teleporters[0].height};
        if (main->hub == sfFalse)
            update_minimap(main->minimap, 0, 1);
        update_all2(main);
    }
    return switch_map4(main, move);
}

static int switch_map2(main_t *main, sfVector2f move)
{
    if (is_collide(&MAP.teleporters[0], &CHARACT, move) == 1\
                    && MAP.y - 1 >= 0 && MAP.maze[MAP.y - 1][MAP.x] == 'X') {
        if (CURENT_MAP.passed == sfFalse || main->bonus)
            return 1;
        MAP.map = MAP.lvl[--MAP.y][MAP.x].map;
        if (main->hub == sfTrue && MAP.y == 0 && MAP.x == 1) {
            launch_game(main);
            return 0;
        }
        update_all1(main);
        CHARACT.pos = (sfVector2f) {MAP.teleporters[2].left + \
        MAP.teleporters[2].width / 2, MAP.teleporters[2].top - 50};
        if (main->hub == sfFalse)
            update_minimap(main->minimap, 0, -1);
        update_all2(main);
    }
    return switch_map3(main, move);
}

int switch_map(main_t *main, sfVector2f move)
{
    if (is_collide(&MAP.teleporters[3], &CHARACT, move) == 1\
                    && MAP.x - 1 >= 0 && MAP.maze[MAP.y][MAP.x - 1] == 'X') {
        if (CURENT_MAP.passed == sfFalse || main->bonus)
            return 1;
        MAP.map = MAP.lvl[MAP.y][--MAP.x].map;
        update_all1(main);
        CHARACT.pos = (sfVector2f) {MAP.teleporters[1].left - 50, \
        MAP.teleporters[1].top + MAP.teleporters[1].height / 2};
        if (main->hub == sfFalse)
            update_minimap(main->minimap, -1, 0);
        update_all2(main);
    }
    return switch_map2(main, move);
}