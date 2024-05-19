/*
** EPITECH PROJECT, 2024
** Jamalakitou
** File description:
** option_interaction
*/

#include "../../include/functions.h"
#include "../../include/structs.h"

static sfBool is_over(sfText *text, sfVector2f mouse)
{
    const sfFloatRect frect = sfText_getGlobalBounds(text);

    return (sfFloatRect_contains(&frect, mouse.x, mouse.y));
}

static sfBool is_oversp(sfSprite *text, sfVector2f mouse)
{
    const sfFloatRect frect = sfSprite_getGlobalBounds(text);

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

void button_fps(flame_t *flame, sfVector2f mouse)
{
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

void button_sound(flame_t *flame, sfVector2f mouse)
{
    if (is_oversp(flame->menu->opt->more, mouse))
        sfSprite_setScale(flame->menu->opt->more, (sfVector2f) {0.6, 0.6});
    else
        sfSprite_setScale(flame->menu->opt->more, (sfVector2f) {0.5, 0.5});
    if (is_oversp(flame->menu->opt->less, mouse))
        sfSprite_setScale(flame->menu->opt->less, (sfVector2f) {0.6, 0.6});
    else
        sfSprite_setScale(flame->menu->opt->less, (sfVector2f) {0.5, 0.5});
}

void button_resolution(flame_t *flame, sfVector2f mouse)
{
    if (is_over(flame->menu->opt->res1, mouse)) {
        change_color(flame->menu->opt->res1, true);
    } else {
        change_color(flame->menu->opt->res1, false);
    }
    if (is_over(flame->menu->opt->res2, mouse)) {
        change_color(flame->menu->opt->res2, true);
    } else {
        change_color(flame->menu->opt->res2, false);
    }
    if (is_over(flame->menu->opt->res3, mouse)) {
        change_color(flame->menu->opt->res3, true);
    } else {
        change_color(flame->menu->opt->res3, false);
    }
}

void button_fullscreen(flame_t *flame, sfVector2f mouse)
{
    if (is_overrect(flame->menu->opt->square, mouse))
        sfRectangleShape_setOutlineColor(flame->menu->opt->square, sfWhite);
    else
        sfRectangleShape_setOutlineColor(flame->menu->opt->square, sfBlack);
}

void button_option(flame_t *flame)
{
    sfVector2f mouse = get_universal_mouse_position(flame);

    button_fps(flame, mouse);
    button_sound(flame, mouse);
    button_fullscreen(flame, mouse);
    button_resolution(flame, mouse);
}