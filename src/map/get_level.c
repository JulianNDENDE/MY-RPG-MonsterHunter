/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** get_level
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include "map.h"
#include "enemy.h"

char ****get_maps(void)
{
    char ****maps = malloc(sizeof(char ***) * 15);
    DIR *dir = opendir("assets/maps");
    struct dirent *folder = NULL;

    if (dir == NULL)
        return (NULL);
    for (size_t i = 0; i < 15; i++)
        maps[i] = malloc(sizeof(char **) * 4);
    while ((folder = readdir(dir)) != NULL) {
        if (folder != NULL && my_strlen(folder->d_name) == 2 && \
            folder->d_name[0] >= 'a' && folder->d_name[0] <= 'o' && \
            folder->d_name[1] >= '1' && folder->d_name[1] <= '4')
            maps[folder->d_name[0] - 97][folder->d_name[1] - 49] = \
                parse_map(open_map(my_strcat("assets/maps/", folder->d_name)));
    }
    if (closedir(dir) == -1)
        return (NULL);
    return maps;
}

map_type get_map_type(char **maze, int x, int y)
{
    sfBool type[4] = {sfFalse, sfFalse, sfFalse, sfFalse};

    if (y - 1 >= 0 && maze[y - 1][x] == 'X')
        type[0] = sfTrue;
    if (maze[y][x + 1] == 'X')
        type[2] = sfTrue;
    if (maze[y + 1] && maze[y + 1][x] == 'X')
        type[1] = sfTrue;
    if (x - 1 >= 0 && maze[y][x - 1] == 'X')
        type[3] = sfTrue;
    map_type test = get_type(type);
    return test;
}

void free_lvl(map_s *map, int width, int height)
{
    FOR_FOR(width, height) {
        if (map->maze[y][x] == 'X') {
            for (int i = 0; map->lvl[y][x].enemy[i] != NULL; i++) {
                if (map->lvl[y][x].enemy[i]->sprite != NULL)
                    sfSprite_destroy(map->lvl[y][x].enemy[i]->sprite);
                free(map->lvl[y][x].enemy[i]);
            }
            for (int i = 0; map->lvl[y][x].map[i] != NULL; i++)
                free(map->lvl[y][x].map[i]);
            free(map->lvl[y][x].map);
        }
    }
}

map_t **get_lvl(char **maze, int lvl_type, main_t *main)
{
    char ****maps = get_maps();
    map_t **lvl = malloc(sizeof(map_t *) * 11);

    for (int y = 0; maze[y]; y++) {
        lvl[y] = malloc(sizeof(map_t) * 11);
        for (int x = 0; maze[y][x]; x++) {
            lvl[y][x].map = NULL;
            lvl[y][x].passed = 0;
            lvl[y][x].lvl = lvl_type;
            lvl[y][x].print_tp = 0;
            if (maze[y][x] == 'X') {
                lvl[y][x].map = maps[get_map_type(maze, x, y)][RDM(0, 2)];
                lvl[y][x].enemy = get_enemies(lvl[y][x].map, main);
                lvl[y][x].pnj = NULL;
            }
        }
    }
    return (lvl);
}