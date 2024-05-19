/*
** EPITECH PROJECT, 2024
** The-olympics-flame-journey
** File description:
** portal
*/
#include "../include/structs.h"
#include <SFML/Graphics.h>
#include "../include/functions.h"

void link_portal(portal_t *portal, int src, int dest)
{
    portal->portal_pos[src]->pos_tp = portal->portal_pos[dest]->pos;
}

void display_portal(flame_t *flame)
{
    sfRenderWindow_drawSprite(WINDOW, flame->player->runner, NULL);
}