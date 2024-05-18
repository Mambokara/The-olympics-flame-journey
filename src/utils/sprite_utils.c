/*
** EPITECH PROJECT, 2024
** myrpg
** File description:
** sprite
*/

#include "../../include/functions.h"
#include "../../include/structs.h"

sfSprite *create_sprite(sfVector2f pos, char *file, sfVector2f scale)
{
    sfTexture *texture = sfTexture_createFromFile(file, NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2u coord = sfTexture_getSize(texture);

    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}
