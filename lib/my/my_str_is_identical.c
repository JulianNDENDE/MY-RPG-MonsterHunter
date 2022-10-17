/*
** EPITECH PROJECT, 2021
** lib
** File description:
** str is identical
*/

#include "my_lib.h"

int my_str_is_identical(const char *str_1, const char *str_2)
{
    for (size_t i = 0; str_1[i] != '\0'; i++) {
        if (str_1[i] != str_2[i])
            return 0;
    }
    return 1;
}