/*
** EPITECH PROJECT, 2024
** Jamalakitou
** File description:
** full_screen
*/

#include "../../include/functions.h"
#include "../../include/structs.h"

void full_screen(flame_t *flame, int condi)
{
    sfVideoMode mode = {1920, 1080, 32};

    sfRenderWindow_destroy(WINDOW);
    game_loop(condi);
}
