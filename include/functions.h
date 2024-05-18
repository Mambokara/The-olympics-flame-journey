/*
** EPITECH PROJECT, 2024
** functions.h
** File description:
** All functions for the project
*/


#pragma once
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Types.h>
    #include "structs.h"
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdbool.h>

// MOVE FUNCTIONS

int move_player(flame_t *flame, int side);
void check_gravity(flame_t *flame);

/* Game loop functions */

void game_loop(flame_t *flame);

/* Init functions */

/* MENU FUNCTIONS */

menu_t *init_menu(void);
void display_menu(flame_t *flame);

/* !MENU FUNCTION */

void closed_window(flame_t *flame);
void over_text(flame_t *flame);
void is_pressed(flame_t *flame);
settings_t *init_settings(void);
static player_t *init_player(void);
sfText *create_text(char *str, sfFont *font, sfVector2f position,
    unsigned int Size);
sfSprite *create_sprite(sfVector2f pos, char *file, sfVector2f scale);
sfSprite *create_sprite_portal(portal_t *portal, sfVector2f pos,
    char *file, sfVector2f scale);
sfRectangleShape *create_rectangle(sfVector2f size, sfVector2f pos,
    sfColor outline, sfColor fill);
static sfTexture *get_texture(char *str);
static sfSprite *setup_sprite(sfTexture *texture, sfVector2f pos);
static sfView *init_view(player_t *player);
void create_portal(portal_t *portal);
void link_portal(portal_t *portal, int src, int dest);
flame_t *init_flame(void);
