/*
** EPITECH PROJECT, 2024
** animate_flame
** File description:
** animate the flame
*/
#include "../include/structs.h"

void animate_flame(flame_t *flame)
{
    float seconds;
    sfTime time;
    player_t* player = flame->player;
    static int offset = 0;

    time = sfClock_getElapsedTime(player->anim_clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.15) {
        player->rect.top = 0;
        player->rect.left = offset * 50;
        player->rect.width = 50;
        player->rect.height = 50;
        sfClock_restart(player->anim_clock);
        offset += 1;
        if (offset == 7)
            offset = 0;
        sfSprite_setTextureRect(player->runner, player->rect);
    }
}