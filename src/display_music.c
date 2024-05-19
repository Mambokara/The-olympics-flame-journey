/*
** EPITECH PROJECT, 2024
** display_music
** File description:
** display the music volume
*/
#include "../include/structs.h"
#include "../include/functions.h"
#include <string.h>

void display_music(flame_t *flame)
{
    int music = sfMusic_getVolume(flame->sound->music);
    sfVector2f center = sfView_getCenter(VIEW);
    
    sfText_setString(flame->sound->text, nbr_to_str(music));
    sfText_setPosition(flame->sound->text, (sfVector2f)
        {center.x - 1900.0f / 2, center.y + 940.0f / 2});
    sfRenderWindow_drawText(flame->game_win, flame->sound->text, NULL);
}
