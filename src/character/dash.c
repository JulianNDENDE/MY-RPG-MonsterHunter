/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** dash
*/

#include <stdlib.h>
#include "my_rpg.h"

static void real_dash(main_t *main)
{
    if (sfKeyboard_isKeyPressed(main->config.keys.dash) && \
            (CHARACT.move.x != 0 || CHARACT.move.y != 0) && \
            CHARACT.stamina >= 15 && \
            get_Milliseconds(CHARACT.dashclock, main->clock_error) > 1000) {
        CHARACT.stamina = CHARACT.stamina - 15;
        sfClock_restart(CHARACT.dashclock);
        CHARACT.dashing = 1;
        CHARACT.previous = 0;
        CHARACT.invicibility_time = sfMilliseconds(200);
        sfClock_restart(CHARACT.clock);
        CHARACT.dashingmove = V2F(
            CHARACT.move.x * 30,
            CHARACT.move.y * 30);
    }
}

void dash(main_t *main)
{
    if (CHARACT.stamina < CHARACT.maxstamina && \
            get_Milliseconds(CHARACT.dashclock, main->clock_error) > \
            CHARACT.previous + 500) {
        CHARACT.stamina = CHARACT.stamina + 1;
        CHARACT.previous = get_Milliseconds(
                            CHARACT.dashclock, main->clock_error);
    }
    if (CHARACT.dashing == 1) {
        if (get_Milliseconds(CHARACT.dashclock, main->clock_error) < 200 && \
            check_colide(main, CHARACT.dashingmove) != 1) {
            realy_moov(main, CHARACT.dashingmove, &CAM, main->config);
        } else
            CHARACT.dashing = 0;
        return;
    }
    real_dash(main);
}

int check_pos(main_t *main)
{
    if (MAP.map[CHARACT_Y + 2] == NULL)
        return (84);
    if (MAP.map[CHARACT_Y][CHARACT_X + 2] == 0)
        return (84);
    if (CHARACT.pos.y <= 0 || CHARACT.pos.x <= 0)
        return (84);
    return (0);
}