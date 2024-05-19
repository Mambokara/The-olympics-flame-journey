/*
** EPITECH PROJECT, 2024
** Jamalakitou
** File description:
** my_particuls
*/

#include "../include/functions.h"
#include "../include/structs.h"

void updateParticles(flame_t *flame, float deltaTime)
{
    for (size_t i = 0; i < flame->parts->count; i++) {
        flame->parts->part[i]->life -= deltaTime;
        if (flame->parts->part[i]->life > 0) {
            flame->parts->part[i]->pos = sfSprite_getPosition(flame->player->runner);
            flame->parts->part[i]->pos.x += flame->parts->part[i]->vel.x * deltaTime;
            flame->parts->part[i]->pos.y += flame->parts->part[i]->vel.y * deltaTime;
            float alpha = flame->parts->part[i]->life / 5.0f * 255;
            flame->parts->part[i]->color.a = (sfUint8)alpha;
        } else {
            flame->parts->part[i]->pos = (sfVector2f){400, 300};
            flame->parts->part[i]->vel = (sfVector2f){(rand() % 200 - 100) / 10.0f, (rand() % 200 - 100) / 10.0f};
            flame->parts->part[i]->life = 5.0f;
        }
    }
}

void drawParticles(flame_t *flame)
{
    for (size_t i = 0; i < flame->parts->count; i++) {
        if (flame->parts->part[i]->life > 0) {
            sfCircleShape* shape = sfCircleShape_create();
            sfCircleShape_setRadius(shape, 10.0f);
            sfCircleShape_setFillColor(shape, flame->parts->part[i]->color);
            sfCircleShape_setPosition(shape, flame->parts->part[i]->pos);
            sfRenderWindow_drawCircleShape(WINDOW, shape, NULL);
            sfCircleShape_destroy(shape);
        }
    }
}
