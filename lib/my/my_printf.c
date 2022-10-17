/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdio.h>
#include "my_lib.h"
#include <unistd.h>
#include "my_printf.h"

static int set_pading_start(char *fmt, int *i)
{
    int x = 0;

    x = give_nbr(fmt, *i, 1);
    *i += 1;
    for (; fmt[*i] == '\''; *i += 1);
    if (fmt[*i] == ' ') {
        my_putchar(' ');
        for (; fmt[*i] == ' '; *i += 1);
        for (; fmt[*i] == '\''; *i += 1);
        x = give_nbr(fmt, *i - 1, 1);
    }
    if (x > 2) {
        *i += my_getlen(x);
        while (x > 2) {
            my_putchar(' ');
            x--;
        }
    }
    return (0);
}

static int set_pading_end(char *fmt, int *i, int x)
{
    if (fmt[*i] == '-') {
        x = give_nbr(fmt, *i, 1);
        *i += 1;
        if (x > 3)
            *i += my_getlen(x);
        return (x);
    }
    for (;x > 2; x--) {
        my_putchar(' ');
    }
    return (x);
}

int char_flags(char *fmt, int *i, va_list ap)
{
    if (fmt[*i] == 's') {
        my_putstr(va_arg(ap, char *));
        return (1);
    }
    if (fmt[*i] == 'c') {
        my_putchar((char)va_arg(ap, int));
        return (1);
    }
    if (fmt[*i] == 'S') {
        my_showstr(va_arg(ap, char *));
        return (1);
    }
    if (fmt[*i] == '%') {
        my_putchar('%');
        return (1);
    }
    return (0);
}

void my_printf(char *fmt, ...)
{
    va_list ap;
    int x = 0;
    int i_var = 0;
    int a = 0;
    int (*f[3])(char *, int *, va_list) = {*char_flags, *p_flag, *int_flags};

    va_start(ap, fmt);
    for (int *i = &i_var; fmt[*i] != '\0'; i_var++) {
        if (fmt[*i] == '%') {
            set_pading_start(fmt, i);
            x = set_pading_end(fmt, i, x);
            for (int j = 0; j < 3; j++)
                a += f[j](fmt, i, ap);
            x = set_pading_end(fmt, i, x);
            if (a == 0)
                my_putchar('%');
        } else
            my_putchar(fmt[*i]);
    }
    va_end(ap);
}