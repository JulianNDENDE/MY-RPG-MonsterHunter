/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** game
*/

#include "my_rpg.h"
#include <stdlib.h>

void display_all_game(sfRenderWindow *window, main_t *main)
{
    sfRenderWindow_clear(window, sfBlack);
    print_map(main, MAP.floor, CAM.cam_pos, &CHARACT);
    if (main->bonus) {
        sfSprite_setPosition(main->bonus->sprite, V2F(
                            main->bonus->pos->x - CAM.cam_pos.x,
                            main->bonus->pos->y - CAM.cam_pos.y));
        sfRenderWindow_drawSprite(window, main->bonus->sprite, NULL);
    }
    if (sfKeyboard_isKeyPressed(sfKeyLShift))
        sfRenderWindow_drawRectangleShape(window, CHARACT.visual_box, NULL);
    display_display(window, main->game);
    if (main->hub == sfFalse && main->minimap)
        print_minimap(main->minimap, window, main->config);
    else if (main->hub == sfFalse && CURENT_MAP.enemy != NULL) {
        update_boss_bar(main, CURENT_MAP.enemy[0]->pv,
            CURENT_MAP.enemy[0]->pv_max);
        display_display(window, main->boss_hud);
    }
}

void update_map(main_t *main)
{
    if (CURENT_MAP.print_tp == sfTrue &&
        is_collide(&MAP.teleporters[4], &CHARACT, (sfVector2f){0, 0}) == 1 &&
        CURENT_MAP.passed == sfTrue && main->bonus == NULL) {
        main->character.pv += main->character.pv_max / 3;
        if (main->character.pv > main->character.pv_max)
            main->character.pv = main->character.pv_max;
        update_live_bar(main->game, main->character.pv,
            main->character.pv_max);
        if (**MAP.map == '!')
            go_to_next_lvl(main);
        else
            go_to_boss(main);
    }
}

void update_collision(main_t *main)
{
    if (main->bonus)
        catch_bonus(main);
    if (main->hub == sfFalse && \
        get_Microseconds(CHARACT.clock, main->clock_error) > \
        CHARACT.invicibility_time.microseconds && \
        particle_check_colision(main)) {
        update_live_bar(main->game, CHARACT.pv, CHARACT.pv_max);
        sfClock_restart(CHARACT.clock);
    }
}

void update(main_t *main)
{
    particle_update(&PROJ.wait_list, &PROJ.particles,
        main->clock_error);
    command_check(&PROJ.wait_list, &PROJ.particles,
        main->clock_error, MAP.boxes);
    if (check_pos(main) == 84) {
        sfRenderWindow_close(main->window);
        return;
    }
    main_caract_move(&main->config.keys, main);
    dash(main);
    update_ennemy(main);
    triger_cam(main);
    fighting_cam(main);
    update_map(main);
    pnj_check(main, MAP.lvl[MAP.y][MAP.x].pnj, CHARACT.hitbox);
    if (!main->hub)
        check_attack(main);
    update_collision(main);
    update_stamina_bar(main->game, main->character.stamina,
        main->character.maxstamina);
}

//void test(main_t *main);

void game(sfRenderWindow *window, main_t *main)
{
    while (sfRenderWindow_isOpen(window)) {
        is_having_to_close(window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) ||
            !sfRenderWindow_hasFocus(window)) {
            if (pause_game(main) == -1)
                return;
            clock_skip_passed_time(main->clock, &main->clock_error);
        }
        while (get_Milliseconds(main->clock, main->clock_error) > 30) {
            update(main);
            clock_restart(main->clock, &main->clock_error);
        }
        if (CHARACT.pv <= 0 || main->hub == -1) {
            set_fade(main, 1);
            return;
        }
        display_all_game(window, main);
        sfRenderWindow_display(window);
    }
}