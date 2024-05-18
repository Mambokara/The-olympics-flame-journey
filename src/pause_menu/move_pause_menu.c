/*
** EPITECH PROJECT, 2024
** move_pause_menu
** File description:
** move the pause menu
*/
#include "../../include/structs.h"
#include "../../include/functions.h"

void move_pause_menu(flame_t *flame, sfVector2f move)
{
    sfText_move(flame->pause_menu->main_menu, move);
    sfText_move(flame->pause_menu->quit, move);
    sfText_move(flame->pause_menu->resume, move);
}
