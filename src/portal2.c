/*
** EPITECH PROJECT, 2024
** The-olympics-flame-journey
** File description:
** portal2
*/
#include "../include/structs.h"
#include "../include/functions.h"

static void fill_struct_portal_lvl2(level_t *lvl)
{
    sfVector2f pos_bin_0 = {4128, 810};
    sfVector2f pos_bin_1 = {5520, 912};
    sfVector2f pos_bin_2 = {6096, 1296};
    sfVector2f pos_bin_3 = {6960, 1248};

    lvl->portal->portal_pos[0]->pos = pos_bin_0;
    lvl->portal->portal_pos[1]->pos = pos_bin_1;
    lvl->portal->portal_pos[2]->pos = pos_bin_2;
    lvl->portal->portal_pos[3]->pos = pos_bin_3;
}

static void fill_struct_portal_lvl1(level_t *lvl)
{
    sfVector2f pos_bin_0 = {4128, 810};
    sfVector2f pos_bin_1 = {5520, 912};

    lvl->portal->portal_pos[0]->pos = pos_bin_0;
    lvl->portal->portal_pos[1]->pos = pos_bin_1;
}

static void fill_struct_portal_isteleportor_lvl2(level_t *lvl)
{
    lvl->portal->portal_pos[0]->is_teleportor = 0;
    lvl->portal->portal_pos[0]->is_teleportor = 1;
    lvl->portal->portal_pos[0]->is_teleportor = 1;
    lvl->portal->portal_pos[0]->is_teleportor = 1;
}

static void fill_struct_portal_isteleportor_lvl1(level_t *lvl)
{
    lvl->portal->portal_pos[0]->is_teleportor = 0;
    lvl->portal->portal_pos[0]->is_teleportor = 1;
}

static void create_rectangle_colision_lvl2(level_t *lvl)
{
    sfVector2f scale = {144, 144};

    for (int i = 0; i < 4; i++) {
        sfRectangleShape_setScale(lvl->portal->portal_pos[i]->rect, scale);
        sfRectangleShape_setPosition(lvl->portal->portal_pos[i]->rect, lvl->portal->portal_pos[i]->pos);
        sfRectangleShape_setFillColor(lvl->portal->portal_pos[i]->rect, sfWhite);
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

void portal_lvl1(level_t *lvl)
{
    fill_struct_portal_lvl1(lvl);
    fill_struct_portal_isteleportor_lvl1(lvl);
    create_rectangle_colision_lvl1(lvl);
}

void portal_lvl2(level_t *lvl)
{
    fill_struct_portal_lvl2(lvl);
    fill_struct_portal_isteleportor_lvl2(lvl);
    create_rectangle_colision_lvl2(lvl);
}