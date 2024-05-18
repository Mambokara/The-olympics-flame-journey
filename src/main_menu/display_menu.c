/*
** EPITECH PROJECT, 2024
** Jamalakitou
** File description:
** display_menu
*/

#include "../../include/functions.h"
#include "../../include/structs.h"

void display_menu(flame_t *flame)
{
    sfRenderWindow_drawText(WINDOW, flame->menu->credit, NULL);
    sfRenderWindow_drawText(WINDOW, flame->menu->option, NULL);
    sfRenderWindow_drawText(WINDOW, flame->menu->play, NULL);
    sfRenderWindow_drawText(WINDOW, flame->menu->quit, NULL);
}