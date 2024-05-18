/*
** EPITECH PROJECT, 2024
** The olympics Flame Journey
** File description:
** Moves for the game
*/

#include "../include/structs.h"
#include "../include/functions.h"
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/View.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>

void jump_player(flame_t *fla, float deltaTime, sfVector2f *velocity,
    int jump_height)
{
    sfVector2f po = sfSprite_getPosition(fla->player->runner);
    const sfFloatRect re = sfSprite_getGlobalBounds(fla->player->runner);
    sfColor colo;    static float pos = 0;
    static int up = 0;

    if (fla->player->is_jumping == 1) {
        if (up != 1) {
            velocity->y -= 700 * deltaTime;
            pos -= 700 * deltaTime;
            up = (pos <= jump_height) ? 1 : 0;
        } else
            velocity->y += 700 * deltaTime;
        po.y += velocity->y;
        colo = sfImage_getPixel(fla->undermap, (po.x), (po.y + re.height));
        if (colo.r == 255 && colo.g == 0 && colo.b == 0) {
            up = 0;
            pos = 0;
            fla->player->is_jumping = 0;
            velocity->y = 0;
        }
    }
    sfSprite_move(fla->player->runner, (sfVector2f){0, velocity->y});
    sfView_setCenter(fla->view, sfSprite_getPosition(fla->player->runner));
}

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
        move_pause_menu(flame, (sfVector2f){-MOVE_SPEED, 0});
        flame->player->pos = sfSprite_getPosition(flame->player->runner);
        sfView_setCenter(flame->view, flame->player->pos);
    } else {
        if (check_coll_right(flame) == 1)
            return 0;
        sfSprite_move(flame->player->runner, (sfVector2f){MOVE_SPEED, 0});
        move_pause_menu(flame, (sfVector2f){MOVE_SPEED, 0});
        flame->player->pos = sfSprite_getPosition(flame->player->runner);
        sfView_setCenter(flame->view, flame->player->pos);
    }
    return 0;
}
