/*
** EPITECH PROJECT, 2024
** init_all
** File description:
** init everything in the structs
*/

#include "../include/structs.h"
#include "../include/functions.h"
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
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
    sfFont *font = sfFont_createFromFile("./assets/Pixellari.ttf");

    sound->sound = 0;
    sound->music = sfMusic_createFromFile("./assets/french_music.ogg");
    sound->text = create_text("Music: 0", font, (sfVector2f){10, 980}, 30);
    return sound;
}

// succes_t *init_succes(void)
// {
// }

particle_t *add_particle(int i)
{
    particle_t *part = malloc(sizeof(particle_t));

    part->pos = (sfVector2f){400, 300};
    part->vel = (sfVector2f){(rand() % 200 - 100) / 10.0f, (rand() % 200 - 100) / 10.0f};
    part->color = sfRed;
    part->life = 5.0f;
}

particles_t *init_particles(void)
{
    particles_t *parts = malloc(sizeof(particles_t));

    parts->count = 10;
    parts->is_part = 0;
    parts->part = malloc(sizeof(particle_t *) * (parts->count + 1));
    for (int i = 0; i < parts->count; i++)
        parts->part[i] = add_particle(i);
    parts->part[parts->count] = NULL;
    return parts;
}

sfSprite *init_checkpoint()
{
    sfTexture *texture = sfTexture_createFromFile("./assets/_b38285a7-5eab-417a-9107-c2c30eff117f-removebg-preview(1).png", NULL);
    sfSprite *torch = sfSprite_create();

    sfSprite_setTexture(torch, texture, sfFalse);
    return torch;
}

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
    flame->parts = init_particles();
    flame->status = MAIN_MENU;
    flame->buffer = MAIN_MENU;
    flame->screen = window;
    flame->sound = init_sound();
    flame->back = create_sprite((sfVector2f) {0, 0}, "./assets/background.png",
        (sfVector2f) {1, 1});
    flame->player = init_player();
    flame->view = init_view(flame->player);
    flame->current_level = 0;
    flame->levels = init_levels();
    flame->settings = init_settings();
    flame->menu = init_menu();
    flame->pause_menu = init_pause_menu();
    flame->world = init_level_selector();
    flame->checkpoint = init_checkpoint();
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
