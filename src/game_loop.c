/*
** EPITECH PROJECT, 2024
** Jam
** File description:
** game_loop
*/

#include "../include/functions.h"
#include "../include/structs.h"
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>

void close_detect(sfRenderWindow *window, sfEvent *event)
{
    if (event->key.code == sfKeyEscape)
        sfRenderWindow_close(window);
}

void analyse_events(flame_t *flame)
{
    sfEvent *event = malloc(sizeof(sfEvent));

    while (sfRenderWindow_pollEvent(WINDOW, event))
        switch (event->type) {
            case sfEvtClosed:
                sfRenderWindow_close(WINDOW);
            case sfEvtKeyReleased:
                close_detect(WINDOW, event);
                break;
        }
}

void update(flame_t *flame)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        move_player(flame, LEFT);
    if (sfKeyboard_isKeyPressed(sfKeyD))
        move_player(flame, RIGHT);
    return;
}

void draw(flame_t *flame)
{
    sfRenderWindow_clear(WINDOW, sfWhite);
    sfRenderWindow_drawSprite(WINDOW, PLAYER , NULL);
    sfRenderWindow_setView(WINDOW, VIEW);
    sfRenderWindow_display(WINDOW);
    return;
}

void game_loop(flame_t *flame)
{
    while (sfRenderWindow_isOpen(WINDOW)) {
        analyse_events(flame);
        update(flame);
        draw(flame);
    }
    return;
}
