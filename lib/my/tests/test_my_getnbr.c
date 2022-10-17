/*
** EPITECH PROJECT, 2020
** test getnbr
** File description:
** unit test
*/

#include <criterion/criterion.h>

int my_getnbr(char *);

Test(test_1, my_getnbr)
{
    int rt = 0;

    rt = my_getnbr("6");
    cr_assert_eq(rt, 6);
}

Test(test_3, my_getnbr)
{
    int rt = 0;

    rt = my_getnbr("-8637");
    cr_assert_eq(rt, -8637);
}

Test(test_4, my_getnbr)
{
    int rt = 0;

    rt = my_getnbr("-0");
    cr_assert_eq(rt, 0);
}

Test(test_5, my_getnbr)
{
    int rt = 0;

    rt = my_getnbr("");
    cr_assert_eq(rt, 0);
}

Test(test_6, my_getnbr)
{
    int rt = 0;

    rt = my_getnbr("9856746745949746975");
    cr_assert_eq(rt, 0);
}
