/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main function
*/

#include "my_rpg.h"
#include <stdlib.h>

int my_rpg(void);

char *my_getenv(char **env, char *var)
{
    int i = 0;
    int x = 0;
    while (env[i] != NULL) {
        while (env[i][x] == var[x] &&
            env[i][x] != '\0' && var[x] != '\0') {
            x += 1;
        }
        if (env[i][x] == '\0')
            return (NULL);
        if (x == my_strlen(var) && env[i][x] == 61)
            return (&env[i][x+1]);
        x = 0;
        i += 1;
    }
    return (NULL);
}

int main(int argc, char **argv, char **env)
{
    if (env == NULL || my_getenv(env, "DISPLAY") == NULL)
        return (84);
    my_rpg();
}
