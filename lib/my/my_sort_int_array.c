/*
** EPITECH PROJECT, 2020
** my sort in array
** File description:
** sort the content of the array
*/

int my_swap(int *a, int *b);

int swapandtest(int *array, int a)
{
    int rt = 0;

    if (array[a] > array[a + 1])
        rt = my_swap(&array[a], &array[a + 1]);
    return (rt);
}

void my_sort_int_array(int *array, int  size)
{
    int test = 1;

    while (test != 0) {
        test = 0;
        for (int a = 0; a < size - 1; a++)
            test = test + swapandtest(array, a);
    }
}
