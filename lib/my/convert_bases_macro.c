/*
** EPITECH PROJECT, 2020
** convert bases macros
** File description:
** set macro for convert bases
*/

char *convert_base(char const *nbr, char const *base_from, char const *base_to);

char *dec_to_uphex(char const *nbr)
{
    return (convert_base(nbr, "0123456789", "0123456789ABCDEF"));
}

char *dec_to_lowhex(char const *nbr)
{
    return (convert_base(nbr, "0123456789", "0123456789abcdef"));
}

char *dec_to_oct(char const *nbr)
{
    return (convert_base(nbr, "0123456789", "01234567"));
}

char *dec_to_bin(char const *nbr)
{
    return (convert_base(nbr, "0123456789", "01"));
}