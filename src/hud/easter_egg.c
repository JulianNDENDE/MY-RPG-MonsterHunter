/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** easter_egg
*/

#include "my_rpg.h"

void niconiconiiii(main_t *main)
{
    sfMusic_stop(main->assets.menu_music);
    sfMusic_destroy(main->assets.menu_music);
    main->assets.menu_music = play_music("assets/music/niconiconiii.wav", \
                                        main->config.volume, 1);
}

void doku_mitenda(main_t *main)
{
    sfMusic *sound = play_music("assets/music/dokomitenda.wav", 100, 0);
    sfClock *clock = sfClock_create();

    sfMusic_pause(main->assets.menu_music);
    while (get_Second(clock, (sfTime) {0}) < 7);
    sfMusic_stop(sound);
    sfMusic_destroy(sound);
    sfMusic_play(main->assets.menu_music);
}