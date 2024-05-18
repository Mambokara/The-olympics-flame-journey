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
    #include "structs.h"

/* Game loop functions */

void game_loop(flame_t *flame);

/* Init functions */

flame_t *init_flame(void);
menu_t *init_menu(void);
settings_t *init_settings(void);
player_t *init_player(void);
void display_menu(flame_t *flame);
sfText *create_text(char *str, sfFont *font, sfVector2f position,
    unsigned int Size);
sfSprite *create_sprite(sfVector2f pos, char *file, sfVector2f scale);
sfRectangleShape *create_rectangle(sfVector2f size, sfVector2f pos,
    sfColor outline, sfColor fill);

