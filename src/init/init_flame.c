/*
** EPITECH PROJECT, 2024
** Jam
** File description:
** init_flame
*/

#include "../../include/structs.h"
#include "../../include/functions.h"

flame_t *init_flame(void)
{
    flame_t *flame = malloc(sizeof(flame_t));
    sfVideoMode mode = {1920, 1080, 32};

    flame->player = init_player();
    flame->settings = init_settings();
    flame->game_win = sfRenderWindow_create(mode, "Flame",
        sfClose | sfResize | sfDefaultStyle, NULL);
    return flame;
}
