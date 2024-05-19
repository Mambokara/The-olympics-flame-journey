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
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>
#include <stdio.h>
#include <time.h>

sfVector2f get_universal_mouse_position(flame_t *flame)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(WINDOW);
    sfView const *view = sfRenderWindow_getView(WINDOW);

    return sfRenderWindow_mapPixelToCoords(WINDOW, mouse, view);
}

void key_detect(sfEvent *event, flame_t *flame)
{
    switch (event->key.code) {
        case sfKeyD:
            flame->world->button = R;
            break;
        case sfKeyQ:
            flame->world->button = L;
            break;
        case sfKeyZ:
            flame->world->button = UP;
            break;
        case sfKeyS:
            flame->world->button = DOWN;
            break;
        default:
            flame->world->button = NONE;
            break;
    }
    if (flame->status == MAIN_MENU || flame->buffer == MAIN_MENU)
        return;
    if (event->key.code == sfKeyEnter && flame->status == LEVEL_SELECTION) {
        flame->current_level = flame->world->start->id - 1;
        flame->status = IN_GAME;
        flame->buffer = IN_GAME;
        sfSprite_setPosition(PLAYER, (sfVector2f){100, 1000});
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

void analyse_events(flame_t *flame)
{
    sfEvent *event = malloc(sizeof(sfEvent));

    while (sfRenderWindow_pollEvent(WINDOW, event))
        switch (event->type) {
            case sfEvtClosed:
                sfRenderWindow_close(WINDOW);
            case sfEvtKeyReleased:
                key_detect(event, flame);
                break;
            case sfEvtMouseButtonPressed:
                menu_pressed(flame);
                is_pause_pressed(flame);
            default:
                break;
        }
}

void update(flame_t *flame, float deltaTime, sfVector2f velocity)
{
    if (flame->status == LEVEL_SELECTION)
        selection_menu(flame);
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
    for (int i = 0; CURRENT_LVL->portal->portal_pos[i] != NULL; i++) {
        teleport(flame->player, CURRENT_LVL->portal, i, flame);
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
    level_t *level = flame->levels[flame->current_level];

    sfRenderWindow_clear(WINDOW, sfBlack);
    display_background(flame);
    if (flame->status == IN_GAME || flame->buffer == IN_GAME) {
        sfRenderWindow_drawSprite(WINDOW, level->ground, NULL);
        sfRenderWindow_drawSprite(WINDOW, flame->checkpoint, NULL);
        drawParticles(flame);
        sfRenderWindow_drawSprite(WINDOW, PLAYER, NULL);
    }
    if (flame->status == MAIN_MENU || flame->buffer == MAIN_MENU) {
        sfRenderWindow_drawSprite(WINDOW, flame->back, NULL);
        display_menu(flame);
    }
    if (flame->status == LEVEL_SELECTION || flame->buffer == LEVEL_SELECTION) {
        sfRenderWindow_drawSprite(WINDOW, flame->world->map, NULL);
        draw_lock(flame);
        sfRenderWindow_drawSprite(WINDOW, flame->player->runner, NULL);
    }
    sfRenderWindow_setView(WINDOW, VIEW);
    display_pause_menu(flame);
    display_framerate(flame);
    display_music(flame);
    sfRenderWindow_display(WINDOW);
    return;
}

void set_icon(flame_t *flame)
{
    sfImage* icon = sfImage_createFromFile("./assets/logo_jam.png");
    const sfUint8* iconPixels = sfImage_getPixelsPtr(icon);
    sfVector2u iconSize = sfImage_getSize(icon);
    sfRenderWindow_setIcon(WINDOW, iconSize.x, iconSize.y, iconPixels);
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
    sfSprite_scale(flame->checkpoint, (sfVector2f){0.5, 0.5});
    sfSprite_setPosition(flame->checkpoint, (sfVector2f){4600, 730});
    set_icon(flame);
    sfRenderWindow_setFramerateLimit(WINDOW, 600);
    while (sfRenderWindow_isOpen(WINDOW)) {
        deltaTime = sfTime_asSeconds(sfClock_restart(clock));
        updateParticles(flame, deltaTime);
        analyse_events(flame);
        update(flame, deltaTime, velocity);
        draw(flame);
    }
    return;
}
