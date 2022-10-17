/*
** EPITECH PROJECT, 2021
** move.c
** File description:
** move function
*/

#include <math.h>
#include "my_rpg.h"

void realy_moov(main_t *main, sfVector2f move, \
                info_move_t *info_m, config_t config)
{
    sfInt32 time = get_Milliseconds(CHARACT.dashclock, main->clock_error);
    int choice = floor((time % (300 / (int) ceil(CHARACT.speed / 20))) / \
                (100 / (int) ceil(CHARACT.speed / 20)));
    sfIntRect actu = sfSprite_getTextureRect(CHARACT.sprite);

    sfSprite_setTextureRect(CHARACT.sprite,
        R2I(32 * choice, actu.top, actu.width, actu.height));
    CHARACT.move = V2F(move.x, move.y);
    CHARACT.pos = (sfVector2f) \
        {CHARACT.pos.x + move.x, CHARACT.pos.y + move.y};
    info_m->cam_pos = (sfVector2i) \
        {CHARACT.pos.x - (windowx / 2), CHARACT.pos.y - (windowy / 2)};
}

void move_f(int direction, main_t *main)
{
    float positiv = 2;
    float negativ = -2;

    switch (direction) {
    case 1:
        if (check_colide(main, (sfVector2f){0, negativ}) != 1)
            realy_moov(main, (sfVector2f){0, negativ}, &CAM, main->config);
        break;
    case 2:
        if (check_colide(main, (sfVector2f){0, positiv}) != 1)
            realy_moov(main, (sfVector2f){0, positiv}, &CAM, main->config);
        break;
    case 3:
        if (check_colide(main, (sfVector2f){negativ, 0}) != 1)
            realy_moov(main, (sfVector2f){negativ, 0}, &CAM, main->config);
        break;
    case 4:
        if (check_colide(main, (sfVector2f){positiv, 0}) != 1)
            realy_moov(main, (sfVector2f){positiv, 0}, &CAM, main->config);
    }
}

static void update_hitbox(main_t *main)
{
    CHARACT.hitbox = sfSprite_getGlobalBounds(CHARACT.sprite);
    CHARACT.hitbox.width /= 4;
    CHARACT.hitbox.height /= 4;
    CHARACT.hitbox.top += CHARACT.hitbox.height * 1.5;
    CHARACT.hitbox.left += CHARACT.hitbox.width * 1.5;
    sfRectangleShape_setPosition(CHARACT.visual_box, RV2F(CHARACT.hitbox));
    sfRectangleShape_setSize(CHARACT.visual_box, V2F(\
                            CHARACT.hitbox.width, CHARACT.hitbox.height));
}

void main_caract_move(keybind_t *move, main_t *main)
{
    CHARACT.move = V2F(0, 0);
    update_anime(main);
    for (int i = 0; i < CHARACT.speed / (4 + (
        3 * sfKeyboard_isKeyPressed(sfKeyLShift))); i++) {
        if (sfKeyboard_isKeyPressed(move->forward)) {
            move_f(1, main);
        } if (sfKeyboard_isKeyPressed(move->back)) {
            move_f(2, main);
        } if (sfKeyboard_isKeyPressed(move->left)) {
            move_f(3, main);
        } if (sfKeyboard_isKeyPressed(move->right)) {
            move_f(4, main);
        }
    }
    update_hitbox(main);
}

void update_anime(main_t *main)
{
    sfIntRect actu = sfSprite_getTextureRect(main->assets.player);
    sfVector2i mouse = sfMouse_getPosition((const sfWindow *)main->window);
    sfVector2f player = sfSprite_getPosition(CHARACT.sprite);
    float angle = atanf((mouse.y - player.y) / (mouse.x - player.x));

    angle = angle * 180 / M_PI;
    if (mouse.x - player.x < 0)
        angle += 180;
    if (angle >= 45 && angle < 135)
        sfSprite_setTextureRect(main->assets.player, \
                                R2I(actu.width, 0, 32, 32));
    if (angle >= 135 && angle < 225)
        sfSprite_setTextureRect(main->assets.player, \
                                R2I(actu.width, 32, 32, 32));
    if (angle < 45)
        sfSprite_setTextureRect(main->assets.player, \
                                R2I(actu.width, 64, 32, 32));
    if ((angle >= 225 && angle < 270) || angle < -45)
        sfSprite_setTextureRect(main->assets.player, \
                                R2I(actu.width, 96, 32, 32));
}