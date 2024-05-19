/*
** EPITECH PROJECT, 2024
** The olympics Flame Journey
** File description:
** Moves for the game
*/

#include "../include/structs.h"
#include "../include/functions.h"
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Types.h>

int check_color_red(sfVector2f po, sfFloatRect re, flame_t *fla)
{
    sfColor colo = sfImage_getPixel(fla->undermap, (po.x), (po.y + re.height));
    sfColor colo2 = sfImage_getPixel(fla->undermap, (po.x + re.width),
        (po.y + re.height));

    if ((colo.r == 255 && colo.g == 0 && colo.b == 0) ||
        (colo2.r == 255 && colo2.g == 0 && colo2.b == 0)) {
        return 1;
    }
    if ((colo.r == 0 && colo.g == 0 && colo.b == 255) ||
        (colo2.r == 0 && colo2.g == 0 && colo2.b == 255)) {
        sfSprite_setPosition(fla->player->runner, (sfVector2f){100, 1000});
        return 1;
    }
    return 0;
}

void jump_player(flame_t *fla, float deltaTime, sfVector2f *velocity,
    int jump_height)
{
    sfVector2f po = sfSprite_getPosition(fla->player->runner);
    const sfFloatRect re = sfSprite_getGlobalBounds(fla->player->runner);
    static float pos = 0;
    static int up = 0;

    if (fla->player->is_jumping == 1) {
        if (up != 1) {
            velocity->y -= 700 * deltaTime;
            pos -= 700 * deltaTime;
            up = (pos <= jump_height) ? 1 : 0;
        } else
            velocity->y += 700 * deltaTime;
        po.y += velocity->y;
        if (check_color_red(po, re, fla) == 1) {
            up = 0;
            pos = 0;
            fla->player->is_jumping = 0;
            velocity->y = 0;
        }
    }
    sfSprite_move(fla->player->runner, (sfVector2f){0, velocity->y});
    sfText_move(fla->fps, (sfVector2f){0, velocity->y});
    move_pause_menu(fla, (sfVector2f){0, velocity->y});
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
    if (((color.r == 0 && color.g == 0 && color.b == 255) ||
        (color2.r == 0 && color2.g == 0 && color2.b == 255))){
        sfSprite_setPosition(flame->player->runner, (sfVector2f){100, 1000});
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
        (color2.r == 255 && color2.g == 0 && color2.b == 0))){
        return 1;
    }
    if (((color.r == 0 && color.g == 0 && color.b == 255) ||
        (color2.r == 0 && color2.g == 0 && color2.b == 255))){
        sfSprite_setPosition(flame->player->runner, (sfVector2f){100, 1000});
        return 1;
    }
    return 0;
}

int move_player(flame_t *flame, int side)
{
    if (side == LEFT) {
        sfSprite_setTexture(flame->player->runner, flame->player->left_tex, sfFalse);
        if (check_coll_left(flame) == 1)
            return 0;
        sfSprite_move(flame->player->runner, (sfVector2f){-MOVE_SPEED, 0});
        move_pause_menu(flame, (sfVector2f){-MOVE_SPEED, 0});
        sfText_move(flame->fps, (sfVector2f){-MOVE_SPEED, 0});
        flame->player->pos = sfSprite_getPosition(flame->player->runner);
        sfView_setCenter(flame->view, flame->player->pos);
    } else {
        sfSprite_setTexture(flame->player->runner, flame->player->right_tex, sfFalse);
        if (check_coll_right(flame) == 1)
            return 0;
        sfSprite_move(flame->player->runner, (sfVector2f){MOVE_SPEED, 0});
        move_pause_menu(flame, (sfVector2f){MOVE_SPEED, 0});
        sfText_move(flame->fps, (sfVector2f){MOVE_SPEED, 0});
        flame->player->pos = sfSprite_getPosition(flame->player->runner);
        sfView_setCenter(flame->view, flame->player->pos);
    }
    return 0;
}
