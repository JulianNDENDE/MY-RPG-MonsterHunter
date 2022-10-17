/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** hud
*/

#ifndef HUD_H_
#define HUD_H_

#include "my_csfml.h"
#include "structure.h"

typedef enum in_game_sprite
{
    life_bar,
    life_sprite
} in_game_sprite;

typedef enum in_game_text
{
    life_txt
} in_game_text;

void init_settings(main_t *main);
void init_boss_hud(main_t *main);
void display_all_game(sfRenderWindow *window, main_t *main);
void init_ingame_hud(main_t *main);
void update_live_bar(display_t *game, int life, int life_max);
void update_stamina_bar(display_t *game, int stamina, int stamina_max);
void init_pause(main_t *main);
int pause_game(main_t *main);
minimap_t *init_minimap(int width, int height, main_t *main);
void print_minimap(minimap_t *map, sfRenderWindow *window, config_t config);
void update_minimap(minimap_t *map, int move_x, int move_y);
void reload_minimap(minimap_t *map, int width, int height);
void loading_screen(display_t *loading, float percent, \
                    sfRenderWindow *window, config_t config);
void init_loading_scene(main_t *main);
void settings(main_t *all, sfRenderWindow *window);
void display_waiting_screen(sfRenderWindow *window, main_t *main, \
                            void (*to_load[])(main_t *));
void get_menu_display(main_t *main);
void free_game_hud(main_t *main);
void update_boss_bar(main_t *main, int life, int life_max);
list_l *set_inventory(main_t *main);
void doku_mitenda(main_t *main);
void niconiconiiii(main_t *main);

#endif /* !HUD_H_ */
