/*
** EPITECH PROJECT, 2024
** Jamalakitou
** File description:
** display_credits
*/

#include "../../include/functions.h"
#include "../../include/structs.h"

void display_credits(flame_t *flame)
{
    sfRenderWindow_drawRectangleShape(WINDOW, flame->menu->back, NULL);
    sfRenderWindow_drawText(WINDOW, flame->menu->txtcredit, NULL);
    sfRenderWindow_drawText(WINDOW, flame->menu->lucas, NULL);
}
