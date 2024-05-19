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

<<<<<<< HEAD
=======
static sfBool is_oversp(sfSprite *text, sfVector2f mouse)
{
    const sfFloatRect frect = sfSprite_getGlobalBounds(text);

    return (sfFloatRect_contains(&frect, mouse.x, mouse.y));
}

>>>>>>> c8295f2 ([+] add fullscreen function and change fps function)
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

void is_option_pressed(flame_t *flame, sfVector2f mouse)
{
<<<<<<< HEAD
    sfVector2f mouse = get_universal_mouse_position(flame); 
=======
>>>>>>> c8295f2 ([+] add fullscreen function and change fps function)

    if (is_over(flame->menu->opt->fps30, mouse)) {
        sfRenderWindow_setFramerateLimit(WINDOW, 30);
        sfText_setOutlineThickness(flame->menu->opt->fps30, 10);
    } else {
        sfText_setOutlineThickness(flame->menu->opt->fps30, 5);
    }
    if (is_over(flame->menu->opt->fps60, mouse)) {
        sfRenderWindow_setFramerateLimit(WINDOW, 60);
        sfText_setOutlineThickness(flame->menu->opt->fps60, 10);
    } else {
        sfText_setOutlineThickness(flame->menu->opt->fps60, 5);
    }
    if (is_over(flame->menu->opt->fps90, mouse)) {
        sfRenderWindow_setFramerateLimit(WINDOW, 90);
        sfText_setOutlineThickness(flame->menu->opt->fps90, 10);
    } else {
        sfText_setOutlineThickness(flame->menu->opt->fps90, 5);
    }
}

void is_sound_pressed(flame_t *flame, sfVector2f mouse)
{
    if (is_oversp(flame->menu->opt->more, mouse)) {
        flame->sound->sound += 1;
        sfSprite_setColor(flame->menu->opt->more, sfGreen);
    } else
        sfSprite_setColor(flame->menu->opt->more, sfColor_fromRGB(255, 255, 255));
    if (is_oversp(flame->menu->opt->less, mouse)) {
        flame->sound->sound -= 1;
        sfSprite_setColor(flame->menu->opt->less, sfRed);
    } else
        sfSprite_setColor(flame->menu->opt->less, sfColor_fromRGB(255, 255, 255));
}

void is_fullscreen_pressed(flame_t *flame, sfVector2f mouse)
{
    if (is_overrect(flame->menu->opt->square, mouse))
        flame->menu->opt->is_check = 1;
}

void is_resolution_pressed(flame_t *flame, sfVector2f mouse)
{
    if (is_over(flame->menu->opt->res1, mouse)) {
        flame->menu->opt->res_window = 1;
        sfText_setOutlineThickness(flame->menu->opt->res1, 10);
    } else {
        sfText_setOutlineThickness(flame->menu->opt->res1, 5);
    }
    if (is_over(flame->menu->opt->res2, mouse)) {
        flame->menu->opt->res_window = 2;
        sfText_setOutlineThickness(flame->menu->opt->res2, 10);
    } else {
        sfText_setOutlineThickness(flame->menu->opt->res2, 5);
    }
    if (is_over(flame->menu->opt->res3, mouse)) {
        flame->menu->opt->res_window = 3;
        sfText_setOutlineThickness(flame->menu->opt->res3, 10);
    } else {
        sfText_setOutlineThickness(flame->menu->opt->res3, 5);
    }
}

void menu_pressed(flame_t *flame)
{
    sfVector2f mouse = get_universal_mouse_position(flame);
    printf("%d\n", flame->menu->opt->res_window);
    is_menu_pressed(flame);
    if (flame->menu->condio == 1) {
        is_option_pressed(flame, mouse);
        is_sound_pressed(flame, mouse);
        is_fullscreen_pressed(flame, mouse);
        is_resolution_pressed(flame, mouse);
    }
}
