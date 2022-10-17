/*
** EPITECH PROJECT, 2020
** my put str
** File description:
** reverse the string
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_evil_str(char *str)
{
    int len = my_strlen(str);
    int i = 0;
    int j = len - 1;
    char *rts = malloc(len + 1);

    for (int a = 0; a < len; a++)
        rts[a] = str[a];
    rts[len] = '\0';
    while (i < len) {
        str[i] = rts[j];
        i++;
        j--;
    }
    free(rts);
    str[i] = '\0';
    return (str);
}
