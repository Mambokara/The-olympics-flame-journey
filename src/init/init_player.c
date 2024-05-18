/*
** EPITECH PROJECT, 2024
** Jam
** File description:
** init_player
*/

#include "../../include/structs.h"

player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));
    sfVector2f position = {960, 540};

    player->is_jumping = false;
    player->is_reversed = false;
    player->pos = position;
    player->runner = NULL;
    player->run_tex = NULL;
    return player;
}
