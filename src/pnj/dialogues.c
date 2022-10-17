/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** dialogues
*/

#include "my_rpg.h"

static char *test0[] = {
    "Test 0",
    "Ta mere:",
    "Bonjour,",
    "Vous allez bien ?",
    NULL
};

static char *test1[] = {
    "Test 1",
    "Ta mere:",
    "Bonjour,",
    "Vous allez toujours bien ?",
    NULL
};

static char *test2[] = {
    "Oui",
    "Ta mere:",
    "Cool",
    NULL
};

static char *test3[] = {
    "Non",
    "Ta mere:",
    "Oh mince",
    NULL
};

static char *test4[] = {
    "balec",
    "Le paume du vilage:",
    "Je ne sais pas ce que je fais la",
    NULL
};

void init_cringe_guys(main_t *main)
{
    dialogue_t *choices[] = {
        create_dialogue(test2, NULL, main->assets.font, 1),
        create_dialogue(test3, NULL, main->assets.font, 2),
        NULL
    };
    dialogue_t *dial1 = create_dialogue(test1, choices, main->assets.font, 1);
    dialogue_t *dial0 = create_dialogue(test0, choices, main->assets.font, 1);
    dialogue_t *dial2 = create_dialogue(test4, NULL, main->assets.font, 1);

    MAP.lvl[1][0].pnj = malloc(sizeof(pnj_t) * 3);
    MAP.lvl[1][0].pnj[0] = create_pnj(create_sprite(V2F(0, 0), \
                V2F(192, 256), main->assets.pnj2), \
                V2F(12, 5), (dialogue_t *[]) {dial0, dial1}, main->config);
    MAP.lvl[1][0].pnj[1] = create_pnj(create_sprite(V2F(0, 0), \
                V2F(192, 256), main->assets.pnj3), \
                V2F(7, 7), (dialogue_t *[]) {dial2, NULL}, main->config);
    MAP.lvl[1][0].pnj[2] = NULL;
    sfSprite_setTextureRect(MAP.lvl[1][0].pnj[0]->sprite, R2I(32, 64, 32, 32));
    sfSprite_setTextureRect(MAP.lvl[1][0].pnj[1]->sprite, R2I(32, 0, 32, 32));
}

static void display_all(sfRenderWindow *window, main_t *main, \
                        dialogue_t *dialogue, sfRectangleShape *shape)
{
    sfRenderWindow_clear(window, sfBlack);
    display_all_game(window, main);
    sfRenderWindow_drawRectangleShape(window, shape, NULL);
    sfRenderWindow_drawText(window, dialogue->char_name, NULL);
    for (int i = 0; dialogue->txt[i]; i++)
        sfRenderWindow_drawText(window, dialogue->txt[i], NULL);
    if (dialogue->choice != NULL)
        for (int i = 0; dialogue->choice[i]; i++)
            sfRenderWindow_drawText(window, \
                    dialogue->choice[i]->dial_name, NULL);
    sfRenderWindow_display(window);
}

dialogue_t *set_up_dialogue(dialogue_t *dial, dialogue_t **choices)
{
    int len = 0;

    if (choices == NULL) {
        dial->choice = NULL;
        return dial;
    }
    for (len = 0; choices[len] != NULL; len++);
    dial->choice = malloc(sizeof(dialogue_t) * (len + 1));
    for (int i = 0; i < len; i++) {
        sfText_setPosition(choices[i]->dial_name, V2F(150, 670 + i * 30));
        dial->choice[i] = choices[i];
    }
    dial->choice[len] = NULL;
    return dial;
}

dialogue_t *create_dialogue(char **txt, dialogue_t **choices, \
                            sfFont *font, int rt_value)
{
    dialogue_t *dial = malloc(sizeof(dialogue_t));
    int len = 0;

    for (len = 0; txt[len] != NULL; len++);
    if (len < 3)
        return NULL;
    dial->dial_name = create_text(V2F(150, 700), txt[0], 30, font);
    dial->char_name = create_text(V2F(140, 500), txt[1], 28, font);
    sfText_setColor(dial->dial_name, sfWhite);
    sfText_setColor(dial->char_name, sfWhite);
    dial->txt = malloc(sizeof(sfText *) * (len + 1));
    for (int i = 0; i < len - 2; i++) {
        dial->txt[i] = create_text(V2F(150, 545 + i * 30), \
                                    txt[i + 2], 28, font);
        sfText_setColor(dial->txt[i], sfWhite);
    }
    dial->txt[len - 2] = NULL;
    dial->rt = rt_value;
    return set_up_dialogue(dial, choices);
}

int dialogue(sfRenderWindow *window, main_t *main, dialogue_t dialogue)
{
    sfVector2f mouse;
    sfFloatRect rect;
    sfRectangleShape *shape = create_rectangleshape(R2F(
                    130, 490, main->windowx - 260, main->windowy - 510
                    ), (sfColor) {0, 0, 0, 150});

    while (sfRenderWindow_isOpen(window) && \
            !sfKeyboard_isKeyPressed(sfKeyEscape) &&
            !sfMouse_isButtonPressed(sfMouseRight)) {
        is_having_to_close(window);
        mouse = VV2F(sfMouse_getPositionRenderWindow(window));
        for (int i = 0; dialogue.choice && dialogue.choice[i]; i++) {
            rect = sfText_getGlobalBounds(dialogue.choice[i]->dial_name);
            if (sfMouse_isButtonPressed(sfMouseLeft) && \
                sfFloatRect_contains(&rect, mouse.x, mouse.y))
                dialogue = *dialogue.choice[i];
        }
        display_all(window, main, &dialogue, shape);
    }
    sfRectangleShape_destroy(shape);
    return dialogue.rt;
}