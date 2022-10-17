/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** score
*/

#include "my_rpg.h"

char *create_timer(long int time)
{
    char *msg = NULL;
    char *hour = NULL;
    char *min = NULL;
    char *sec = NULL;

    if (floor(floor(time / 60) / 60) < 10)
        hour = my_strcat("0", my_getstr(floor(floor(time / 60) / 60)));
    else
        hour = my_getstr(floor(floor(time / 60) / 60));
    if ((int)floor(time / 60) % 60 < 10)
        min = my_strcat("0", my_getstr((int)floor(time / 60) % 60));
    else
        min = my_getstr((int)floor(time / 60) % 60);
    if (time % 60 < 10)
        sec = my_strcat("0", my_getstr(time % 60));
    else
        sec = my_getstr(time % 60);
    msg = my_strcat(my_strcat(my_strcat(hour, " : "),
    my_strcat(min, " : ")), sec);
    return msg;
}

void score_manager(main_t *main, display_t *display)
{
    char *msg = NULL;
    long int time = get_Second(main->runclock, main->clock_error);

    display->texts[0] = sfText_create();
    msg = create_timer(time);
    sfText_setString(display->texts[0], msg);
    sfText_setFont(display->texts[0], main->assets.font);
    sfText_setCharacterSize(display->texts[0], 40);
    sfText_setPosition(display->texts[0],
    V2F(main->windowx * 0.42, main->windowy * 0.8));
}