/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main function
*/

#include "my_rpg.h"
#include <stdlib.h>
#include <unistd.h>

int count_rooms(char **map, char type)
{
    int count = 0;
    for (int y = 0; map[y] != NULL; y++) {
        for (int x = 0; map[y][x] != '\0'; x++) {
            count = (map[y][x] == type) ? count + 1 : count;
        }
    }
    return (count);
}

int is_inside(sfVector2i pos, int size)
{
    if (pos.x < 0 || pos.x >= size || pos.y < 0 || pos.y >= size)
        return (0);
    return (1);
}

int create_path(sfVector2i pos, char **maze, int len, int size)
{
    sfVector2i moves[4] = {(sfVector2i){pos.x - 1, pos.y},
        (sfVector2i){pos.x + 1, pos.y}, (sfVector2i){pos.x, pos.y - 1},
        (sfVector2i){pos.x, pos.y + 1}};
    int nb = rand() % 4;

    while (is_inside(moves[nb], size) == 0)
        nb = rand() % 4;
    maze[moves[nb].y][moves[nb].x] = 'X';
    if (count_rooms(maze, 'X') < len)
        create_path(moves[nb], maze, len, size);
    return (0);
}

char **make_maze(int size, int len)
{
    if (size <= 2)
        size = 4;
    if (len <= 2)
        len = 3;
    char **maze = malloc(sizeof(char *) * (size + 1));
    for (int y = 0; y < size; y++) {
        maze[y] = malloc(sizeof(char) * (size + 1));
        for (int x = 0; x < size; x++)
            maze[y][x] = '.';
        maze[y][size] = '\0';
    }
    maze[size] = NULL;
    maze[size/2][size/2] = 'X';
    create_path((sfVector2i){size/2, size/2}, maze, len, size);
    for (int y = 0; maze[y] != NULL; y++) {
        write(2, maze[y], 10);
        write(2, "\n", 1);
    }
    return (maze);
}