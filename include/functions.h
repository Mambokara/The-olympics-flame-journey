/*
** EPITECH PROJECT, 2024
** functions.h
** File description:
** All functions for the project
*/


#pragma once
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Types.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdbool.h>

#include "./structs.h"

// INIT FUNCTIONS

static sfTexture *get_texture(char *str);
static sfSprite *setup_sprite(sfTexture *texture, sfVector2f pos);
static player_t *init_player(void);
static sfView *init_view(player_t *player);
flame_t *init_flame(void);

// MOVE FUNCTIONS

int move_player(flame_t *flame, int side);
void check_gravity(flame_t *flame);
