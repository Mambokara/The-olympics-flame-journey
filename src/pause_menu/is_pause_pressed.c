/*
** EPITECH PROJECT, 2024
** is_pause_pressed
** File description:
** check if a button of the pause menu is pressed
*/
#include "../../include/structs.h"
#include "../../include/functions.h"

static sfBool is_over(sfText *text, sfVector2f mouse)
{
    const sfFloatRect frect = sfText_getGlobalBounds(text);

    return (sfFloatRect_contains(&frect, mouse.x, mouse.y));
}

void is_pause_pressed(flame_t *flame)
{
    sfVector2f mouse = get_universal_mouse_position(flame);

    if (is_over(flame->pause_menu->quit, mouse)) {
        sfText_setOutlineThickness(flame->pause_menu->quit, 10);
    } else
        sfText_setOutlineThickness(flame->pause_menu->quit, 5);
    if (is_over(flame->pause_menu->main_menu, mouse)) {
        sfText_setOutlineThickness(flame->pause_menu->main_menu, 10);
    } else
        sfText_setOutlineThickness(flame->pause_menu->main_menu, 5);
    if (is_over(flame->pause_menu->resume, mouse)) {
        flame->status = flame->buffer;
        flame->pause_menu->is_displayed = 0;
    } else
        sfText_setOutlineThickness(flame->pause_menu->resume, 5);
}

static void change_color(sfText *text, bool condi)
{
    if (condi) {
        sfText_setFillColor(text, sfBlack);
        sfText_setOutlineColor(text, sfWhite);
    } else {
        sfText_setFillColor(text, sfWhite);
        sfText_setOutlineColor(text, sfBlack);
    }
}

void over_pause_text(flame_t *flame)
{
    sfVector2f mouse = get_universal_mouse_position(flame);

    if (is_over(flame->pause_menu->main_menu, mouse))
        change_color(flame->pause_menu->main_menu, true);
    else
        change_color(flame->pause_menu->main_menu, false);
    if (is_over(flame->pause_menu->quit, mouse))
        change_color(flame->pause_menu->quit, true);
    else
        change_color(flame->pause_menu->quit, false);
    if (is_over(flame->pause_menu->resume, mouse))
        change_color(flame->pause_menu->resume, true);
    else
        change_color(flame->pause_menu->resume, false);
}
