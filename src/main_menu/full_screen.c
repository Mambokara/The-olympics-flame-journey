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
    sfRenderWindow_destroy(WINDOW);
    game_loop(condi);
}
