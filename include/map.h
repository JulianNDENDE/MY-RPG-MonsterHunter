/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_

#include "my_csfml.h"
#include "structure.h"

typedef enum
{
    UP,
    DOWN,
    RIGHT,
    LEFT,
    UP_DOWN,
    RIGHT_LEFT,
    UP_LEFT,
    UP_RIGHT,
    DOWN_LEFT,
    DOWN_RIGHT,
    UP_DOWN_RIGHT,
    UP_RIGHT_LEFT,
    UP_DOWN_LEFT,
    DOWN_RIGHT_LEFT,
    UP_DOWN_RIGHT_LEFT
} map_type;

char *open_map(char *path);
char **parse_map(char *map);
map_t **get_lvl(char **maze, int lvl_type, main_t *main);
char ****get_maps(void);
char **make_maze(int size, int len);
map_type get_type(const sfBool type[4]);
void print_pnj_front(int y, main_t *main, sfVector2i pos);
void print_pnj_behind(int y, main_t *main, sfVector2i pos);
void free_maps(main_t *main);
map_t **get_hub(void);
void boss_map(main_t *main);
map_t **get_boss_1(main_t *main);
map_t **get_boss_2(main_t *main);
map_t **get_boss_3(main_t *main);
void go_to_boss(main_t *main);
void go_to_next_lvl(main_t *main);
void print_elem(main_t *main, int floor, sfVector2i pos, sfVector2i square);
void score_manager(main_t *main, display_t *display);

#endif /* !MAP_H_ */