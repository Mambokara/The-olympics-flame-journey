/*
** EPITECH PROJECT, 2024
** The olympics Flame Journey
** File description:
** Moves for the game
*/

#include "../include/structs.h"
#include "../include/functions.h"
#include <SFML/Graphics/View.h>

int move_player(flame_t *flame, int side)
{
    if (side == LEFT) {
        sfSprite_move(flame->player->runner, (sfVector2f){-MOVE_SPEED, 0});
        flame->player->pos = sfSprite_getPosition(flame->player->runner);
        sfView_setCenter(flame->view, flame->player->pos);
    } else {
        sfSprite_move(flame->player->runner, (sfVector2f){MOVE_SPEED, 0});
        flame->player->pos = sfSprite_getPosition(flame->player->runner);
        sfView_setCenter(flame->view, flame->player->pos);
    }
    return 0;
}
