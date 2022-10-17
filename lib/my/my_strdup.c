/*
** EPITECH PROJECT, 2020
** my str dup
** File description:
** alloc memory for a str
*/

#include <stdlib.h>

int my_strlen(const char *str);

int my_arraylen(char **array);

char *my_strdup(char const *src)
{
    char *dest;
    int len = my_strlen(src);
    int i = 0;

    dest = malloc(sizeof(char) * (len + 1));
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char **my_arraydup(char **array)
{
    char **dup = malloc(sizeof(char *) * (my_arraylen(array) + 2));
    size_t i;

    if (dup == NULL)
        return NULL;
    for (i = 0; array[i] != NULL; i++) {
        dup[i] = my_strdup(array[i]);
    }
    dup[i] = NULL;
    return dup;
}