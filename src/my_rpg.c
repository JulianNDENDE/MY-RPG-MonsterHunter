/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** my_rpg
*/

#include <stdlib.h>
#include "my_rpg.h"

static void (*to_load[])(main_t *) = {
    &get_textures_basic,
    &init_loading_scene,
    &init_settings,
    &init_boss_hud,
    &get_menu_display,
    NULL
};

void init_rdm(main_t *main)
{
    main->clock = sfClock_create();
    main->runclock = sfClock_create();
    main->global_clock = sfClock_create();
    CAM.cam_pos = (sfVector2i) {
    CHARACT.pos.x - (main->windowx / 2), CHARACT.pos.y - (main->windowy / 2)};
    main->clock_error.microseconds = 0;
    main->proj.wait_list = NULL;
    main->proj.particles = NULL;
    main->hub = sfTrue;
}

void get_config(main_t *main)
{
    char *config = open_file("assets/config");

    main->config.window_x = my_getnbr(my_strtok(&config, '\n') + 9);
    main->config.window_y = my_getnbr(my_strtok(&config, '\n') + 9);
    main->config.map_format = my_getnbr(my_strtok(&config, '\n') + 11);
    main->config.player_base_speed = my_getnbr(my_strtok(&config, '\n') + 18);
    main->config.player_base_atk = my_getnbr(my_strtok(&config, '\n') + 16);
    main->config.player_base_tek = my_getnbr(my_strtok(&config, '\n') + 16);
    main->config.player_base_health = my_getnbr(my_strtok(&config, '\n') + 19);
    main->config.volume = my_getnbr(my_strtok(&config, '\n') + 7);
    main->config.framerate = my_getnbr(my_strtok(&config, '\n') + 10);
    main->config.keys.forward = my_getnbr(my_strtok(&config, '\n') + 8);
    main->config.keys.back = my_getnbr(my_strtok(&config, '\n') + 5);
    main->config.keys.left = my_getnbr(my_strtok(&config, '\n') + 5);
    main->config.keys.right = my_getnbr(my_strtok(&config, '\n') + 6);
    main->config.keys.interact = my_getnbr(my_strtok(&config, '\n') + 9);
    main->config.keys.dash = my_getnbr(my_strtok(&config, '\n') + 5);
    main->config.player_filename = my_strtok(&config, '\n') + 7;
}

int my_rpg(void)
{
    main_t main;
    sfImage *icon = sfImage_createFromFile("assets/sprites/icon.png");

    srand((size_t) &main);
    get_config(&main);
    main.window = create_window
    ((sfVector2f) {main.windowx, main.windowy}, "my_rpg");
    sfRenderWindow_setIcon(main.window, sfImage_getSize(icon).x,
        sfImage_getSize(icon).x, sfImage_getPixelsPtr(icon));
    main.loading_screen = NULL;
    display_waiting_screen(main.window, &main, to_load);
    menu(&main, main.window);
    free_textures_basic(&main);
    sfImage_destroy(icon);
    return 0;
}
