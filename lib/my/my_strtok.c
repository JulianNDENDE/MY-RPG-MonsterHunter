/*
** EPITECH PROJECT, 2021
** lib
** File description:
** my_strtok
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_lib.h"

char *my_strtok(char **str, char delim)
{
    size_t len = 0;
    char *tok = NULL;

    if ((*str)[0] == '\0') {
        *str = NULL;
        return NULL;
    }
    for (len = 0; (*str)[len] != delim && (*str)[len] != '\0'; len++);
    tok = malloc(sizeof(char) * (len + 2));
    for (len = 0; **str != delim && **str != '\0'; len++) {
        tok[len] = **str;
        (*str)++;
    }
    tok[len] = **str;
    if (**str != '\0')
        (*str)++;
    tok[len + 1] = '\0';
    return tok;
}