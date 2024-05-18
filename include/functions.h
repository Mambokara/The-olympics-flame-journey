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

/* Game loop functions */

void game_loop(flame_t *flame);

/* Init functions */

flame_t *init_flame(void);
settings_t *init_settings(void);
player_t *init_player(void);
