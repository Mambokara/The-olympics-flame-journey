/*
** EPITECH PROJECT, 2024
** Jamalakitou
** File description:
** display_option
*/

#include "../../include/functions.h"
#include "../../include/structs.h"

void display_option(flame_t *flame)
{
    sfRenderWindow_drawRectangleShape(WINDOW, flame->menu->opt->back, NULL);
    sfRenderWindow_drawText(WINDOW, flame->menu->opt->fps, NULL);
    sfRenderWindow_drawText(WINDOW, flame->menu->opt->fps30, NULL);
    sfRenderWindow_drawText(WINDOW, flame->menu->opt->fps60, NULL);
    sfRenderWindow_drawText(WINDOW, flame->menu->opt->fps90, NULL);
}