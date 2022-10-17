/*
** EPITECH PROJECT, 2020
** my show str
** File description:
** show a str or his hexadecimal
*/

#include "my_lib.h"
#include <unistd.h>

static int formating(unsigned char c)
{
    char res[4] = "000";
    char *oct = 0;
    int i = 0;
    int j = 2;

    oct = convert_base(my_getstr(c), "0123456789", "01234567");
    i = my_strlen(oct) - 1;
    while (i >= 0) {
        res[j] = oct[i];
        i--;
        j--;
    }
    write(1, "\\", 1);
    write(1, &res, 3);
    return (0);
}

int my_showstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (my_char_isprintable(str[i]) == 0)
            formating(str[i]);
        else
            write(1, &str[i], 1);
        i++;
    }
    return (0);
}