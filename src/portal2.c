/*
** EPITECH PROJECT, 2024
** The-olympics-flame-journey
** File description:
** portal2
*/
#include "../include/structs.h"
#include "../include/functions.h"

static portal_pos_t **fill_struct_portal_lvl2(void)
{
    portal_pos_t **portal_pos = malloc(sizeof(portal_t *));

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
    return portal_pos;
}

static portal_t *fill_struct_portal_lvl1(void)
{
    portal_t *portal = malloc(sizeof(portal_t));

    sfVector2f pos_bin_0 = {4128, 810};
    sfVector2f pos_bin_1 = {5520, 912};

    portal->portal_pos[0]->pos = pos_bin_0;
    portal->portal_pos[1]->pos = pos_bin_1;
}

static void fill_struct_portal_isteleportor_lvl2(portal_t *portal)
{
    portal->portal_pos[0]->is_teleportor = 0;
    portal->portal_pos[1]->is_teleportor = 1;
    portal->portal_pos[2]->is_teleportor = 1;
    portal->portal_pos[3]->is_teleportor = 1;
}

static void fill_struct_portal_isteleportor_lvl1(level_t *lvl)
{
    lvl->portal->portal_pos[0]->is_teleportor = 0;
    lvl->portal->portal_pos[1]->is_teleportor = 1;
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

static void create_rectangle_colision_lvl1(level_t *lvl)
{
    sfVector2f scale = {144, 144};

    for (int i = 0; i < 2; i++) {
        sfRectangleShape_setScale(lvl->portal->portal_pos[i]->rect, scale);
        sfRectangleShape_setPosition(lvl->portal->portal_pos[i]->rect, lvl->portal->portal_pos[i]->pos);
        sfRectangleShape_setFillColor(lvl->portal->portal_pos[i]->rect, sfWhite);
    }
}

// void teleport(player_t *player, portal_t *portal, int i)
// {
//     if (coord_portal(player, portal) == 1) {
//         player->pos.x = portal->portal_pos[i]->pos_tp.x;
//         player->pos.y = portal->portal_pos[i]->pos_tp.y;
//         sfSprite_setPosition(player->runner, player->pos);
//     }
// }

portal_t *portal_lvl1(level_t *lvl)
{
    fill_struct_portal_lvl1();
    fill_struct_portal_isteleportor_lvl1(lvl);
    create_rectangle_colision_lvl1(lvl);
}

portal_t *portal_lvl2(void)
{
    portal_t *portal = malloc(sizeof(portal_t));

    portal->portal_pos = fill_struct_portal_lvl2();
    fill_struct_portal_isteleportor_lvl2(portal);
    create_rectangle_colision_lvl2(portal);
    return portal;
}

void draw_rectangle(flame_t *flame)
{
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawRectangleShape(WINDOW, flame->levels[flame->current_level]->portal->portal_pos[i]->rect, NULL);
    }
}