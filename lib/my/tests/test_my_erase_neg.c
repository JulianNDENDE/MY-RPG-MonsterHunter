/*
** EPITECH PROJECT, 2020
** test erase neg
** File description:
** tests
*/

#include <criterion/criterion.h>

void my_erase_neg(char *str);

Test(test_1, my_erase_neg)
{
    char *rt = "654";

    my_erase_neg(rt);
    cr_assert_str_eq(rt, "654");
}

Test(test_2, my_erase_neg)
{
    char rt[] = "-42";

    my_erase_neg(rt);
    cr_assert_str_eq(rt, "42");
}
