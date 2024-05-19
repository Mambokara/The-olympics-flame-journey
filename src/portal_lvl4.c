/*
** EPITECH PROJECT, 2024
** The-olympics-flame-journey
** File description:
** portal_lvl4
*/

#include "../include/structs.h"
#include "../include/functions.h"
#include "../include/macros.h"

static portal_pos_t **fill_struct_portal_lvl2(void)
{
    portal_pos_t **portal_pos = malloc(sizeof(portal_t *)*5);

    sfVector2f pos_bin_0 = {4128, 864};
    sfVector2f pos_bin_1 = {5520, 960};
    sfVector2f pos_bin_2 = {6096, 1344};
    sfVector2f pos_bin_3 = {6960, 1296};

    for (int i = 0; i < 4; i++) {
        portal_pos[i] = malloc(sizeof(portal_pos_t));
    }
    portal_pos[0]->pos = pos_bin_0;
    portal_pos[1]->pos = pos_bin_1;
    portal_pos[2]->pos = pos_bin_2;
    portal_pos[3]->pos = pos_bin_3;
    portal_pos[4] =  NULL;
    for (int i = 0; i < 4; i++) {
        portal_pos[i]->id = i;
    }
    return portal_pos;
}

static void fill_struct_portal_isteleportor_lvl2(portal_t *portal)
{
    portal->portal_pos[0]->is_teleportor = 1;
    portal->portal_pos[1]->is_teleportor = 0;
    portal->portal_pos[2]->is_teleportor = 1;
    portal->portal_pos[3]->is_teleportor = 0;
}

static void create_rectangle_colision_lvl2(portal_t *portal)
{
    sfVector2f size = {144, 96};

    for (int i = 0; i < 4; i++) {
        portal->portal_pos[i]->rect = sfRectangleShape_create();
        sfRectangleShape_setSize(portal->portal_pos[i]->rect, size);
        sfRectangleShape_setPosition(portal->portal_pos[i]->rect, portal->portal_pos[i]->pos);
        sfRectangleShape_setFillColor(portal->portal_pos[i]->rect, sfWhite);
    }
}

portal_t *portal_lvl2(void)
{
    portal_t *portal = malloc(sizeof(portal_t));

    portal->portal_pos = fill_struct_portal_lvl2();
    fill_struct_portal_isteleportor_lvl2(portal);
    create_rectangle_colision_lvl2(portal);
    link_portal(portal, 0, 1);
    link_portal(portal, 2, 3);
    return portal;
}