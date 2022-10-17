/*
** EPITECH PROJECT, 2020
** get_big_nbr.c
** File description:
** Xavier DAVID & Damien ANTONIOU
*/

#include <stdlib.h>
#include "my_lib.h"

static int get_result(char const *str, char *result, int loc, int count)
{
    for (int i = 0 ; i < count ; i++) {
        result[i] = str[loc + i];
    }
    return (my_getnbr(result));
}

int give_nbr(char const *str, int loc, int side)
{
    char *result;
    int int_result;
    int count = 0;

    if (side != 1) {
        for (int i = (loc - 1) ; str[i] < 58 && str[i] > 47 ; i--)
            count++;
    } else if (side == 1) {
        for (int i = (loc + 1) ; str[i] < 58 && str[i] > 47 ; i++)
            count++;
    }
    result = malloc(sizeof(char) * (count + 1));
    if (side != 1) {
        int_result = get_result(str, result, loc - count, count);
    } else {
        int_result = get_result(str, result, (loc + 1), count);
    }
    free(result);
    return (int_result);
}
