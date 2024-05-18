/*
** EPITECH PROJECT, 2024
** The-olympics-flame-journey
** File description:
** portal
*/
#include "../include/structs.h"
#include <SFML/Graphics.h>
#include "../include/functions.h"

int coord_portal(player_t *player, portal_t *portal)
{
    for (int i = 0; i < portal->nbr_portal; i++)
    if ((player->pos.x < portal->portal_pos[i]->pos.x + 10 || player->pos.x <
        portal->portal_pos[i]->pos.x - 10) && (player->pos.y <
        portal->portal_pos[i]->pos.y + 10 || player->pos.y <
        portal->portal_pos[i]->pos.y - 10)) {
            return 1;
    } else {
        return 0;
    }
}

void attribute_number_portal(portal_t *portal)
{
    for (int i = 0; i < portal->nbr_portal; i++) {
        portal->portal_pos[i]->id = i;
    }
}

void teleport(player_t *player, portal_t *portal, int i)
{
    if (sfKeyboard_isKeyPressed(sfKeyF) == sfTrue &&
        coord_portal(player, portal) == 1) {
        player->pos.x = portal->portal_pos[i]->pos_tp.x;
        player->pos.y = portal->portal_pos[i]->pos_tp.y;
    }
}

void create_portal(portal_t *portal)
{
    sfVector2f test = {0.0};
    sfVector2f test2 = {2.2};

    create_sprite_portal(portal, test, PORTAL, test2);
    create_sprite_portal(portal, test, PORTAL, test2);
}

void link_portal(portal_t *portal, int src, int dest)
{
    portal->portal_pos[src]->pos_tp = portal->portal_pos[dest]->pos;
}
