/*
** EPITECH PROJECT, 2024
** The olympics Flame Journey
** File description:
** Moves for the game
*/

#include "../include/structs.h"
#include "../include/functions.h"

int move_player(player_t *player, int side)
{
    if (side == LEFT) {
        sfSprite_move(player->runner, (sfVector2f){MOVE_SPEED, 0});
        player->pos = sfSprite_getPosition(player->runner);
    } else {
        sfSprite_move(player->runner, (sfVector2f){-MOVE_SPEED, 0});
        player->pos = sfSprite_getPosition(player->runner);
    }
    return 0;
}
