/*
** EPITECH PROJECT, 2024
** Jamalakitou
** File description:
** button_over
*/

#include "../../include/functions.h"
#include "../../include/structs.h"

static sfBool is_over(sfText *text, sfVector2f mouse)
{
    const sfFloatRect frect = sfText_getGlobalBounds(text);

    return (sfFloatRect_contains(&frect, mouse.x, mouse.y));
}

static sfBool is_overrect(sfRectangleShape *rect, sfVector2f mouse)
{
    const sfFloatRect frect = sfRectangleShape_getGlobalBounds(rect);

    return (sfFloatRect_contains(&frect, mouse.x, mouse.y));
}


void is_pressed(flame_t *flame)
{
    sfVector2f mouse = get_universal_mouse_position(flame);

    if (is_over(flame->menu->credit, mouse)) {
        flame->menu->condic = 1;
        sfText_setOutlineThickness(flame->menu->credit, 10);
    } else {
        if (!is_overrect(flame->menu->back, mouse))
            flame->menu->condic = 0;
        sfText_setOutlineThickness(flame->menu->credit, 5);
    }
    if (is_over(flame->menu->option, mouse)) {
        sfText_setOutlineThickness(flame->menu->option, 10);
    } else
        sfText_setOutlineThickness(flame->menu->option, 5);
    if (is_over(flame->menu->play, mouse)) {
        sfText_setOutlineThickness(flame->menu->play, 10);
    } else
        sfText_setOutlineThickness(flame->menu->play, 5);
    if (is_over(flame->menu->quit, mouse) && flame->menu->condic == 0) {
        flame->menu->condiq = 1;
        sfText_setOutlineThickness(flame->menu->quit, 10);
    } else
        sfText_setOutlineThickness(flame->menu->quit, 5);
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

void over_text(flame_t *flame)
{
    sfVector2f mouse = get_universal_mouse_position(flame); 

    if (is_over(flame->menu->credit, mouse))
        change_color(flame->menu->credit, true);
    else
        change_color(flame->menu->credit, false);
    if (is_over(flame->menu->option, mouse))
        change_color(flame->menu->option, true);
    else
        change_color(flame->menu->option, false);
    if (is_over(flame->menu->play, mouse))
        change_color(flame->menu->play, true);
    else
        change_color(flame->menu->play, false);
    if (is_over(flame->menu->quit, mouse))
        change_color(flame->menu->quit, true);
    else
        change_color(flame->menu->quit, false);
}
