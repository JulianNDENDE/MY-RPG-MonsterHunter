/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** pause
*/

#include <stdlib.h>
#include "my_rpg.h"

void init_pause(main_t *main)
{
    display_t *display = init_display(1, 3, 0);

    ADD_BUTTON(display->buttons, 10, 600, 250, 50, \
                ANIM_RED, main->assets.button, "Quit");
    ADD_BUTTON(display->buttons, 10, 500, 250, 50, \
                ANIM_RED, main->assets.button, "Settings");
    ADD_BUTTON(display->buttons, 10, 400, 250, 50, \
                ANIM_RED, main->assets.button, "Continue");
    display->texts[0] = create_text(
                        (sfVector2f) {350, 400}, "0", 40, main->assets.font);
    display->texts[1] = create_text(
                        (sfVector2f) {350, 500}, "0", 40, main->assets.font);
    display->texts[2] = create_text(
                        (sfVector2f) {350, 600}, "0", 40, main->assets.font);
    display->sprites[0] = create_sprite(
                            V2F(main->windowx - 300, main->windowy / 5), \
                            V2F(296, 528), main->assets.inventory);
    main->pause = display;
}

static void display_all(main_t *main, sfRenderWindow *window, list_l *inventory)
{
    display_display(window, main->pause);
    get_button(inventory, window);
    RenderWindow_drawAllButtons(window, inventory);
    sfRenderWindow_display(window);
}

void draw_stats_pause(main_t *main)
{
    weapon_t *weapon_1 = CHARACT.weapon_atk;
    weapon_t *weapon_2 = CHARACT.weapon_tek;
    char *buf = my_strcat("Attack damage:\t\t ",
        my_getstr(weapon_1->damage));

    sfText_setString(main->pause->texts[0], buf);
    free(buf);
    buf = my_strcat("Technique damage:\t", my_getstr(weapon_2->damage));
    sfText_setString(main->pause->texts[1], buf);
    free(buf);
    buf = my_strcat("Speed:\t\t\t\t\t\t ", my_getstr(CHARACT.speed));
    sfText_setString(main->pause->texts[2], buf);
    free(buf);
}

static list_l *start_pause(main_t *main)
{
    sfRectangleShape *shape = create_rectangleshape(
        (sfFloatRect) {0, 0, main->windowx, main->windowy}, \
        (sfColor) {0, 0, 0, 120});
    sfRectangleShape *txt_shape = create_rectangleshape(
        (sfFloatRect) {325, 375, 700, 300}, (sfColor) {0, 0, 0, 60});
    list_l *inventory = NULL;

    sfRenderWindow_drawRectangleShape(main->window, shape, NULL);
    sfRenderWindow_drawRectangleShape(main->window, txt_shape, NULL);
    inventory = set_inventory(main);
    sfRectangleShape_destroy(shape);
    sfRectangleShape_destroy(txt_shape);
    draw_stats_pause(main);
    return inventory;
}

int pause_game(main_t *main)
{
    list_l *inventory = start_pause(main);

    while (sfRenderWindow_isOpen(main->window)) {
        is_having_to_close(main->window);
        switch (get_button(main->pause->buttons, main->window)) {
        case 0:
            return 0;
        case 1:
            settings(main, main->window);
            display_all_game(main->window, main);
            inventory = start_pause(main);
            break;
        case 2:
            return -1;
        }
        display_all(main, main->window, inventory);
    }
    return -1;
}