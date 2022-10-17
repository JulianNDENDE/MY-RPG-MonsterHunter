/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** load_textures
*/

#include "my_rpg.h"

static void get_textures_game_2(main_t *main)
{
    main->assets.inventory = sfTexture_createFromFile(
        "assets/hud/inventory.png", NULL);
    main->assets.pillar = sfTexture_createFromFile(
        "assets/sprites/anim/pillar.png", NULL);
    main->assets.enemy = sfTexture_createFromFile(
        "assets/sprites/bird_up.png", NULL);
    main->assets.pnj1 = sfTexture_createFromFile(
        "assets/sprites/pnj/Male 12-1.png", NULL);
    main->assets.pnj3 = sfTexture_createFromFile(
        "assets/sprites/pnj/Male 13-2.png", NULL);
    main->assets.pnj2 = sfTexture_createFromFile(
        "assets/sprites/pnj/Female 18-2.png", NULL);
    main->assets.pnj4 = sfTexture_createFromFile(
        "assets/sprites/pnj/Dog 01-3.png", NULL);
    sfSprite_setTexture(main->assets.player, sfTexture_createFromFile(
                        main->config.player_filename, NULL), sfFalse);
    sfSprite_setTextureRect(main->assets.player, (sfIntRect){0, 0, 32, 32});
    sfSprite_setScale(main->assets.player, V2F(2, 2));
}

void get_textures_game(main_t *main)
{
    main->assets.tree1 = sfTexture_createFromFile(
        "assets/sprites/anim/tree1.png", NULL);
    main->assets.tree2 = sfTexture_createFromFile(
        "assets/sprites/anim/tree2.png", NULL);
    main->assets.rock1 = sfTexture_createFromFile(
        "assets/sprites/anim/rock1.png", NULL);
    main->assets.map = sfTexture_createFromFile(
        "assets/sprites/map.png", NULL);
    main->assets.boss = sfTexture_createFromFile(
        "assets/sprites/boss.png", NULL);
    main->assets.mob = sfTexture_createFromFile(
        "assets/sprites/mob.png", NULL);
    main->assets.printed = sfSprite_create();
    main->assets.player = sfSprite_create();
    main->assets.quest_complete = sfTexture_createFromFile(
        "assets/hud/clear.png", NULL);
    get_textures_game_2(main);
}

void get_textures_basic(main_t *main)
{
    main->assets.button = sfTexture_createFromFile(
        "assets/hud/button.png", NULL);
    main->assets.bonus = sfTexture_createFromFile(
        "assets/hud/bonus.png", NULL);
    main->assets.bar = sfTexture_createFromFile(
        "assets/hud/life_bar.png", NULL);
    main->assets.font = sfFont_createFromFile("assets/hud/Monster_hunter.ttf");
    main->assets.loading_backgroud = sfTexture_createFromFile(
        "assets/hud/loading.png", NULL);
    main->assets.menu_backgroud = sfTexture_createFromFile(
        "assets/hud/menu_2.jpg", NULL);
    main->assets.menu_music = play_music("assets/music/menu.wav", \
                                        main->config.volume, 1);
    main->assets.htp = sfTexture_createFromFile(
        "assets/hud/howtoplay.png", NULL);
}

void free_textures_game(main_t *main)
{
    sfTexture_destroy(main->assets.tree1);
    sfTexture_destroy(main->assets.tree2);
    sfTexture_destroy(main->assets.rock1);
    sfTexture_destroy(main->assets.map);
    sfTexture_destroy(main->assets.boss);
    sfTexture_destroy(main->assets.quest_complete);
    sfTexture_destroy(main->assets.inventory);
    sfTexture_destroy(main->assets.pillar);
    sfTexture_destroy(main->assets.enemy);
    sfTexture_destroy(main->assets.mob);
    sfTexture_destroy(main->assets.pnj1);
    sfTexture_destroy(main->assets.pnj2);
    sfTexture_destroy(main->assets.pnj3);
    sfTexture_destroy(main->assets.pnj4);
    sfSprite_destroy(main->assets.printed);
    sfSprite_destroy(main->assets.player);
}

void free_textures_basic(main_t *main)
{
    sfTexture_destroy(main->assets.button);
    sfTexture_destroy(main->assets.bar);
    sfTexture_destroy(main->assets.loading_backgroud);
    sfTexture_destroy(main->assets.menu_backgroud);
    sfTexture_destroy(main->assets.bonus);
    sfFont_destroy(main->assets.font);
    sfMusic_stop(main->assets.menu_music);
    sfMusic_destroy(main->assets.menu_music);
    sfTexture_destroy(main->assets.htp);
}