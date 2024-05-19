/*
** EPITECH PROJECT, 2024
** init_all
** File description:
** init everything in the structs
*/

#include "../include/structs.h"
#include "../include/functions.h"
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>

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
    sfVector2f position = {100, 1000};

    player->can_move = 0;
    player->is_jumping = false;
    player->is_reversed = false;
    player->pos = position;
    player->right_tex = get_texture("assets/spritesheet_right.png");
    player->left_tex = get_texture("assets/spritesheet_left.png");
    player->runner = setup_sprite(player->right_tex, position);
    return player;
}

static sfView *init_view(player_t *player)
{
    sfView *view = sfView_create();

    sfView_setSize(view, (sfVector2f){1920, 1080});
    sfView_setCenter(view, (sfVector2f){960, 540});
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
    sfText_setPosition(text, (sfVector2f){10, 1040});
    return text;
}

sfImage *init_undermap(void)
{
    sfImage *undermap = sfImage_createFromFile(UNDERMAP);

    return undermap;
}

sound_t *init_sound(void)
{
    sound_t *sound = malloc(sizeof(sound_t));

    sound->sound = 0;
    sound->music = sfMusic_createFromFile("./assets/french_music.ogg");
    return sound;
}

// succes_t *init_succes(void)
// {


// }

flame_t *init_flame(int window)
{
    flame_t *flame = malloc(sizeof(flame_t));
    sfVideoMode m1920 = {1920, 1080, 32};
    sfVideoMode m1536 = {1536, 864, 32};
    sfVideoMode m1366 = {1366, 768, 32};
    sfTexture *texture = get_texture(MAP);

    if (window == 10) {
        flame->game_win = sfRenderWindow_create(m1920, "Flame",
            sfClose | sfResize | sfDefaultStyle, NULL);
    }
    if (window == 11) {
        flame->game_win = sfRenderWindow_create(m1536, "Flame",
            sfClose | sfResize | sfDefaultStyle, NULL);
    }
    if (window == 12) {
        flame->game_win = sfRenderWindow_create(m1366, "Flame",
            sfClose | sfResize | sfDefaultStyle, NULL);
    }
    flame->frame = 30;
    flame->status = MAIN_MENU;
    flame->buffer = MAIN_MENU;
    flame->screen = window;
    // flame->scs = init_succes();
    flame->sound = init_sound();
    flame->back = create_sprite((sfVector2f) {0, 0}, "./assets/background.png",
        (sfVector2f) {1, 1});
    flame->player = init_player();
    flame->view = init_view(flame->player);
    flame->map = setup_sprite(texture, (sfVector2f){0, 0});
    flame->background_city = create_sprite((sfVector2f){0, 0}, "./assets/levels/level1_background.png", (sfVector2f){1, 1});
    flame->undermap = init_undermap();
    flame->settings = init_settings();
    flame->menu = init_menu();
    flame->portal = init_portal();
    flame->pause_menu = init_pause_menu();
    flame->world = init_level_selector();
    if (window == 0 && window < 10)
        flame->game_win = sfRenderWindow_create(m1920, "Flame",
            sfClose | sfResize | sfDefaultStyle, NULL);
    if (window == 1 && window < 10)
         flame->game_win = sfRenderWindow_create(m1920, "Flame",
            sfClose | sfResize | sfFullscreen, NULL);
    flame->fps = create_fps();
    sfRenderWindow_setView(WINDOW, VIEW);
    return flame;
}
