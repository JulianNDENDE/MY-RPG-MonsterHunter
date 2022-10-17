/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** clock
*/

#include "my_csfml.h"
#include <stdlib.h>

sfTime clock_get_elapsed_time(sfClock *clock, sfTime error)
{
    sfTime rt = sfClock_getElapsedTime(clock);

    rt.microseconds -= error.microseconds;
    return rt;
}

void clock_restart(sfClock *clock, sfTime *error)
{
    sfClock_restart(clock);
    error->microseconds = 0;
}

void clock_skip_passed_time(sfClock *clock, sfTime *error)
{
    *error = sfClock_getElapsedTime(clock);
}