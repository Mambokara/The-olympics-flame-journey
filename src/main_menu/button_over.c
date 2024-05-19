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
