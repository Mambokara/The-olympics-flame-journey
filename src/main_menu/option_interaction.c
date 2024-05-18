/*
** EPITECH PROJECT, 2024
** Jamalakitou
** File description:
** option_interaction
*/

#include "../../include/functions.h"
#include "../../include/structs.h"

static sfBool is_over(sfText *text, sfVector2i mouse)
{
    const sfFloatRect frect = sfText_getGlobalBounds(text);

    return (sfFloatRect_contains(&frect, mouse.x, mouse.y));
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

void button_fps(flame_t *flame)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(WINDOW);

    if (is_over(flame->menu->opt->fps30, mouse)) {
        change_color(flame->menu->opt->fps30, true);
    } else {
        change_color(flame->menu->opt->fps30, false);
    }
    if (is_over(flame->menu->opt->fps60, mouse)) {
        change_color(flame->menu->opt->fps60, true);
    } else {
        change_color(flame->menu->opt->fps60, false);
    }
    if (is_over(flame->menu->opt->fps90, mouse)) {
        change_color(flame->menu->opt->fps90, true);
    } else {
        change_color(flame->menu->opt->fps90, false);
    }
}

void button_option(flame_t *flame)
{
    button_fps(flame);
}