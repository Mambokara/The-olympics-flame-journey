/*
** EPITECH PROJECT, 2024
** The olympics Flame Journey
** File description:
** Moves for the game
*/

#include "../include/structs.h"
#include "../include/functions.h"
#include <SFML/Config.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/View.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>

int check_color_red(sfVector2f po, sfFloatRect re, flame_t *fla)
{
    level_t *level = fla->levels[fla->current_level];
    sfColor colo = sfImage_getPixel(level->undermap, (po.x), (po.y + re.height));
    sfColor colo2 = sfImage_getPixel(level->undermap, (po.x + re.width),
        (po.y + re.height));

    if ((colo.r == 255 && colo.g == 0 && colo.b == 0) ||
        (colo2.r == 255 && colo2.g == 0 && colo2.b == 0)) {
        return 1;
    }
    if ((colo.r == 0 && colo.g == 0 && colo.b == 255) ||
        (colo2.r == 0 && colo2.g == 0 && colo2.b == 255)) {
        sfSprite_setPosition(fla->player->runner, fla->player->respawn);
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
    level_t *level = flame->levels[flame->current_level];

    center_view = sfView_getCenter(flame->view);
    color = sfImage_getPixel(level->undermap, center_view.x,
                    center_view.y + rect.height - 1);
    color2 = sfImage_getPixel(level->undermap, center_view.x,
                    center_view.y);
    if (((color.r == 255 && color.g == 0 && color.b == 0) ||
        (color2.r == 255 && color.g == 0 && color.b == 0)) &&
        sfFloatRect_contains(&rect, center_view.x, center_view.y) == sfTrue){
        return 1;
    }
    if (((color.r == 255 && color.g == 174 && color.b == 174) ||
        (color2.r == 255 && color2.g == 174 && color2.b == 174))){
        return 1;
    }
    if (((color.r == 0 && color.g == 0 && color.b == 255) ||
        (color2.r == 0 && color2.g == 0 && color2.b == 255))){
        sfSprite_setPosition(flame->player->runner, flame->player->respawn);
        return 1;
    }
    return 0;
}

int check_coll_right(flame_t *flame)
{
    sfVector2f center_view;
    sfColor color;
    sfColor color2;
    sfTexture *text;
    const sfFloatRect rect = sfSprite_getGlobalBounds(flame->player->runner);
    level_t *level = flame->levels[flame->current_level];

    center_view = sfView_getCenter(flame->view);
    color = sfImage_getPixel(level->undermap, center_view.x + rect.width,
                    center_view.y + rect.height - 1);
    color2 = sfImage_getPixel(level->undermap, center_view.x + rect.width,
                    center_view.y);
    if (((color.r == 255 && color.g == 0 && color.b == 0) ||
        (color2.r == 255 && color2.g == 0 && color2.b == 0))){
        return 1;
    }
    if (((color.r == 255 && color.g == 174 && color.b == 174) ||
        (color2.r == 255 && color2.g == 174 && color2.b == 174))){
        return 1;
    }
    if (((color.r == 0 && color.g == 0 && color.b == 255) ||
        (color2.r == 0 && color2.g == 0 && color2.b == 255))){
        sfSprite_setPosition(flame->player->runner, flame->player->respawn);
        return 1;
    }
    if (((color.r == 229 && color.g == 255 && color.b == 0) ||
        (color2.r == 229 && color2.g == 255 && color2.b == 0)) &&
        flame->player->respawn.x == 100 && flame->player->respawn.y == 1000){
        text = sfTexture_createFromFile("assets/torch_with.png", NULL);
        sfSprite_setTexture(flame->checkpoint, text, sfFalse);
        printf("%f, %f\n", center_view.x, center_view.y - 10);
        center_view.y =center_view.y - 10;
        flame->player->respawn = center_view;
    }
    if (((color.r == 0 && color.g == 255 && color.b == 0) ||
        (color2.r == 0 && color2.g == 255 && color2.b == 0))){
        flame->buffer = LEVEL_SELECTION;
        flame->status = LEVEL_SELECTION;
        flame->player->can_move = 0;
        sfSprite_setTexture(flame->checkpoint, flame->torch, sfFalse);
        flame->player->respawn = (sfVector2f){100, 1000};
        sfSprite_setPosition(flame->player->runner, (sfVector2f){960, 540});
        sfView_setCenter(VIEW, (sfVector2f){960, 540});
        flame->world->stock[flame->current_level + 1]->locked = 0;
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
