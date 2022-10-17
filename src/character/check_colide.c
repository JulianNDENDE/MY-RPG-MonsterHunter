/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** check_colide
*/

#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "my_rpg.h"

sfVector2f get_size_map_colid(char **map, config_t config)
{
    int height = 0;
    int width = 0;
    int width_max = 0;
    while (map[height] != NULL) {
        while (map[height][width] != '\0') {
            width_max = get_width_max(map[height], width_max);
            width++;
        }
        width = 0;
        height++;
    }
    return ((sfVector2f){width_max * MAP_FORMAT, height * MAP_FORMAT});
}

int check_colide_map(sfVector2f move, sfVector2f pos, \
                    sfVector2f size, config_t config)
{
    if (move.x != 0 && (move.x + pos.x - (size.x / 2) < 0 \
        || move.x + pos.x + (size.x / 2) > windowx))
        return (1);
    if (move.y != 0 && (move.y + pos.y - (size.y / 2) < 0 \
        || move.y + pos.y + (size.y / 2) > windowy))
        return (1);
    return (0);
}

int is_collide(sfIntRect *box, character_t *character, sfVector2f move)
{
    float left = character->pos.x - (character->size.x / 2);
    float down = character->pos.y + (character->size.y / 2);
    sfFloatRect rect = {box->left, box->top, box->width, box->height};
    sfFloatRect player_box = (sfFloatRect) {
        left + move.x, down - 2 + move.y, character->size.x, 2};

    if (box == NULL || box->top == -1)
        return (0);
    if (sfFloatRect_intersects(&rect, &player_box, NULL))
        return 1;
    return (0);
}

int check_colide_box(main_t *main, sfVector2f move)
{
    int x = floor(CHARACT.pos.x / main->MAP_FORMAT);
    int y = floor(CHARACT.pos.y / main->MAP_FORMAT);

    for (int index = 0; index < 3; index++) {
        for (int tg = 0; tg < 3; tg++) {
            if (is_collide(CAM.box[abs(y - 1) + index][abs(x - 1) + tg], \
                            &CHARACT, move) == 1)
                return (1);
        }
    }
    if (switch_map(main, move))
        return 1;
    return (0);
}

int check_colide(main_t *main, sfVector2f move)
{
    sfFloatRect char_rect = sfSprite_getGlobalBounds(CHARACT.sprite);

    CHARACT.size = (sfVector2f){char_rect.width, char_rect.height};
    if (check_colide_box(main, move) == 1)
        return (1);
    return (0);
}