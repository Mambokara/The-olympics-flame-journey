/*
** EPITECH PROJECT, 2024
** The-olympics-flame-journey
** File description:
** portal2
*/
#include "../include/structs.h"
#include "../include/functions.h"
#include "../include/macros.h"

int coord_portal(player_t *player, portal_t *portal, flame_t *flame, int i)
{
    player->pos = sfView_getCenter(VIEW);
    if(player->pos.x >= portal->portal_pos[i]->pos.x &&
        player->pos.x <= portal->portal_pos[i]->pos.x + 144 &&
        player->pos.y >= portal->portal_pos[i]->pos.y && player->pos.y <=
        portal->portal_pos[i]->pos.y + 96) {
        return i;
    }
    return -1;
}

void teleport(player_t *player, portal_t *portal, int i, flame_t *flame)
{
    if (coord_portal(player, portal, flame, i) != -1 && portal->portal_pos[i]->id != 0) {
        player->pos.x = portal->portal_pos[i]->pos_tp.x;
        player->pos.y = portal->portal_pos[i]->pos_tp.y;
        sfSprite_setPosition(player->runner, player->pos);
    }
}

static portal_pos_t **fill_struct_portal_lvl1(void)
{
    portal_pos_t **portal_pos = malloc(sizeof(portal_t *)*3);

    sfVector2f pos_bin_0 = {1824, 1008};
    sfVector2f pos_bin_1 = {3360, 816};

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

static void fill_struct_portal_isteleportor_lvl1(portal_t *portal)
{
    portal->portal_pos[0]->is_teleportor = 1;
    portal->portal_pos[1]->is_teleportor = 0;
}

static void create_rectangle_colision_lvl1(portal_t *portal)
{
    sfVector2f scale = {144, 96};

    for (int i = 0; i < 2; i++) {
        portal->portal_pos[i]->rect = sfRectangleShape_create();
        sfRectangleShape_setSize(portal->portal_pos[i]->rect, scale);
        sfRectangleShape_setPosition(portal->portal_pos[i]->rect, portal->portal_pos[i]->pos);
        sfRectangleShape_setFillColor(portal->portal_pos[i]->rect, sfWhite);
    }
}

portal_t *portal_lvl1(void)
{
    portal_t *portal = malloc(sizeof(portal_t));

    portal->portal_pos = fill_struct_portal_lvl1();
    fill_struct_portal_isteleportor_lvl1(portal);
    create_rectangle_colision_lvl1(portal);
    link_portal(portal, 0, 1);
    return portal;
}

void draw_rectangle(flame_t *flame)
{
    for (int i = 0; i < 2; i++) {
        sfRenderWindow_drawRectangleShape(WINDOW, flame->levels[flame->current_level]->portal->portal_pos[i]->rect, NULL);
    }
}
