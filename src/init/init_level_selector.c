/*
** EPITECH PROJECT, 2024
** Jam
** File description:
** init_level_selector
*/

#include "../../include/structs.h"
#include "../../include/functions.h"
#include "../../include/macros.h"
#include <SFML/Graphics/Sprite.h>

static world_point_t *one_p(w_map_t *world)
{
    world_point_t *one = malloc(sizeof(world_point_t));

    one->lock = sfSprite_copy(world->lock);
    one->up = NULL;
    one->left = NULL;
    one->right = NULL;
    one->down = NULL;
    one->id = 1;
    one->locked = 0;
    one->position.x = 1388;
    one->position.y = 890;
    return one;
}

static world_point_t *two_p(w_map_t *world)
{
    world_point_t *two = malloc(sizeof(world_point_t));

    two->lock = sfSprite_copy(world->lock);
    two->up = NULL;
    two->left = NULL;
    two->right = NULL;
    two->down = NULL;
    two->id = 2;
    two->locked = 0;
    two->position.x = 1240;
    two->position.y = 855;
    return two;
}

static world_point_t *three_p(w_map_t *world)
{
    world_point_t *three = malloc(sizeof(world_point_t));

    three->lock = sfSprite_copy(world->lock);
    sfSprite_setPosition(three->lock, (sfVector2f){600, 800});
    three->up = NULL;
    three->left = NULL;
    three->id = 3;
    three->right = NULL;
    three->down = NULL;
    three->locked = 1;
    three->position.x = 1220;
    three->position.y = 580;
    return three;
}

static world_point_t *six_p(w_map_t *world)
{
    world_point_t *six = malloc(sizeof(world_point_t));

    six->lock = sfSprite_copy(world->lock);
    sfSprite_setPosition(six->lock, (sfVector2f){600, 800});
    six->up = NULL;
    six->left = NULL;
    six->id = 3;
    six->right = NULL;
    six->down = NULL;
    six->locked = 1;
    six->position.x = 665;
    six->position.y = 720;
    return six;
}

static void init_links(world_point_t **stock)
{
    stock[0]->left = stock[1];
    stock[0]->up = stock[1];
    stock[1]->right = stock[0];
    stock[1]->up = stock[2];
    stock[2]->down = stock[1];
    stock[1]->left = stock[5];
    stock[5]->right = stock[1];
}

world_point_t **init_points(w_map_t *world)
{
    world_point_t **stock = malloc(sizeof(world_point_t *) * 9);

    stock[0] = one_p(world);
    stock[1] = two_p(world);
    stock[2] = three_p(world);
    //stock[3] = four_p(world);
    //stock[4] = five_p(world);
    stock[5] = six_p(world);
    //stock[6] = seven_p(world);
    //stock[7] = height_p(world);
    //stock[8] = NULL;

    init_links(stock);
    return stock;
}

w_map_t *init_level_selector(void)
{
    w_map_t *world = malloc(sizeof(w_map_t));

    world->map =sfSprite_create();
    sfSprite_setTexture(world->map, sfTexture_createFromFile(WMAP, NULL),
        sfFalse);
    world->lock = create_sprite((sfVector2f){0, 0}, LOCK, (sfVector2f){1, 1});
    world->stock = init_points(world);
    world->start = world->stock[0];
    return world;
}
