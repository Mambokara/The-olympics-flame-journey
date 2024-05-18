/*
** EPITECH PROJECT, 2024
** init_all
** File description:
** init everything in the structs
*/

#include "../include/structs.h"
#include "../include/functions.h"
#include <SFML/Graphics/Types.h>

static sfTexture *get_texture(char *str)
{
    sfTexture *texture;

    texture = sfTexture_createFromFile(str, NULL);
    return texture;
}

static sfSprite *setup_sprite(sfTexture *texture, sfVector2f pos)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setPosition(sprite, pos);
    return sprite;
}

static player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));
    sfVector2f position = {960, 540};

    player->is_jumping = false;
    player->is_reversed = false;
    player->pos = position;
    player->run_tex = get_texture("assets/player_texture.png");
    player->runner = setup_sprite(player->run_tex, position);
    return player;
}

static sfView *init_view(player_t *player)
{
    sfView *view = sfView_create();

    sfView_setCenter(view, sfSprite_getPosition(player->runner));
    return view;
}

sfImage *init_undermap(void)
{
    sfImage *undermap = sfImage_createFromFile(UNDERMAP);

    return undermap;
}

flame_t *init_flame(void)
{
    flame_t *flame = malloc(sizeof(flame_t));
    sfVideoMode mode = {1920, 1080, 32};
    sfTexture *texture = get_texture(UNDERMAP);

    flame->player = init_player();
    flame->view = init_view(flame->player);
    flame->map = setup_sprite(texture, (sfVector2f){0, 0});
    flame->undermap = init_undermap();
    flame->game_win = sfRenderWindow_create(mode, "Flame",
        sfClose | sfResize | sfDefaultStyle, NULL);
    return flame;
}