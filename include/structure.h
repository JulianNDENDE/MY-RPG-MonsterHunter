/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-nicolas.lavigne
** File description:
** structures
*/

#ifndef STRUCTURES_H_
#define STRUCTURES_H_

#include "my_csfml.h"
#include "particle.h"

#define PROJ        main->proj
#define CAM         main->cam
#define MAP         main->map
#define CHARACT     main->character
#define SETTINGS    main->settings
#define CURENT_MAP  MAP.lvl[MAP.y][MAP.x]

typedef struct
{
    sfSprite *sprite;
    sfInt32 previous;
    sfInt32 now;
    sfInt32 time;
    int begin_sprite;
    int len;
} object_t;

typedef struct bonus
{
    char *name;
    int atk;
    void (*atk_anim)(particle_t *, list_l **particles);
    int tek;
    void (*tek_anim)(particle_t *, list_l **particles);
    float speed;
    int pv;
    int pv_max;
    int stamina;
    int max_stamina;
    sfSprite *sprite;
    sfVector2f *pos;
} bonus_t;

typedef struct character
{
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
    sfFloatRect hitbox;
    sfRectangleShape *visual_box;
    void *weapon_atk;
    void *weapon_tek;
    float speed;
    int pv;
    int pv_max;
    int coins;
    int stamina;
    int maxstamina;
    int dashing;
    sfVector2f move;
    sfVector2f dashingmove;
    sfClock *dashclock;
    int previous;
    bonus_t *bonus[30];
    sfTime invicibility_time;
    sfClock *clock;
} character_t;

typedef struct assets
{
    sfFont *font;
    sfTexture *bonus;
    sfTexture *button;
    sfTexture *bar;
    sfTexture *map;
    sfTexture *tree1;
    sfTexture *tree2;
    sfTexture *rock1;
    sfSprite *player;
    sfSprite *printed;
    sfTexture *menu_backgroud;
    sfTexture *loading_backgroud;
    sfTexture *inventory;
    sfTexture *pillar;
    sfTexture *mob;
    sfTexture *enemy;
    sfTexture *boss;
    sfTexture *pnj1;
    sfTexture *pnj2;
    sfTexture *pnj3;
    sfTexture *pnj4;
    sfMusic *menu_music;
    sfTexture *quest_complete;
    sfTexture *htp;
} assets_t;

typedef struct
{
    sfSprite *sprite;
    sfVector2f pos;
    sfFloatRect size;
    sfVector2f move;
    sfClock *clock;
    sfInt32 next;
    int isaboss;
    int loop;
    float speed;
    int pv;
    int pv_max;
    int coins;
    float atk_dmg;
} enemy_t;

typedef struct key
{
    sfKeyCode forward;
    sfKeyCode back;
    sfKeyCode left;
    sfKeyCode right;
    sfKeyCode interact;
    sfKeyCode dash;
} keybind_t;

typedef struct dialogue
{
    sfText *char_name;
    sfText *dial_name;
    sfText **txt;
    struct dialogue **choice;
    int rt;
} dialogue_t;

typedef struct pnj
{
    sfSprite *sprite;
    sfBool passed;
    sfVector2f pos;
    dialogue_t first_dialogue;
    dialogue_t second_dialogue;
} pnj_t;

typedef struct map
{
    char **map;
    sfBool passed;
    enemy_t **enemy;
    pnj_t **pnj;
    int lvl;
    int print_tp;
} map_t;

typedef struct map_struct
{
    char **maze;
    char **map;
    object_t **object;
    sfIntRect ***boxes;
    int floor;
    map_t **lvl;
    int x;
    int y;
    int room;
    sfIntRect *teleporters;
} map_s;

typedef struct particles_struct
{
    list_l *particles;
    list_l *wait_list;
} particle_s;

typedef struct cam_struct
{
    char **map;
    sfVector2i cam_pos;
    sfVector2f *target_pos;
    sfIntRect ***box;
    int is_fighting;
} info_move_t;

typedef struct minimap
{
    int x;
    int y;
    int width;
    int height;
    int count;
    sfRectangleShape ***minimap;
    sfRectangleShape *background;
} minimap_t;

typedef struct config
{
    int window_x;
    int window_y;
    int map_format;
    int player_base_speed;
    int player_base_atk;
    int player_base_tek;
    int player_base_health;
    int volume;
    int framerate;
    keybind_t keys;
    char *player_filename;
} config_t;

typedef struct main
{
    minimap_t *minimap;
    assets_t assets;
    display_t *menu;
    display_t *game;
    display_t *pause;
    display_t *loading_screen;
    display_t *settings;
    display_t *boss_hud;
    map_s map;
    info_move_t cam;
    character_t character;
    particle_s proj;
    sfClock *clock;
    sfClock *runclock;
    sfClock *global_clock;
    sfTime clock_error;
    sfRenderWindow *window;
    sfRectangleShape *test;
    int hub;
    bonus_t *bonus;
    config_t config;
} main_t;

void init_character(main_t *main);
void init_camera(main_t *main);
void init_map(main_t *main);
void rdm_map(main_t *main);

#endif /* !STRUCTURES_H_ */