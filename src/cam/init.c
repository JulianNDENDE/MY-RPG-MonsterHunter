/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** init
*/

#include "structure.h"
#include "param.h"

void init_camera(main_t *main)
{
    sfVector2i pos = {0, 0};

    CAM.map = MAP.map;
    CAM.box = MAP.boxes;
    CAM.cam_pos = pos;
    CAM.target_pos = &(sfVector2f){1600, 1000};
    CAM.is_fighting = 0;
}