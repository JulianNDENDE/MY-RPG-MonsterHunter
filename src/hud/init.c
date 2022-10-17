/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** init
*/

#include "my_rpg.h"

static void init_button_setting(display_t *settings, sfTexture *texture,
    config_t config)
{
    ADD_BUTTON(settings->buttons, 300, (windowy / 4) * 3, 424, 50,
        ANIM_RED, texture, "Return");
    ADD_BUTTON(settings->buttons, 300, windowy / 4, 50, 50,
        ANIM_RED, texture, "15");
    ADD_BUTTON(settings->buttons, 400, windowy / 4, 50, 50,
        ANIM_RED, texture, "30");
    ADD_BUTTON(settings->buttons, 500, windowy / 4, 50, 50,
        ANIM_RED, texture, "60");
    ADD_BUTTON(settings->buttons, 565, (windowy / 4) * 2, 10, 30,
        NULL, texture, NULL);
}

void init_settings(main_t *main)
{
    display_t *settings = init_display(2, 2, 0);
    sfTexture *check = sfTexture_createFromFile("assets/hud/check.png", NULL);

    settings->texts[0] = create_text((sfVector2f) {20, main->windowy / 4},
        "Framerate:", 35, main->assets.font);
    settings->texts[1] = create_text((sfVector2f) {20,
        (main->windowy / 4) * 2}, "Volume:", 35, main->assets.font);
    settings->sprites[0] = create_sprite((sfVector2f) {380,
        main->windowy / 4 - 30}, (sfVector2f) {110, 110}, check);
    settings->sprites[1] = create_sprite((sfVector2f) {270, (main->windowy /
        4) * 2 + 10}, (sfVector2f) {310, 10}, main->assets.button);
    settings->sprites[2] = create_sprite((sfVector2f) {0, 0}, (sfVector2f) {
        main->windowx, main->windowy}, main->assets.menu_backgroud);
    init_button_setting(settings, main->assets.button, main->config);
    main->settings = settings;
}

void init_boss_hud(main_t *main)
{
    display_t *display = init_display(1, 1, 1);
    display->sprites[0] = create_sprite((sfVector2f) {main->windowx / 3, 20}, \
        (sfVector2f) {main->windowx / 2 + 2, 20}, main->assets.bar);
    display->texts[0] = create_text((sfVector2f) {main->windowx / 3 + 4, 16}, \
        "100 / 100", 20, main->assets.font);
    display->shapes[0] = sfRectangleShape_create();
    sfRectangleShape_setPosition(display->shapes[0],
        (sfVector2f) {main->windowx / 3, 21});
    main->boss_hud = display;
}

void init_ingame_hud(main_t *main)
{
    display_t *display = init_display(2, 1, 2);

    main->minimap = NULL;
    display->sprites[0] = create_sprite((sfVector2f) {50, 20}, \
                            (sfVector2f) {302, 20}, main->assets.bar);
    display->sprites[1] = create_sprite((sfVector2f) {50, 45}, \
                            (sfVector2f) {252, 12}, main->assets.bar);
    display->texts[0] = create_text((sfVector2f) {54, 16}, \
                    "100 / 100", 20, main->assets.font);
    display->shapes[0] = sfRectangleShape_create();
    sfRectangleShape_setPosition(display->shapes[0], (sfVector2f) {51, 21});
    display->shapes[1] = sfRectangleShape_create();
    sfRectangleShape_setPosition(display->shapes[1], (sfVector2f) {51, 46});
    sfRectangleShape_setFillColor(display->shapes[1], sfBlue);
    main->game = display;
}

void free_game_hud(main_t *main)
{
    free_display(main->game);
    free_display(main->pause);
}