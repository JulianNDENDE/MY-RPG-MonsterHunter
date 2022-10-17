/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** level_index
*/

#include "map.h"

static map_type type2(const sfBool type[4])
{
    if (type[0] == 1 && type[1] == 0 && type[2] == 1 && type[3] == 0)
        return UP_RIGHT;
    if (type[0] == 1 && type[1] == 0 && type[2] == 0 && type[3] == 1)
        return UP_LEFT;
    if (type[0] == 0 && type[1] == 1 && type[2] == 1 && type[3] == 0)
        return DOWN_RIGHT;
    if (type[0] == 0 && type[1] == 1 && type[2] == 0 && type[3] == 1)
        return DOWN_LEFT;
    if (type[0] == 1 && type[1] == 0 && type[2] == 0 && type[3] == 0)
        return UP;
    if (type[0] == 0 && type[1] == 1 && type[2] == 0 && type[3] == 0)
        return DOWN;
    if (type[0] == 0 && type[1] == 0 && type[2] == 1 && type[3] == 0)
        return RIGHT;
    if (type[0] == 0 && type[1] == 0 && type[2] == 0 && type[3] == 1)
        return LEFT;
    return -1;
}

map_type get_type(const sfBool type[4])
{
    if (type[0] == 1 && type[1] == 1 && type[2] == 1 && type[3] == 1)
        return UP_DOWN_RIGHT_LEFT;
    if (type[0] == 1 && type[1] == 1 && type[2] == 1 && type[3] == 0)
        return UP_DOWN_RIGHT;
    if (type[0] == 1 && type[1] == 1 && type[2] == 0 && type[3] == 1)
        return UP_DOWN_LEFT;
    if (type[0] == 0 && type[1] == 1 && type[2] == 1 && type[3] == 1)
        return DOWN_RIGHT_LEFT;
    if (type[0] == 1 && type[1] == 0 && type[2] == 1 && type[3] == 1)
        return UP_RIGHT_LEFT;
    if (type[0] == 1 && type[1] == 1 && type[2] == 0 && type[3] == 0)
        return UP_DOWN;
    if (type[0] == 0 && type[1] == 0 && type[2] == 1 && type[3] == 1)
        return RIGHT_LEFT;
    return type2(type);
}