/*
** EPITECH PROJECT, 2024
** The olympics Flame Journey
** File description:
** Moves for the game
*/

#include "../include/structs.h"
#include "../include/functions.h"
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/View.h>

int check_coll_left(flame_t *flame)
{
    sfVector2f center_view;
    sfColor color;
    sfColor color2;
    const sfFloatRect rect = sfSprite_getGlobalBounds(flame->player->runner);

    center_view = sfView_getCenter(flame->view);
    color = sfImage_getPixel(flame->undermap, center_view.x,
                    center_view.y + rect.height - 1);
    color2 = sfImage_getPixel(flame->undermap, center_view.x,
                    center_view.y);
    if (((color.r == 255 && color.g == 0 && color.b == 0) ||
        (color2.r == 255 && color.g == 0 && color.b == 0)) &&
        sfFloatRect_contains(&rect, center_view.x, center_view.y) == sfTrue){
        return 1;
    }
    return 0;
}

int check_coll_right(flame_t *flame)
{
    sfVector2f center_view;
    sfColor color;
    sfColor color2;
    const sfFloatRect rect = sfSprite_getGlobalBounds(flame->player->runner);

    center_view = sfView_getCenter(flame->view);
    color = sfImage_getPixel(flame->undermap, center_view.x + rect.width,
                    center_view.y + rect.height - 1);
    color2 = sfImage_getPixel(flame->undermap, center_view.x + rect.width,
                    center_view.y);
    if (((color.r == 255 && color.g == 0 && color.b == 0) ||
        (color2.r == 255 && color.g == 0 && color.b == 0)) &&
        sfFloatRect_contains(&rect, center_view.x, center_view.y) == sfTrue){
        return 1;
    }
    return 0;
}

int move_player(flame_t *flame, int side)
{
    if (side == LEFT) {
        if (check_coll_left(flame) == 1)
            return 0;
        sfSprite_move(flame->player->runner, (sfVector2f){-MOVE_SPEED, 0});
        flame->player->pos = sfSprite_getPosition(flame->player->runner);
        sfView_setCenter(flame->view, flame->player->pos);
    } else {
        if (check_coll_right(flame) == 1)
            return 0;
        sfSprite_move(flame->player->runner, (sfVector2f){MOVE_SPEED, 0});
        flame->player->pos = sfSprite_getPosition(flame->player->runner);
        sfView_setCenter(flame->view, flame->player->pos);
    }
    return 0;
}
