/*
** EPITECH PROJECT, 2024
** Jam
** File description:
** main
*/

#include "../include/functions.h"
#include "../include/structs.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/View.h>
#include <SFML/System/Vector2.h>
#include <stdbool.h>

static sfTexture *get_texture(void)
{
    sfTexture *texture;

    texture = sfTexture_createFromFile("assets/player_texture.png", NULL);
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
    player->run_tex = get_texture();
    player->runner = setup_sprite(player->run_tex, position);
    return player;
}

static sfView *init_view(player_t *player)
{
    sfView *view = sfView_create();

    sfView_setCenter(view, sfSprite_getPosition(player->runner));
    return view;
}

static flame_t *init_flame(void)
{
    flame_t *flame = malloc(sizeof(flame_t));
    sfVideoMode mode = {1920, 1080, 32};

    flame->player = init_player();
    flame->view = init_view(flame->player);
    flame->game_win = sfRenderWindow_create(mode, "Flame",
        sfClose | sfResize | sfDefaultStyle, NULL);
    return flame;
}

int main(void)
{
    flame_t *flame = init_flame();

    game_loop(flame);
    return 0;
}
