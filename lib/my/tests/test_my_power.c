/*
** EPITECH PROJECT, 2020
** test power
** File description:
** tests
*/

#include <criterion/criterion.h>

int my_power(int, int);

Test(test_2, my_power)
{
    int rt = 0;

    rt = my_power(-65, 3);
    cr_assert_eq(rt, -274625);
}

Test(test_3, my_power)
{
    int rt = 0;

    rt = my_power(65, 4);
    cr_assert_eq(rt, 17850625);
}

Test(test_4, my_power)
{
    int rt = 0;

    rt = my_power(65, 0);
    cr_assert_eq(rt, 1);
}

Test(test_5, my_power)
{
    int rt = 0;

    rt = my_power(65, -35);
    cr_assert_eq(rt, 0);
}

Test(test_6, my_power)
{
    int rt = 0;

    rt = my_power(1, 56786);
    cr_assert_eq(rt, 1);
}
