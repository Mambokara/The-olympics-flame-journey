/*
** EPITECH PROJECT, 2024
** gravity.h
** File description:
** file with the gravity functions
*/

#include "../include/structs.h"
#include "../include/functions.h"
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/View.h>
#include <SFML/System/Vector2.h>
#include <stdbool.h>

void check_gravity(flame_t *flame)
{
    sfVector2f center_view;
    sfColor color;
    sfColor color2;
    const sfFloatRect rect = sfSprite_getGlobalBounds(flame->player->runner);
    level_t *level = flame->levels[flame->current_level];

    if (flame->player->is_jumping == 1) {
        return;
    }
    center_view = sfView_getCenter(flame->view);
    color = sfImage_getPixel(level->undermap, center_view.x,
                    center_view.y + rect.height);
    color2 = sfImage_getPixel(level->undermap, center_view.x + rect.width,
                    center_view.y + rect.height);
    if (((color.r == 255 && color.g == 0 && color.b == 0) ||
        (color2.r == 255 && color2.g == 0 && color2.b == 0))){
        flame->player->is_jumping = 0;
        return;
    }
    if (((color.r == 0 && color.g == 0 && color.b == 255) ||
        (color2.r == 0 && color2.g == 0 && color2.b == 255))){
        sfSprite_setPosition(flame->player->runner, flame->player->respawn);
        return;
    }
    sfSprite_move(flame->player->runner, (sfVector2f){0, 1});
    sfText_move(flame->fps, (sfVector2f){0, 1});
    move_pause_menu(flame, (sfVector2f){0, 1});
    sfView_move(flame->view, (sfVector2f){0, 1});
}
