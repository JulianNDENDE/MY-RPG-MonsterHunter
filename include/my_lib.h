/*
** EPITECH PROJECT, 2020
** my fonctions
** File description:
** list of prototypes
*/

#ifndef MY_H
#define MY_H

#include <stddef.h>

void my_putchar(char c);
int my_strlen(char const *str);
int my_arraylen(char **array);
int my_power(int nb, int p);
char *my_evil_str(char *str);
int my_putstr(char const *str);
void my_swap(char *a, char *b);
char *my_getstr(int nbr);
char *my_get_unsigned_str(unsigned int nbr);
void my_sort_int_array(int *array, int size);
int my_isneg(int n);
long my_getnbr(char const *str);
int my_getlen(int a);
char *my_strdup(char const *src);
char **my_arraydup(char **array);
int my_get_unsigned_len(unsigned int a);
int my_put_nbr(unsigned int nb);
int my_put_unsigned_nbr(unsigned int nb);
int my_char_isnum(char const c);
int my_char_isprintable(char const c);
void my_wait(int time);
char *convert_base(char const *, char const *, char const *);
char *my_strcpy(char *dest, char const *src);
char *convert_base(char const *nbr, char const *base_from, char const *base_to);
char *dec_to_uphex(char const *nbr);
char *dec_to_lowhex(char const *nbr);
char *dec_to_oct(char const *nbr);
char *dec_to_bin(char const *nbr);
int count_x(char *);
int count_y(char *);
void my_printf(char *fmt, ...);
int my_showstr(char const *str);
int give_nbr(char const *str, int loc, int side);
int get_nbr_len(int a);
char *my_strcat(char *dest , char  const *src);
int my_is_in_str(const char c, const char *str);
char **my_str_to_word_array(const char *str);
int my_str_is_identical(const char *str_1, const char *str_2);
char *my_strtok(char **str, char delim);
char *open_file(char const *filepath);

typedef struct linked_list
{
    void *data;
    struct linked_list *next;
} list_l;

void add_nod(list_l **head, void *av);
void delete_node(list_l **head, int index);

#endif