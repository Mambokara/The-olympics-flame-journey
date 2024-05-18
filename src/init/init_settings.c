/*
** EPITECH PROJECT, 2024
** Jam
** File description:
** init settings
*/

#include "../../include/structs.h"

settings_t *init_settings(void)
{
    settings_t *settings = malloc(sizeof(settings_t));

    settings->mvolume = 100;
    settings->svolume = 100;
    settings->framerate = 60;
    settings->resolution.x = 1920;
    settings->resolution.y = 1080;
    settings->is_fullscreen = sfFalse;
    return settings;
}
