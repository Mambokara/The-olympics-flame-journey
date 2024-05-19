/*
** EPITECH PROJECT, 2024
** display_pause_menu
** File description:
** display the pause menu
*/
#include "../../include/structs.h"
#include "../../include/functions.h"

void display_pause_menu(flame_t *flame)
{
    if (flame->status == MAIN_MENU)
        return;
    over_pause_text(flame);
    if (flame->pause_menu->is_displayed == 1) {
        sfRenderWindow_drawText(WINDOW, flame->pause_menu->resume, NULL);
        sfRenderWindow_drawText(WINDOW, flame->pause_menu->main_menu, NULL);
        sfRenderWindow_drawText(WINDOW, flame->pause_menu->quit, NULL);
    }
}
