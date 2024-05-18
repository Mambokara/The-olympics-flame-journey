/*
** EPITECH PROJECT, 2024
** structs.h
** File description:
** All structs for the project
*/

#pragma once
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Types.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdbool.h>
    #define MOVE_SPEED 7
    #define WINDOW flame->game_win
    #define SETTINGS flame->settings
    #define PLAYER flame->player
    #define POURCENT_MAP map->size

typedef struct player_s {
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
} menu_t;

typedef struct flame_s {
    player_t *player;
    sfRenderWindow *game_win;
    settings_t *settings;
    menu_t *menu;
    sfSprite *back;
} flame_t;
