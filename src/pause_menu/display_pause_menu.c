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
    sfVector2f center;

    if (flame->status == MAIN_MENU)
        return;
    over_pause_text(flame);
    if (flame->pause_menu->is_displayed == 1) { 
        center = sfView_getCenter(VIEW);
        sfText_setPosition(flame->pause_menu->resume, (sfVector2f)
            {center.x - 500.0f / 2, center.y + 330.0f / 2});
        sfText_setPosition(flame->pause_menu->main_menu, (sfVector2f)
            {center.x - 600.0f / 2, center.y - 200.0f / 2});
        sfText_setPosition(flame->pause_menu->quit, (sfVector2f)
            {center.x - 450.0f / 2, center.y + 50.0f / 2});
        sfRenderWindow_drawText(WINDOW, flame->pause_menu->resume, NULL);
        sfRenderWindow_drawText(WINDOW, flame->pause_menu->main_menu, NULL);
        sfRenderWindow_drawText(WINDOW, flame->pause_menu->quit, NULL);
    }
}
