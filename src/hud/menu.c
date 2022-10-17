/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** menu
*/

#include <stdlib.h>
#include "my_rpg.h"

static void (*to_load[])(main_t *) = {
    &get_textures_game,
    &init_map,
    &init_ingame_hud,
    &init_character,
    &init_camera,
    &init_pause,
    &init_rdm,
    &init_hub_pnj,
    NULL
    };

static inline void free_particles(main_t *main)
{
    particle_freeall(&main->proj.particles, &PROJ.wait_list);
}

static void (*to_free[])(main_t *) = {
    &free_particles,
    &free_textures_game,
    &free_game_hud,
    NULL
    };

static void display_all(sfRenderWindow *window, main_t *main)
{
    sfRenderWindow_clear(window, sfWhite);
    display_display(window, main->menu);
    sfRenderWindow_display(window);
}

void get_menu_display(main_t *main)
{
    display_t *display = init_display(1, 0, 0);

    ADD_BUTTON(display->buttons, main->windowx - 40, \
                8, 32, 32, ANIM_LEFT, \
                main->assets.button, "?");
    ADD_BUTTON(display->buttons, 10, 10, \
                400, 50, ANIM_RIGHT, \
                main->assets.button, "Change character");
    ADD_BUTTON(display->buttons, main->windowx - 250, \
                (main->windowy / 2) + 80, 250, 50, ANIM_LEFT, \
                main->assets.button, "Quit");
    ADD_BUTTON(display->buttons, main->windowx - 250, \
                (main->windowy / 2), 250, 50, ANIM_LEFT, \
                main->assets.button, "Settings");
    ADD_BUTTON(display->buttons, main->windowx - 250, \
                (main->windowy / 2) - 70, 250, 50, ANIM_LEFT, \
                main->assets.button, "New Game");
    display->sprites[0] = create_sprite(V2F(0, 0), \
            V2F(main->windowx, main->windowy), main->assets.menu_backgroud);
    main->menu = display;
}

void launch_hub(main_t *main, sfRenderWindow *window)
{
    display_waiting_screen(window, main, to_load);
    display_all_game(window, main);
    set_fade(main, 0);
    game(window, main);
    display_waiting_screen(window, main, to_free);
    sfMusic_stop(main->assets.menu_music);
    sfMusic_destroy(main->assets.menu_music);
    main->assets.menu_music = play_music("assets/music/menu.wav",
                                        main->config.volume, 1);
}

void how_to_play(main_t *main)
{
    sfSprite *htp = create_sprite(V2F(0, 0), V2F(main->windowx, main->windowy),
                                main->assets.htp);

    sfRenderWindow_drawSprite(main->window, htp, NULL);
    sfRenderWindow_display(main->window);
    while (!sfKeyboard_isKeyPressed(sfKeyEscape) && 
            !sfMouse_isButtonPressed(sfMouseRight)) {
        is_having_to_close(main->window);
    }
}

int menu(main_t *main, sfRenderWindow *window)
{
    while (sfRenderWindow_isOpen(window)) {
        is_having_to_close(window);
        switch (get_button(main->menu->buttons, window)) {
        case 0:
            launch_hub(main, window);
            break;
        case 1:
            settings(main, window);
            break;
        case 2:
            sfRenderWindow_close(window);
            break;
        case 3:
            change_character(main);
            break;
        case 4:
            how_to_play(main);
        }
        display_all(window, main);
    }
    return 0;
}