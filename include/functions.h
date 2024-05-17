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

// MOVE FUNCTIONS
int move_player(player_t *player, int side);
