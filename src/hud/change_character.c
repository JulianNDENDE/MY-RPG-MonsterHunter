/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** change_character
*/

#include <unistd.h>
#include <stdio.h>
#include "my_rpg.h"

void change_character(main_t *main)
{
    sfTexture *texture = NULL;
    sfText *txt = create_text(V2F(10, 100), "ecrivez le path de\n\
            la nouvelle texture\ndu charactere", 50, main->assets.font);
    char *path = NULL;
    size_t n = 0;

    sfRenderWindow_drawText(main->window, txt, NULL);
    sfRenderWindow_display(main->window);
    while (!texture) {
        write(2, "$> ", 3);
        if (getline(&path, &n, stdin) == -1)
            return;
        path[my_strlen(path) - 1] = '\0';
        texture = sfTexture_createFromFile(path, NULL);
    }
    main->config.player_filename = path;
    sfTexture_destroy(texture);
}