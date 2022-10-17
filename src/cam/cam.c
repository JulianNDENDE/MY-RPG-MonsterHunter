/*
** EPITECH PROJECT, 2021
** cam.c
** File description:
** cam function
*/

#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "my_rpg.h"

void move_fcam(info_move_t *info_cam, character_t *character, config_t config)
{
    float move_x = info_cam->target_pos->x - character->pos.x;
    float move_y = info_cam->target_pos->y - character->pos.y;
    if (move_x > (windowx / 4))
        move_x = windowx / 4;
    if (move_y > (windowy / 4))
        move_y = windowy / 4;
    if (move_x < -(windowx / 4))
        move_x = -windowx / 4;
    if (move_y < -(windowy / 4))
        move_y = -windowy / 4;
    info_cam->cam_pos = (sfVector2i) {character->pos.x - (windowx / 2) +
    move_x, character->pos.y - (windowy / 2) + move_y};
}

void fighting_cam(main_t *main)
{
    if (CAM.is_fighting == 1) {
        if (CAM.target_pos != NULL) {
            move_fcam(&CAM, &CHARACT, main->config);
        }
    } else {
        CAM.cam_pos = (sfVector2i) {CHARACT.pos.x - (main->windowx / 2),
        CHARACT.pos.y - (main->windowy / 2)};
    }
}

void triger_cam(main_t *main)
{
    if (sfKeyboard_isKeyPressed(sfKeyF))
        CAM.is_fighting = 1;
    if (sfKeyboard_isKeyPressed(sfKeyC))
        CAM.is_fighting = 0;
}