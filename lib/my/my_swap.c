/*
** EPITECH PROJECT, 2020
** my_swap
** File description:
** swap the two int
*/

void my_swap(char *a, char *b)
{
    char c = *a;

    *a = *b;
    *b = c;
}
