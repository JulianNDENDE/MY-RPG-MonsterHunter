/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** all int flags
*/

#include <stdarg.h>
#include "my_lib.h"
#include <stddef.h>

int int_flags_long(char *fmt, int *i, va_list ap);

int int_flags_2(char *fmt, int i, size_t nbr)
{
    if (fmt[i] == 'o') {
        my_putstr(dec_to_oct(my_get_unsigned_str(nbr)));
        return (1);
    }
    if (fmt[i] == 'b') {
        my_putstr(dec_to_bin(my_get_unsigned_str(nbr)));
        return (1);
    }
    return (0);
}

int int_flags_1(char *fmt, int i, size_t nbr)
{
    if (fmt[i] == 'u') {
        my_put_unsigned_nbr(nbr);
        return (1);
    }
    if (fmt[i] == 'x') {
        my_putstr(dec_to_lowhex(my_get_unsigned_str(nbr)));
        return (1);
    }
    if (fmt[i] == 'X') {
        my_putstr(dec_to_uphex(my_get_unsigned_str(nbr)));
        return (1);
    }
    return (int_flags_2(fmt, i, nbr));
}

int p_flag(char *fmt, int *i, va_list ap)
{
    if (fmt[*i] == 'p') {
        my_putstr("0x");
        my_putstr(dec_to_lowhex(my_getstr(va_arg(ap, int))));
        return (1);
    }
    return (0);
}

int int_flags_long(char *fmt, int *i, va_list ap)
{
    if (fmt[*i] == 'l') {
        *i += 1;
        if (fmt[*i] == 'd' || fmt[*i] == 'i')
            return (my_put_nbr((long)va_arg(ap, int)) + 1);
        if (my_is_in_str(fmt[*i], "obuxX") == 1)
            return (int_flags_1(fmt, *i, va_arg(ap, unsigned long)));
    }
    if (fmt[*i] == 'd' || fmt[*i] == 'i')
        return (my_put_nbr(va_arg(ap, int)) + 1);
    if (my_is_in_str(fmt[*i], "obuxX") == 1)
        return (int_flags_1(fmt, *i, va_arg(ap, unsigned int)));
    return (0);
}

int int_flags(char *fmt, int *i, va_list ap)
{
    if (fmt[*i] == 'h') {
        *i += 1;
        if (fmt[*i] == 'h') {
            *i += 1;
            if (fmt[*i] == 'd' || fmt[*i] == 'i')
                return (my_put_nbr((char)va_arg(ap, int)) + 1);
            if (my_is_in_str(fmt[*i], "obuxX") == 1)
                return (int_flags_1(fmt, *i,
                        (unsigned char)va_arg(ap, unsigned int)));
        }
        if (fmt[*i] == 'd' || fmt[*i] == 'i')
            return (my_put_nbr((short)va_arg(ap, int)) + 1);
        if (my_is_in_str(fmt[*i], "obuxX") == 1)
            return (int_flags_1(fmt, *i,
                        (unsigned short)va_arg(ap, unsigned int)));
    }
    return (int_flags_long(fmt, i, ap));
}