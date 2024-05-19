/*
** EPITECH PROJECT, 2024
** Jamalakitou
** File description:
** my_particuls
*/

#include "../include/functions.h"
#include "../include/structs.h"

void emitParticle(particles_t *parts, sfVector2f pos, sfVector2f velocity) {
    if (parts->count < MAX_PARTICLES) {
        particle_t *particle = &parts->part[parts->count];
        int red = 255;
        int green = rand() % 256;
        int blue = 0;

        particle->color = sfColor_fromRGB(red, green, blue);
        particle->pos = pos;
        particle->vel = velocity;
        particle->life = 0.3f;
        parts->count++;
    }
}

void updateParticles(flame_t *flame, float deltaTime) {
    sfVector2f velocity = {0.0f, 0.0f};
    sfVector2f pos = sfView_getCenter(VIEW);

    pos.x += 24;
    pos.y += 26;
    emitParticle(flame->parts, pos, velocity);
    for (int i = 0; i < flame->parts->count; i++) {
        particle_t *particle = &flame->parts->part[i];
        particle->pos.x += particle->vel.x * deltaTime;
        particle->pos.y += particle->vel.y * deltaTime;
        float alpha = particle->life * 255;
        particle->color.a = (sfUint8)alpha;
        particle->life -= deltaTime * 2.0f;
        if (particle->life <= 0) {
            flame->parts->part[i] = flame->parts->part[flame->parts->count - 1];
            flame->parts->count--;
        }
    }
}

void drawParticles(flame_t *flame) {
    for (int i = 0; i < flame->parts->count; i++) {
        particle_t *particle = &flame->parts->part[i];
        sfCircleShape *shape = sfCircleShape_create();
        sfCircleShape_setRadius(shape, 10.0f);
        sfCircleShape_setFillColor(shape, particle->color);
        sfCircleShape_setPosition(shape, particle->pos);
        sfRenderWindow_drawCircleShape(WINDOW, shape, NULL);
        sfCircleShape_destroy(shape);
    }
}


