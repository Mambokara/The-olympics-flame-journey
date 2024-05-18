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
    over_text(flame);
    sfRenderWindow_drawText(WINDOW, flame->menu->credit, NULL);
    sfRenderWindow_drawText(WINDOW, flame->menu->option, NULL);
    sfRenderWindow_drawText(WINDOW, flame->menu->play, NULL);
    sfRenderWindow_drawText(WINDOW, flame->menu->quit, NULL);
    if (flame->menu->condic == 1)
       display_credits(flame);
    if (flame->menu->condiq == 1)
        closed_window(flame);
    if (flame->menu->condio == 1) {
        button_option(flame);
        display_option(flame);
    }
}
