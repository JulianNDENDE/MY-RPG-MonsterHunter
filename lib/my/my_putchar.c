/*
** EPITECH PROJECT, 2020
** my putchar
** File description:
** put a char
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
