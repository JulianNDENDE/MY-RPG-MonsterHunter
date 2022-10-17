/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** my_strcat
*/

#include <stdlib.h>

int my_strlen(char const *);

char *my_strcat(char const *dest, char const *src)
{
    int i = 0;
    char *cat = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

    if (cat == NULL)
        return NULL;
    for (size_t j = 0; dest[j] != '\0'; j++) {
        cat[i] = dest[j];
        i++;
    }
    for (size_t j = 0; src[j] != '\0'; j++) {
        cat[i] = src[j];
        i++;
    }
    cat[i] = '\0';
    return (cat);
}