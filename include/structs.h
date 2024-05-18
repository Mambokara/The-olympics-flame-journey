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
    LEVEL_SELECTION
};

typedef struct player_s {
    int can_move;
    sfSprite *runner;
    sfTexture *run_tex;
    bool is_reversed;
    sfVector2f pos;
    bool is_jumping;
} player_t;

typedef struct portal_pos_s {
    sfVector2f pos;
    sfVector2f pos_tp;
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
typedef struct menu_s {
    sfText *quit;
    sfText *option;
    sfText *play;
    sfText *credit;
    int condic;
    int condio;
    int condip;
    int condiq;
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
    sfMusic *music;
} level_t;

typedef struct flame_s {
    enum game_status status;
    sfImage *undermap;
    player_t *player;
    sfSprite *map;
    sfView *view;
    sfRenderWindow *game_win;
    settings_t *settings;
    menu_t *menu;
    pause_menu_t *pause_menu;
    sfSprite *back;
} flame_t;
