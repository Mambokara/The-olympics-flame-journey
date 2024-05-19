/*
** EPITECH PROJECT, 2024
** Jam
** File description:
** init_level_selector
*/

#include "../../include/structs.h"
#include "../../include/functions.h"
#include "../../include/macros.h"
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>

w_map_t *init_level_selector(void)
{
    w_map_t *world = malloc(sizeof(w_map_t));

    world->map =sfSprite_create();
    sfSprite_setTexture(world->map, sfTexture_createFromFile(WMAP, NULL),
        sfFalse);
    return world;
}
