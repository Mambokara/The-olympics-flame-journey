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
    sfRenderWindow_drawRectangleShape(WINDOW, flame->menu->opt->square, NULL);
    sfRenderWindow_drawRectangleShape(WINDOW, flame->menu->opt->s_quare, NULL);
    sfRenderWindow_drawSprite(WINDOW, flame->menu->opt->less, NULL);
    sfRenderWindow_drawSprite(WINDOW, flame->menu->opt->more, NULL);
    sfRenderWindow_drawText(WINDOW, flame->menu->opt->fps, NULL);
    sfRenderWindow_drawText(WINDOW, flame->menu->opt->fps30, NULL);
    sfRenderWindow_drawText(WINDOW, flame->menu->opt->fps60, NULL);
    sfRenderWindow_drawText(WINDOW, flame->menu->opt->fps90, NULL);
    sfRenderWindow_drawText(WINDOW, flame->menu->opt->music, NULL);
    sfRenderWindow_drawText(WINDOW, flame->menu->opt->fullscreen, NULL);
    sfRenderWindow_drawText(WINDOW, flame->menu->opt->res, NULL);
    sfRenderWindow_drawText(WINDOW, flame->menu->opt->res1, NULL);
    sfRenderWindow_drawText(WINDOW, flame->menu->opt->res2, NULL);
    sfRenderWindow_drawText(WINDOW, flame->menu->opt->res3, NULL);
    sfRenderWindow_drawText(WINDOW, flame->menu->opt->save, NULL);
    if (flame->status != SETTING)
        return;
    if (flame->menu->opt->res_window == 1)
        resolution_window(flame, 10);
    if (flame->menu->opt->res_window == 2)
        resolution_window(flame, 11);
    if (flame->menu->opt->res_window == 3)
        resolution_window(flame, 12);
    if (flame->screen == 1)
        sfRenderWindow_drawSprite(flame->game_win, flame->menu->opt->check, NULL);
    if (flame->menu->opt->is_check == 1) {
        flame->menu->opt->is_check = 0;
        if (flame->screen % 2 != 0)
            full_screen(flame, 0);
        else
            full_screen(flame, 1);
    }
}
