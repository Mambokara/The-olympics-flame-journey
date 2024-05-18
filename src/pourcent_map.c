/*
** EPITECH PROJECT, 2024
** The-olympics-flame-journey
** File description:
** pourcent_map
*/
#include "../../include/structs.h"

int get_pourcent_map(player_t *player, map_t *map)
{
    int return_value = player->pos.x / POURCENT_MAP * 100;

    return return_value;
}