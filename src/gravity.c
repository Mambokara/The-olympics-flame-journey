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
    const sfFloatRect rect = sfSprite_getGlobalBounds(flame->player->runner);

    if (flame->player->is_jumping == 1) {
        return;
    }
    center_view = sfView_getCenter(flame->view);
    color = sfImage_getPixel(flame->undermap, center_view.x,
                    center_view.y + rect.height);
    if (color.r == 255 && color.g == 0 && color.b == 0 &&
        sfFloatRect_contains(&rect, center_view.x, center_view.y) == sfTrue){
        flame->player->is_jumping = 0;
        return;
    }
    sfSprite_move(flame->player->runner, (sfVector2f){0, 1});
    sfView_move(flame->view, (sfVector2f){0, 1});
}
