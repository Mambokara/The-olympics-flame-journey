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
    if (flame->status == MAIN_MENU)
        return;
    if (flame->status == CREDIT)
       display_credits(flame);
    if (flame->status == QUIT)
        closed_window(flame);
    if (flame->status == SETTING) {
        button_option(flame);
        display_option(flame);
    }
}
