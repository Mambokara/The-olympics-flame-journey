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
    #define LEFT 0
    #define RIGHT 1
    #define WINDOW flame->game_win

typedef struct player_s {
    sfSprite *runner;
    sfTexture *run_tex;
    bool is_reversed;
    sfVector2f pos;
    bool is_jumping;
} player_t;

typedef struct flame_s {
    player_t *player;
    sfRenderWindow *game_win;
} flame_t;

void game_loop(flame_t *flame);
