/*
** EPITECH PROJECT, 2020
** erase neg
** File description:
** remove '-' from a char * nbr
*/

void my_swap(char *a, char *b);

int my_strlen(char const *str);

void my_erase_neg(char *str)
{
    int len = my_strlen(str);

    while (str[0] == '-') {
        str[0] = '\0';
        for (int b = 0; b < len - 1; b++)
            my_swap(&str[b], &str[b + 1]);
    }
}
