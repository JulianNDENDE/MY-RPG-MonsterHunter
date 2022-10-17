/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** change_lvl
*/

#include "my_rpg.h"

static sfVector2f get_spawn(main_t *main)
{
    PARSE_MAP(MAP.map) {
        if (MAP.map[y][x] == 'I')
            return (V2F(x * main->MAP_FORMAT + (main->MAP_FORMAT / 2),
                y * main->MAP_FORMAT + (main->MAP_FORMAT / 2)));
    }
    return (V2F(1800, 800));
}

void end_game(main_t *main)
{
    sfMusic *complete = play_music("assets/music/quest complete.wav", \
                                    main->config.volume, 0);
    display_t *display = init_display(1, 1, 0);
    sfMusic_stop(main->assets.menu_music);
    ADD_BUTTON(display->buttons, main->windowx / 3, (main->windowy / 3) * 2, \
    main->windowx / 3, 50, ANIM_RED, main->assets.button, "return to menu");
    display->sprites[0] = create_sprite(
    V2F(main->windowx / 5, main->windowy / 6),
    V2F(main->windowx / 2, main->windowy / 3), main->assets.quest_complete);
    score_manager(main, display);
    while (sfRenderWindow_isOpen(main->window) &&
        get_button(display->buttons, main->window) != 0) {
        is_having_to_close(main->window);
        display_display(main->window, display);
        sfRenderWindow_display(main->window);
    }
    free_display(display);
    sfMusic_stop(complete);
    sfMusic_destroy(complete);
    main->hub = -1;
}

void go_to_next_lvl(main_t *main)
{
    if (MAP.floor == 2) {
        end_game(main);
        return;
    }
    set_fade(main, 1);
    particle_freeall(&PROJ.particles, &PROJ.wait_list);
    free_maps(main);
    rdm_map(main);
    CAM.box = MAP.boxes;
    CHARACT.pos = get_spawn(main);
    CAM.cam_pos = (sfVector2i) {CHARACT.pos.x - (main->windowx / 2),
        CHARACT.pos.y - (main->windowy / 2)};
    main->minimap = init_minimap(10, 10, main);
    reload_minimap(main->minimap, 10, 10);
    display_all_game(main->window, main);
    set_fade(main, 0);
}

void go_to_boss(main_t *main)
{
    set_fade(main, 1);
    particle_freeall(&PROJ.particles, &PROJ.wait_list);
    free_maps(main);
    boss_map(main);
    CAM.box = MAP.boxes;
    CHARACT.pos = get_spawn(main);
    CAM.cam_pos = (sfVector2i) {CHARACT.pos.x - (main->windowx / 2),
        CHARACT.pos.y - (main->windowy / 2)};
    main->minimap = NULL;
    display_all_game(main->window, main);
    set_fade(main, 0);
}

void launch_game(main_t *main)
{
    set_fade(main, 1);
    MAP.floor = -1;
    sfMusic_stop(main->assets.menu_music);
    sfMusic_destroy(main->assets.menu_music);
    main->assets.menu_music = play_music("assets/music/in game.wav",
                                        main->config.volume, 1);
    particle_freeall(&PROJ.particles, &PROJ.wait_list);
    free_maps(main);
    rdm_map(main);
    CAM.box = MAP.boxes;
    CHARACT.pos = get_spawn(main);
    CAM.cam_pos = (sfVector2i) {CHARACT.pos.x - (main->windowx / 2),
        CHARACT.pos.y - (main->windowy / 2)};
    main->minimap = init_minimap(10, 10, main);
    main->hub = sfFalse;
    sfClock_restart(main->runclock);
    reload_minimap(main->minimap, 10, 10);
    display_all_game(main->window, main);
    set_fade(main, 0);
}