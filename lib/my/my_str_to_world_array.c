/*
** EPITECH PROJECT, 2021
** lib
** File description:
** my str to word array
*/

#include "my_lib.h"
#include <stdlib.h>

int my_count_words(const char *str)
{
    size_t size = 1;

    for (size_t i = 0; str[i] != '\0'; i++)
        if (str[i] == ' ')
            size++;
    return size;
}

char **my_str_to_word_array(const char *str)
{
    char **array = NULL;
    size_t len = my_strlen(str);
    size_t index = 0;
    size_t j;
    size_t size = my_count_words(str);

    array = malloc(sizeof(char *) * size + 1);
    if (array == NULL)
        return NULL;
    for (size_t i = 0; str[i] != '\0'; i++) {
        array[index] = malloc(sizeof(char) * len + 1);
        for (j = 0; str[i] != ' ' && str[i] != '\0'; j++) {
            array[index][j] = str[i];
            i++;
        }
        array[index][j] = '\0';
        index++;
    }
    array[index] = NULL;
    return array;
}