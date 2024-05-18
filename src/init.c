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
    sfVector2f position = {100, 100};

    player->can_move = 0;
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

    sfView_setSize(view, (sfVector2f){1920, 1080});
    sfView_setCenter(view, sfSprite_getPosition(player->runner));
    return view;
}

static sfText *create_fps(void)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("./assets/Pixellari.ttf");

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    sfText_setFillColor(text, sfWhite);
    sfText_setOutlineThickness(text, 5);
    sfText_setString(text, "0 FPS");
    sfText_setPosition(text, (sfVector2f){0, 1040});
    return text;
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
    sfTexture *texture = get_texture(MAP);

    flame->status = MAIN_MENU;
    flame->back = create_sprite((sfVector2f) {0, 0}, "./assets/background.png",
        (sfVector2f) {1, 1});
    flame->player = init_player();
    flame->view = init_view(flame->player);
    flame->map = setup_sprite(texture, (sfVector2f){0, 0});
    flame->undermap = init_undermap();
    flame->settings = init_settings();
    flame->menu = init_menu();
    flame->portal = init_portal();
    flame->pause_menu = init_pause_menu();
    flame->game_win = sfRenderWindow_create(mode, "Flame",
        sfClose | sfResize | sfDefaultStyle, NULL);
    flame->fps = create_fps();
    sfRenderWindow_setView(WINDOW, VIEW);
    return flame;
}
