/*
** EPITECH PROJECT, 2020
** test isnum
** File description:
** tests
*/

#include <criterion/criterion.h>

int my_char_isnum(char);

Test(test_1, my_is_sup)
{
    int rt = 0;

    rt = my_char_isnum('0');
    cr_assert_eq(rt, 1);
}

Test(test_2, my_is_sup)
{
    int	rt = 0;

    rt = my_char_isnum('_');
    cr_assert_eq(rt, 0);
}

Test(test_3, my_is_sup)
{
    int	rt = 0;

    rt = my_char_isnum('9');
    cr_assert_eq(rt, 1);
}
