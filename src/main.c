/*
** EPITECH PROJECT, 2024
** Jam
** File description:
** main
*/

#include "../include/functions.h"
#include "../include/structs.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/VideoMode.h>
#include <SFML/Window/WindowBase.h>
#include <stdbool.h>

static player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));
    sfVector2f position = {960, 540};

    player->is_jumping = false;
    player->is_reversed = false;
    player->pos = position;
    player->runner = NULL;
    player->run_tex = NULL;
    return player;
}

static flame_t *init_flame(void)
{
    flame_t *flame = malloc(sizeof(flame_t));
    sfVideoMode mode = {1920, 1080, 32};

    flame->player = init_player();
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
