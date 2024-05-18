/*
** EPITECH PROJECT, 2024
** Jamalakitou
** File description:
** button_over
*/

#include "../../include/functions.h"
#include "../../include/structs.h"

void over_text(flame_t *flame)
{
    sfFloatRect bound = sfText_getGlobalBounds(flame->menu->credit);
    sfVector2i mouse = sfMouse_getPosition(WINDOW);
}