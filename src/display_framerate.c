/*
** EPITECH PROJECT, 2024
** display_frmaerate
** File description:
** display the framerate
*/
#include "../include/structs.h"
#include "../include/functions.h"
#include <string.h>

void display_framerate(flame_t *flame)
{
    static int first = 1;
    static sfClock * clock;
    static int fps = 0;
    char *fps_text;
    sfTime elapsed;
    sfVector2f center = sfView_getCenter(VIEW);

    if (first == 1) {
        clock = sfClock_create();
        first = 0;
    }
    elapsed = sfClock_getElapsedTime(clock);
    if (sfTime_asSeconds(elapsed) >= 1) {
        fps_text = nbr_to_str(fps);
        strcat(fps_text, " FPS");
        sfText_setString(flame->fps, fps_text);
        fps = 0;
        sfClock_restart(clock);
    } else
        fps ++;
    sfText_setPosition(flame->fps, (sfVector2f) {center.x - 1900.0f / 2, center.y + 1000.0f / 2});
    sfRenderWindow_drawText(flame->game_win, flame->fps, NULL);
}
