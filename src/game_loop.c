/*
** EPITECH PROJECT, 2024
** Jam
** File description:
** game_loop
*/

#include "../include/functions.h"
#include "../include/structs.h"
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/View.h>
#include <SFML/System/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>
#include <stdio.h>
#include <time.h>

sfVector2f get_universal_mouse_position(flame_t*flame)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(WINDOW);
    sfView const *view = sfRenderWindow_getView(WINDOW);
    sfVector2u window_size = sfRenderWindow_getSize(WINDOW);

    return sfRenderWindow_mapPixelToCoords(WINDOW, mouse, view);
}

void close_detect(sfRenderWindow *window, sfEvent *event, flame_t *flame)
{
    if (flame->status != IN_GAME && flame->status != PAUSE_MENU)
        return;
    if (event->key.code == sfKeyEscape) {
        flame->pause_menu->is_displayed =
            (flame->pause_menu->is_displayed == 0) ? 1 : 0;
    }
}

static void update_resolution(flame_t *flame, sfEvent *event)
{
    sfVector2u size_new = sfRenderWindow_getSize(WINDOW);
    sfVector2f center = sfView_getCenter(VIEW);

    return;
    sfView_setCenter(VIEW, center);
    sfRenderWindow_setView(WINDOW, VIEW);
}

void analyse_events(flame_t *flame)
{
    sfEvent *event = malloc(sizeof(sfEvent));

    while (sfRenderWindow_pollEvent(WINDOW, event))
        switch (event->type) {
            case sfEvtClosed:
                sfRenderWindow_close(WINDOW);
            case sfEvtKeyReleased:
                close_detect(WINDOW, event, flame);
                break;
            case sfEvtMouseButtonPressed:
                is_pressed(flame);
                is_pause_pressed(flame);
            case sfEvtResized:
                update_resolution(flame, event);
                break;
            default:
                break;
        }
}

void update(flame_t *flame, float deltaTime, sfVector2f velocity)
{
    if (flame->player->can_move == 1 && flame->pause_menu->is_displayed == 0) {
        check_gravity(flame);
        if (sfKeyboard_isKeyPressed(sfKeySpace) &&
            flame->player->is_jumping == 0)
            flame->player->is_jumping = 1;
        if (sfKeyboard_isKeyPressed(sfKeyQ))
            move_player(flame, LEFT);
        if (sfKeyboard_isKeyPressed(sfKeyD))
            move_player(flame, RIGHT);
        jump_player(flame, deltaTime, &velocity, -200);
    }
    return;
}

void draw(flame_t *flame)
{
    sfRenderWindow_clear(WINDOW, sfWhite);
    if (flame->player->can_move == 1) {
        sfRenderWindow_drawSprite(WINDOW, flame->map, NULL);
        sfRenderWindow_drawSprite(WINDOW, PLAYER, NULL);
    }
    if (flame->player->can_move == 0) {
        sfRenderWindow_drawSprite(WINDOW, flame->back, NULL);
        display_menu(flame);
    }
    sfRenderWindow_setView(WINDOW, VIEW);
    display_pause_menu(flame);
    sfRenderWindow_display(WINDOW);
    return;
}

void game_loop(flame_t *flame)
{
    sfClock* clock = sfClock_create();
    float deltaTime = 0;
    sfVector2f velocity = {0.0f, 0.0f};

    while (sfRenderWindow_isOpen(WINDOW)) {
        deltaTime = sfTime_asSeconds(sfClock_restart(clock));
        analyse_events(flame);
        update(flame, deltaTime, velocity);
        draw(flame);
    }
    return;
}
