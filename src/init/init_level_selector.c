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

static world_point_t *four_p(w_map_t *world)
{
    world_point_t *four = malloc(sizeof(world_point_t));

    four->lock = sfSprite_copy(world->lock);
    sfSprite_setPosition(four->lock, (sfVector2f){600, 800});
    four->up = NULL;
    four->left = NULL;
    four->id = 4;
    four->right = NULL;
    four->down = NULL;
    four->locked = 1;
    four->position.x = 1375;
    four->position.y = 228;
    return four;
}

static world_point_t *five_p(w_map_t *world)
{
    world_point_t *five = malloc(sizeof(world_point_t));

    five->lock = sfSprite_copy(world->lock);
    sfSprite_setPosition(five->lock, (sfVector2f){600, 800});
    five->up = NULL;
    five->left = NULL;
    five->id = 5;
    five->right = NULL;
    five->down = NULL;
    five->locked = 1;
    five->position.x = 970;
    five->position.y = 35;
    return five;
}

static world_point_t *six_p(w_map_t *world)
{
    world_point_t *six = malloc(sizeof(world_point_t));

    six->lock = sfSprite_copy(world->lock);
    sfSprite_setPosition(six->lock, (sfVector2f){600, 800});
    six->up = NULL;
    six->left = NULL;
    six->id = 6;
    six->right = NULL;
    six->down = NULL;
    six->locked = 1;
    six->position.x = 665;
    six->position.y = 720;
    return six;
}


static world_point_t *seven_p(w_map_t *world)
{
    world_point_t *seven = malloc(sizeof(world_point_t));

    seven->lock = sfSprite_copy(world->lock);
    sfSprite_setPosition(seven->lock, (sfVector2f){600, 800});
    seven->up = NULL;
    seven->left = NULL;
    seven->id = 7;
    seven->right = NULL;
    seven->down = NULL;
    seven->locked = 1;
    seven->position.x = 565;
    seven->position.y = 430;
    return seven;
}

static world_point_t *eight_p(w_map_t *world)
{
    world_point_t *eight = malloc(sizeof(world_point_t));

    eight->lock = sfSprite_copy(world->lock);
    sfSprite_setPosition(eight->lock, (sfVector2f){600, 800});
    eight->up = NULL;
    eight->left = NULL;
    eight->id = 8;
    eight->right = NULL;
    eight->down = NULL;
    eight->locked = 1;
    eight->position.x = 965;
    eight->position.y = 300;
    return eight;
}
static void init_links(world_point_t **stock)
{
    stock[0]->left = stock[1];
    stock[0]->up = stock[1];
    stock[1]->right = stock[0];
    stock[1]->up = stock[2];
    stock[1]->left = stock[5];
    stock[2]->down = stock[1];
    stock[2]->up = stock[4];
    stock[2]->right = stock[3];
    stock[2]->left = stock[7];
    stock[3]->down = stock[2];
    stock[3]->up = stock[4];
    stock[3]->left = stock[7];
    stock[4]->right = stock[3];
    stock[4]->down = stock[2];
    stock[4]->left = stock[7];
    stock[5]->right = stock[1];
    stock[5]->up = stock[6];
    stock[6]->down = stock[5];
    stock[6]->right = stock[7];
    stock[6]->up = stock[7];
    stock[7]->right = stock[3];
    stock[7]->up = stock[4];
    stock[7]->down = stock[2];
    stock[7]->left = stock[6];
}

world_point_t **init_points(w_map_t *world)
{
    world_point_t **stock = malloc(sizeof(world_point_t *) * 9);

    stock[0] = one_p(world);
    stock[1] = two_p(world);
    stock[2] = three_p(world);
    stock[3] = four_p(world);
    stock[4] = five_p(world);
    stock[5] = six_p(world);
    stock[6] = seven_p(world);
    stock[7] = eight_p(world);
    stock[8] = NULL;

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
