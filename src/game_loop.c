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
#include <SFML/Graphics/Sprite.h>
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

void key_detect(sfRenderWindow *window, sfEvent *event, flame_t *flame)
{
    if (flame->status == MAIN_MENU || flame->buffer == MAIN_MENU)
        return;
    if (event->key.code == sfKeyEnter && flame->status == LEVEL_SELECTION) {
        flame->status = IN_GAME;
        flame->buffer = IN_GAME;
    }
    if (event->key.code == sfKeyEscape) {
        if (flame->pause_menu->is_displayed == 0) {
            flame->pause_menu->is_displayed = 1;
            flame->buffer = flame->status;
            flame->status = PAUSE_MENU;
        } else {
            flame->pause_menu->is_displayed = 0;
            flame->status = flame->buffer;
        }
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
                key_detect(WINDOW, event, flame);
                break;
            case sfEvtMouseButtonPressed:
                menu_pressed(flame);
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
    if (flame->status != IN_GAME)
        return;
    if (flame->status == IN_GAME && flame->pause_menu->is_displayed == 0) {
        animate_flame(flame);
        check_gravity(flame);
        if (sfKeyboard_isKeyPressed(sfKeySpace) &&
            flame->player->is_jumping == 0)
            flame->player->is_jumping = 1;
        if (sfKeyboard_isKeyPressed(sfKeyQ)) {
            move_player(flame, LEFT);
        }
        if (sfKeyboard_isKeyPressed(sfKeyD))
            move_player(flame, RIGHT);
        jump_player(flame, deltaTime, &velocity, -200);
    }
    return;
}

void make_musique(flame_t *flame)
{
    sfMusic_setLoop(flame->sound->music, sfTrue);
    sfMusic_play(flame->sound->music);
    sfMusic_setVolume(flame->sound->music, 50.0f);
}

void draw(flame_t *flame)
{
    sfRenderWindow_clear(WINDOW, sfWhite);
    if (flame->status == IN_GAME || flame->buffer == IN_GAME) {
        sfRenderWindow_drawSprite(WINDOW, flame->map, NULL);
        sfRenderWindow_drawSprite(WINDOW, PLAYER, NULL);
    }
    if (flame->status == MAIN_MENU || flame->buffer == MAIN_MENU) {
        sfRenderWindow_drawSprite(WINDOW, flame->back, NULL);
        display_menu(flame);
    }
    if (flame->status == LEVEL_SELECTION || flame->buffer == LEVEL_SELECTION) {
        sfRenderWindow_drawSprite(WINDOW, flame->world->map, NULL);
    }
    sfRenderWindow_setView(WINDOW, VIEW);
    display_pause_menu(flame);
    display_framerate(flame);
    sfRenderWindow_display(WINDOW);
    return;
}

void game_loop(int window)
{
    flame_t *flame = init_flame(window);
    sfClock* clock = sfClock_create();
    float deltaTime = 0;
    flame->player->respawn = (sfVector2f){100, 1000};
    sfVector2f velocity = {0.0f, 0.0f};

    flame->clock = sfClock_create();
    flame->player->anim_clock = sfClock_create();
    make_musique(flame);
    sfRenderWindow_setFramerateLimit(WINDOW, flame->frame);
    // sfRenderWindow_setFramerateLimit(WINDOW, 300);
    while (sfRenderWindow_isOpen(WINDOW)) {
        deltaTime = sfTime_asSeconds(sfClock_restart(clock));
        analyse_events(flame);
        update(flame, deltaTime, velocity);
        draw(flame);
        printf("%d\n", flame->status);
    }
    return;
}
