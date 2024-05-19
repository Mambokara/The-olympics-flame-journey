/*
** EPITECH PROJECT, 2024
** display_background
** File description:
** dispaly the background
*/
#include "../include/structs.h"

void display_background(flame_t *flame)
{
    sfVector2f center = sfView_getCenter(VIEW);
    level_t *level = flame->levels[flame->current_level];

    sfSprite_setPosition(level->background,
        (sfVector2f) {center.x - 1980.0f / 2, center.y - 1080.0f / 2});
    sfRenderWindow_drawSprite(flame->game_win, level->background, NULL);
    return;
}
