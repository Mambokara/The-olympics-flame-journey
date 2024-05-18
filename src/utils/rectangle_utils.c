/*
** EPITECH PROJECT, 2024
** Jamalakitou
** File description:
** button_utils
*/

#include "../../include/functions.h"
#include "../../include/structs.h"

sfRectangleShape *create_rectangle(sfVector2f size, sfVector2f pos,
    sfColor outline, sfColor fill)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();

    sfRectangleShape_setSize(rectangle, size);
    sfRectangleShape_setPosition(rectangle, pos);
    sfRectangleShape_setFillColor(rectangle, fill);
    sfRectangleShape_setOutlineColor(rectangle, outline);
    sfRectangleShape_setOutlineThickness(rectangle, 5);
    return rectangle;
}
