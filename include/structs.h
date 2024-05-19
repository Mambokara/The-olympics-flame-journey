/*
** EPITECH PROJECT, 2024
** structs.h
** File description:
** All structs for the project
*/

#pragma once
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdbool.h>
    #include "macros.h"

enum game_status {
    MAIN_MENU = 0,
    IN_GAME,
    PAUSE_MENU,
    LEVEL_SELECTION,
    CREDIT,
    SETTING,
    QUIT
};

enum press {
    L = 0,
    R,
    DOWN,
    UP,
    NONE
};

typedef struct world_point_s {
    struct world_point_s *up;
    struct world_point_s *down;
    struct world_point_s *right;
    struct world_point_s *left;
    int locked;
    int id;
    sfVector2f position;
    sfSprite *lock;
} world_point_t;

typedef struct w_map_s {
    sfSprite *map;
    world_point_t *start;
    world_point_t **stock;
    sfSprite *lock;
    enum press button;
} w_map_t;

typedef struct player_s {
    sfIntRect rect;
    int can_move;
    sfSprite *runner;
    sfTexture *left_tex;
    sfTexture *right_tex;
    bool is_reversed;
    sfVector2f pos;
    sfVector2f respawn;
    bool is_jumping;
    sfClock *anim_clock;
} player_t;

typedef struct portal_pos_s {
    sfVector2f pos;
    sfVector2f pos_tp;
    sfRectangleShape *rect;
    int is_teleportor;
    int id;
} portal_pos_t;

typedef struct portal_s {
    portal_pos_t **portal_pos;
    int nbr_portal;
} portal_t;

typedef struct settings_s {
    unsigned int mvolume;
    unsigned int svolume;
    sfVector2u resolution;
    unsigned int framerate;
    sfBool is_fullscreen;
} settings_t;

typedef struct map_s {
    int size;
} map_t;

typedef struct option_s {
    sfRectangleShape *back;
    sfText *fps;
    sfText *fps30;
    sfText *fps60;
    sfText *fps90;
    sfText *music;
    sfSprite *more;
    sfSprite *less;
    sfText *fullscreen;
    sfSprite *check;
    sfRectangleShape *square;
    int is_check;
    sfText *res;
    sfText *res1;
    sfText *res2;
    sfText *res3;
    int res_window;
    sfText *save;
    sfRectangleShape *s_quare;
} option_t;

typedef struct menu_s {
    option_t *opt;
    sfText *quit;
    sfText *option;
    sfText *play;
    sfText *credit;
    sfText *txtcredit;
    sfText *lucas;
    sfRectangleShape *back;
} menu_t;

typedef struct pause_menu_s {
    int is_displayed;
    sfText *quit;
    sfText *resume;
    sfText *main_menu;
} pause_menu_t;

typedef struct level_s {
    sfSprite *ground;
    sfSprite *background;
    sfImage *undermap;
    sfVector2f checkpoint;
    portal_t *portal;
} level_t;

typedef struct sound_s {
    sfText *text;
    float sound;
    sfMusic* music;
} sound_t;

typedef struct succes_s {

} succes_t;

typedef struct particle_s {
    sfVector2f pos;
    sfVector2f vel;
    sfColor color;
    float life;
} particle_t;

typedef struct particles_s {
    particle_t part[MAX_PARTICLES];
    int count;
    int is_part;
} particles_t;

typedef struct flame_s {
    enum game_status status;
    enum game_status buffer;
    particles_t *parts;
    sfSprite *checkpoint;
    int current_level;
    level_t **levels;
    succes_t *scs;
    sound_t *sound;
    w_map_t *world;
    player_t *player;
    sfView *view;
    sfRenderWindow *game_win;
    settings_t *settings;
    menu_t *menu;
    pause_menu_t *pause_menu;
    sfSprite *back;
    int frame;
    sfClock *clock;
    sfText *fps;
    int screen;
} flame_t;
