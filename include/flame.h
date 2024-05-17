/*
** EPITECH PROJECT, 2024
** flame.h
** File description:
** All protos, include and struct for the project
*/

#pragma once
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Types.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdbool.h>
    #define MOVE_SPEED 7

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
} flame_t ;
