/*
** EPITECH PROJECT, 2024
** The-olympics-flame-journey
** File description:
** portal_lvl3
*/

#include "../include/structs.h"
#include "../include/functions.h"
#include "../include/macros.h"

static portal_pos_t **fill_struct_portal_lvl3(void)
{
    portal_pos_t **portal_pos = malloc(sizeof(portal_t *)*3);

    sfVector2f pos_bin_0 = {4080, 1200};
    sfVector2f pos_bin_1 = {5280, 1056};

    for (int i = 0; i < 2; i++) {
        portal_pos[i] = malloc(sizeof(portal_pos_t));
    }
    portal_pos[0]->pos = pos_bin_0;
    portal_pos[1]->pos = pos_bin_1;
    portal_pos[2] =  NULL;
    for (int i = 0; i < 2; i++) {
        portal_pos[i]->id = i;
    }
    return portal_pos;
}

static void fill_struct_portal_isteleportor_lvl3(portal_t *portal)
{
    portal->portal_pos[0]->is_teleportor = 1;
    portal->portal_pos[1]->is_teleportor = 0;
}

static void create_rectangle_colision_lvl3(portal_t *portal)
{
    sfVector2f scale = {144, 96};

    for (int i = 0; i < 2; i++) {
        portal->portal_pos[i]->rect = sfRectangleShape_create();
        sfRectangleShape_setSize(portal->portal_pos[i]->rect, scale);
        sfRectangleShape_setPosition(portal->portal_pos[i]->rect, portal->portal_pos[i]->pos);
        sfRectangleShape_setFillColor(portal->portal_pos[i]->rect, sfWhite);
    }
}

portal_t *portal_lvl3(void)
{
    portal_t *portal = malloc(sizeof(portal_t));

    portal->portal_pos = fill_struct_portal_lvl3();
    fill_struct_portal_isteleportor_lvl3(portal);
    create_rectangle_colision_lvl3(portal);
    link_portal(portal, 0, 1);
    return portal;
}
