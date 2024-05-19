/*
** EPITECH PROJECT, 2024
** Jamalakitou
** File description:
** menu_pressed
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

void is_menu_pressed(flame_t *flame)
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
        flame->menu->condio = 1;
        sfText_setOutlineThickness(flame->menu->option, 10);
    } else {
        if (!is_overrect(flame->menu->opt->back, mouse))
            flame->menu->condio = 0;
        sfText_setOutlineThickness(flame->menu->option, 5);
    }
    if (is_over(flame->menu->play, mouse)) {
        sfText_setOutlineThickness(flame->menu->play, 10);
        flame->status = LEVEL_SELECTION;
    } else
        sfText_setOutlineThickness(flame->menu->play, 5);
    if (is_over(flame->menu->quit, mouse) && flame->menu->condic == 0) {
        flame->menu->condiq = 1;
        sfText_setOutlineThickness(flame->menu->quit, 10);
    } else
        sfText_setOutlineThickness(flame->menu->quit, 5);
}

void is_option_pressed(flame_t *flame)
{
    sfVector2f mouse = get_universal_mouse_position(flame); 

    if (is_over(flame->menu->opt->fps30, mouse)) {
        flame->frame = 30;
        sfText_setOutlineThickness(flame->menu->opt->fps30, 10);
    } else {
        sfText_setOutlineThickness(flame->menu->opt->fps30, 5);
    }
    if (is_over(flame->menu->opt->fps60, mouse)) {
        flame->frame = 60;
        sfText_setOutlineThickness(flame->menu->opt->fps60, 10);
    } else {
        sfText_setOutlineThickness(flame->menu->opt->fps60, 5);
    }
    if (is_over(flame->menu->opt->fps90, mouse)) {
        flame->frame = 90;
        sfText_setOutlineThickness(flame->menu->opt->fps90, 10);
    } else {
        sfText_setOutlineThickness(flame->menu->opt->fps90, 5);
    }
}

void menu_pressed(flame_t *flame)
{
    printf("%d\n", flame->frame);
    is_menu_pressed(flame);
    if (flame->menu->condio == 1)
        is_option_pressed(flame);
}
