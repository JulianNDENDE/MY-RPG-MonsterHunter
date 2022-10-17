/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** tp
*/

#include "my_rpg.h"

void set_fade(main_t *main, sfBool bool)
{
    sfRectangleShape *shape = sfRectangleShape_create();
    sfColor color = {0, 0, 0, 0};

    sfRectangleShape_setSize(shape, V2F(main->windowx, main->windowy));
    if (bool == 0)
        color.a = 250;
    for (size_t i = 0; i < 10; i++) {
        if (bool == 0)
            color.a -= 25;
        if (bool == 1)
            color.a += 25;
        sfRectangleShape_setFillColor(shape, color);
        if (bool == 0)
            display_all_game(main->window, main);
        sfRenderWindow_drawRectangleShape(main->window, shape, NULL);
        sfRenderWindow_display(main->window);
    }
}

void update_all1(main_t *main)
{
    set_fade(main, 1);
    MAP.teleporters = get_teleporters(MAP.map, main->config);
    MAP.boxes = get_boxes(MAP.map, MAP.floor, main->config);
}

void update_all2(main_t *main)
{
    particle_freeall(&PROJ.particles, &PROJ.wait_list);
    CAM.box = MAP.boxes;
    CAM.cam_pos = (sfVector2i) {CHARACT.pos.x - (main->windowx / 2), \
                                CHARACT.pos.y - (main->windowy / 2)};
    set_fade(main, 0);
}