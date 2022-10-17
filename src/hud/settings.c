/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** settings
*/

#include <stdlib.h>
#include "hud.h"
#include "param.h"

static inline void set_framerate(main_t *main, int pos, int framerate)
{
    sfSprite_setPosition(SETTINGS->sprites[0],
                         V2F(pos, main->windowy / 4 - 30));
    main->config.framerate = framerate;
}

static void display_all(sfRenderWindow *window, display_t *display)
{
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, display->sprites[2], NULL);
    sfRenderWindow_drawSprite(window, display->sprites[1], NULL);
    RenderWindow_drawAllButtons(window, display->buttons);
    sfRenderWindow_drawText(window, display->texts[0], NULL);
    sfRenderWindow_drawText(window, display->texts[1], NULL);
    sfRenderWindow_drawSprite(window, display->sprites[0], NULL);
    sfRenderWindow_display(window);
}

static float move_cursor(display_t *settings, sfRenderWindow *window, \
                        config_t config)
{
    sfVector2i mouse;
    sfVector2f pos;

    while (sfMouse_isButtonPressed(sfMouseLeft)) {
        mouse = sfMouse_getPositionRenderWindow(window);
        if (mouse.x > 565)
            mouse.x = 565;
        if (mouse.x < 275)
            mouse.x = 275;
        button_set_position(settings->buttons->data, \
                            V2F(mouse.x, (windowy / 4) * 2));
        display_all(window, settings);
    }
    pos = button_get_position(settings->buttons->data);
    return ((pos.x - 275) / 3);
}

static int framerate(main_t *main, sfRenderWindow *window)
{
    switch (get_button(SETTINGS->buttons, window)) {
    case 1:
        set_framerate(main, 480, 60);
        break;
    case 2:
        set_framerate(main, 380, 30);
        break;
    case 3:
        set_framerate(main, 280, 15);
        break;
    case 4:
        sfRenderWindow_setFramerateLimit(window, main->config.framerate);
        return 1;
    case 0:
        main->config.volume = move_cursor(SETTINGS, window, main->config);
    }
    return 0;
}

void settings(main_t *all, sfRenderWindow *window)
{
    while (sfRenderWindow_isOpen(window)) {
        is_having_to_close(window);
        if (framerate(all, window) == 1)
            return;
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            return;
        sfMusic_setVolume(all->assets.menu_music, all->config.volume);
        display_all(window, all->settings);
    }
}