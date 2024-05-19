/*
** EPITECH PROJECT, 2024
** Jamalakitou
** File description:
** resolution_window
*/

#include "../../include/functions.h"
#include "../../include/structs.h"

void resolution_window(flame_t *flame, int condi)
{
    sfRenderWindow_destroy(WINDOW);
    game_loop(condi);
}