/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** print_map
*/

#include "my_rpg.h"

static sfVector2i textures_pos[] = {
    (sfVector2i){1, 0}, (sfVector2i){1, 1},
    (sfVector2i){0, 1}, (sfVector2i){0, 2}, (sfVector2i){0, 3},
    (sfVector2i){1, 3}, (sfVector2i){1, 4}, (sfVector2i){2, 4},
    (sfVector2i){3, 4}, (sfVector2i){3, 3}, (sfVector2i){4, 3},
    (sfVector2i){4, 2}, (sfVector2i){3, 2}, (sfVector2i){4, 1},
    (sfVector2i){3, 1}, (sfVector2i){3, 0}, (sfVector2i){2, 0},
    (sfVector2i){1, 5}, (sfVector2i){1, 6}, (sfVector2i){1, 7},
    (sfVector2i){2, 5}, (sfVector2i){2, 6}, (sfVector2i){2, 7},
    (sfVector2i){3, 5}, (sfVector2i){3, 6}, (sfVector2i){3, 7},
    (sfVector2i){4, 5}, (sfVector2i){4, 6}, (sfVector2i){4, 8},
    (sfVector2i){2, 8}, (sfVector2i){1, 8}, (sfVector2i){3, 8}
};

void print_square(sfVector2i square, int floor, sfVector2i pos,
    main_t *main)
{
    char *type = "abcdefghijklmnopqrstuvwxyzAB1234";
    sfIntRect rect = (sfIntRect){64, 64 + floor * 32 * 5, 32, 32};
    sfSprite_setTextureRect(main->assets.printed, rect);
    sfSprite_setPosition(main->assets.printed,
        (sfVector2f){square.x * 128 - pos.x, square.y * 128 - pos.y});
    sfRenderWindow_drawSprite(main->window, main->assets.printed, NULL);
    for (int i = 0; type[i] != '\0'; i++) {
        if (MAP.map[square.y][square.x] == type[i]) {
            rect.top = textures_pos[i].x * 32 + floor * 32 * 5;
            rect.left = textures_pos[i].y * 32;
            sfSprite_setTextureRect(main->assets.printed, rect);
            sfSprite_setPosition(main->assets.printed,
                (sfVector2f){square.x * 128 - pos.x, square.y * 128 - pos.y});
            sfRenderWindow_drawSprite(
                main->window, main->assets.printed, NULL);
        }
    }
}

void print_map(main_t *main, int floor, sfVector2i pos, character_t *player)
{
    sfSprite_setTexture(main->assets.printed, main->assets.map, sfFalse);
    sfSprite_setScale(main->assets.printed, (sfVector2f) {4, 4});
    sfSprite_setPosition(player->sprite, (sfVector2f) \
                        {player->pos.x - pos.x, player->pos.y - pos.y});
    for (int y = 0; MAP.map[y] != NULL; y++) {
        for (int x = 0; MAP.map[y][x] != '\0'; x++)
            print_square((sfVector2i){x, y}, floor, pos, main);
    }
    RenderWindow_drawParticles(main->window, main->proj.particles, pos);
    for (int y = 0; MAP.map[y] != NULL; y++) {
        for (int x = 0; MAP.map[y][x] != '\0'; x++) {
            print_elem(main, floor, pos, (sfVector2i){x, y});
        }
    }
}

void print_teleporters(sfIntRect *boxes, sfVector2i pos, sfRenderWindow *window)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    if (sfMouse_isButtonPressed(sfMouseRight))
    for (int i = 0; i < 5; i++) {
        if (boxes[i].height != -1) {
            sfRectangleShape_setPosition(rect, (sfVector2f) \
                            {boxes[i].left - pos.x, boxes[i].top - pos.y});
            sfRectangleShape_setSize(rect, (sfVector2f) \
                            {boxes[i].width, boxes[i].height});
            sfRectangleShape_setFillColor(rect, sfBlue);
            sfRenderWindow_drawRectangleShape(window, rect, NULL);
        }
    }
}

void print_boxes(sfIntRect ***boxes, sfVector2i pos, sfRenderWindow *window)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    if (sfMouse_isButtonPressed(sfMouseLeft))
    for (int y = 0; boxes[y] != NULL; y++) {
        for (int x = 0; boxes[y][x] != NULL; x++) {
            if (boxes[y][x]->left != -1) {
                sfRectangleShape_setPosition(rect, (sfVector2f) \
                        {boxes[y][x]->left - pos.x, boxes[y][x]->top - pos.y});
                sfRectangleShape_setSize(rect, (sfVector2f) \
                        {boxes[y][x]->width, boxes[y][x]->height});
                sfRectangleShape_setFillColor(rect, sfRed);
                sfRenderWindow_drawRectangleShape(window, rect, NULL);
            }
        }
    }
}