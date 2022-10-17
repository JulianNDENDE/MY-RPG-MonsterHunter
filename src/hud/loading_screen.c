/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** loading_screen
*/

#include <stdlib.h>
#include "my_rpg.h"

static char *tricks[] = {
    "Bilj est une autruche",
    "Diams est un poulpe",
    "Strake est un dindon",
    "Xera est un paresseux",
    "Aujourd'hui, c'est ton jour de vaisselle",
    "mange tes morts (pour obtenir leur pouvoirs)",
    "Connais tu Nord VPN ?",
    "LOadInG ...",
    "Bird Up !!",
    "Attend un peu",
    "pls wait",
    "Ca charge",
    "Master shifu, un sushi?",
    "Quelle est l'evolution de ronflex.... Xera",
    "Niconiconiiiiiiiiii!!!!",
    "Marvin si tu lis cet ligne, ne m'en veut pas, mais t'es mechant",
    "Je suis en vacances",
    "J'ai faim",
    "Tourne a droite, non l'autre droite",
    "Imagine une pizza XXL aux 10 fromages",
    "Imagine un bon tacos 6 viandes",
    "Imagine un burger avec 8 steaks",
    "Imagine un gateau 3 chocolats et Nutella",
    "Imagine une raclette",
    "Imagine une carotte Dio, euh... bio",
    "Tu as faim ?",
    "<3",
    "Lukas pas de micro",
    "C'est du pipo.",
    "Dessine moi un mouton",
    "Un Maximator?",
    "Wololoooo",
    "Soit mignon",
    "Ta gueule!",
    "Oui mais c'est pas toi qui decide",
    "Et zest partis!",
    "Imagine le monde sans toi, snif (ou pas)",
    "On s'fait un fifa?",
    "Ursaff",
    "8 morts, 6 blesses",
    "rhinoshield!!!!!",
    "C'est Thanos ou Monsieurs propre",
    "C'est fort en chocolaaaat !!!!!",
    "Full flemme",
    "Doko mitendayo",
    NULL
};

char *get_tip(void)
{
    int len = 0;

    while (tricks[len] != NULL)
        len += 1;
    return tricks[RDM(0, len)];
}

char *set_up_loading(main_t *main)
{
    char *str = get_tip();

    if (main->loading_screen && \
        my_str_is_identical(str, "Niconiconiiiiiiiiii!!!!"))
        niconiconiiii(main);
    if (main->loading_screen) {
        sfRectangleShape_setSize(main->loading_screen->shapes[0], V2F(0, 20));
        sfText_setPosition(main->loading_screen->texts[0], (sfVector2f) \
            {main->windowx / 2 - my_strlen(str) * 8, main->windowy - 120});
        sfText_setString(main->loading_screen->texts[0], str);
    }
    return str;
}

void display_waiting_screen(sfRenderWindow *window, main_t *main, \
                            void (*to_load[])(main_t *))
{
    int len = 0;
    char *str = set_up_loading(main);

    for (len = 0; to_load[len]; len++);
    sfRenderWindow_setFramerateLimit(window, 4);
    for (int i = 0; i < len; i++) {
        to_load[i](main);
        if (main->loading_screen)
            loading_screen(main->loading_screen, \
                            (float) 100 / len, window, main->config);
    }
    if (my_str_is_identical(str, "Doko mitendayo"))
        doku_mitenda(main);
    sfRenderWindow_setFramerateLimit(window, main->config.framerate);
}

void init_loading_scene(main_t *main)
{
    char *str = get_tip();

    main->loading_screen = init_display(2, 1, 1);
    main->loading_screen->shapes[0] = create_rectangleshape(\
        (sfFloatRect) {50, main->windowy - 70, 0, 20}, sfRed);
    main->loading_screen->sprites[1] = create_sprite((sfVector2f)
    {40, main->windowy - 73}, (sfVector2f) {
                    main->windowx - 132, 26}, main->assets.bar);
    main->loading_screen->sprites[0] = create_sprite((sfVector2f)
    {0, 0}, (sfVector2f) {
        main->windowx, main->windowy}, main->assets.loading_backgroud);
    main->loading_screen->texts[0] = create_text((sfVector2f) \
            {main->windowx / 2 - my_strlen(str) * 8, main->windowy - 120},
            str, 30, main->assets.font);
}

void loading_screen(display_t *loading, float percent, \
                    sfRenderWindow *window, config_t config)
{
    sfVector2f size = sfRectangleShape_getSize(loading->shapes[0]);

    sfRectangleShape_setSize(loading->shapes[0], (sfVector2f) {\
            size.x + (percent * (windowx - 150) / 100), size.y});
    sfRenderWindow_clear(window, sfWhite);
    display_display(window, loading);
    sfRenderWindow_display(window);
}