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
#include <SFML/System/Vector2.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>

void close_detect(sfRenderWindow *window, sfEvent *event)
{
    if (event->key.code == sfKeyEscape)
        sfRenderWindow_close(window);
}

static void update_resolution(flame_t *flame)
{
    sfVector2u size_new = sfRenderWindow_getSize(WINDOW);
    float target = (float)SETTINGS->resolution.x / (float)SETTINGS->resolution.y;
    float actual = (float)size_new.x / (float)size_new.y;

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
                close_detect(WINDOW, event);
                break;
            case sfEvtResized:
                //update_resolution(flame);
                break;
            default:
                break;
        }
}

void update(flame_t *flame)
{
    return;
}

void draw(flame_t *flame)
{
    sfRenderWindow_clear(WINDOW, sfWhite);
    sfRenderWindow_drawSprite(WINDOW, flame->back, NULL);
    display_menu(flame);
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
