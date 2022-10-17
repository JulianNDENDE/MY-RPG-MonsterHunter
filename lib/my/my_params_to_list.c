/*
** EPITECH PROJECT, 2020
** my params to list
** File description:
** put params in a list
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_lib.h"

void add_nod(list_l **head, void *av)
{
    list_l *node = malloc(sizeof(list_l));

    if (*head == NULL) {
        node->data = av;
        node->next = NULL;
        (*head) = node;
        return;
    }
    node->data = av;
    node->next = (*head);
    (*head) = node;
    return;
}

list_l *my_params_to_list(int ac, char * const *av)
{
    list_l *head = 0;
    int i = 0;

    while (i < ac) {
        add_nod(&head, av[i]);
        i++;
    }
    return (head);
}

void delete_node(list_l **head, int index)
{
    list_l *actual = *head;
    list_l *to_link = *head;

    if (!(*head))
        return;
    if (index == 0) {
        *head = (*head)->next;
        return;
    }
    to_link = to_link->next;
    if (to_link != NULL)
        to_link = to_link->next;
    while (index > 1 && to_link != NULL) {
        to_link = to_link->next;
        actual = actual->next;
        index--;
    }
    actual->next = to_link;
    return;
}