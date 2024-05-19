/*
** EPITECH PROJECT, 2024
** Jam
** File description:
** level_selection
*/

#include "../../include/functions.h"
#include "../../include/structs.h"
#include "../../include/macros.h"
 
void selection_menu(flame_t *flame)
{
    sfSprite_setPosition(PLAYER, flame->world->start->position);
    animate_flame(flame);
    if (flame->world->button == L) {
        if (flame->world->start->left != NULL && POSITION->left->locked != 1)
            flame->world->start = flame->world->start->left;
        flame->world->button = NONE;
    }
    if (flame->world->button == R) {
        if (flame->world->start->right != NULL && POSITION->right->locked != 1)
            flame->world->start = flame->world->start->right;
        flame->world->button = NONE;
    }
    if (flame->world->button == DOWN) {
        if (flame->world->start->down != NULL && POSITION->down->locked != 1)
            flame->world->start = flame->world->start->down;
        flame->world->button = NONE;
    }
    if (flame->world->button == UP) {
        if (flame->world->start->up != NULL && POSITION->up->locked != 1)
            flame->world->start = flame->world->start->up;
        flame->world->button = NONE;
    }
}

void draw_lock(flame_t *flame)
{
    for (int i = 0; flame->world->stock[i]; i++) {
        if (flame->world->stock[i]->locked == 1)
            sfRenderWindow_drawSprite(WINDOW, flame->world->stock[i]->lock, NULL);
    }
}
