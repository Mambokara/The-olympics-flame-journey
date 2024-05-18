/*
** EPITECH PROJECT, 2024
** Jam
** File description:
** init_flame
*/

#include "../../include/structs.h"
#include "../../include/functions.h"
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/View.h>

flame_t *init_flame(void)
{
    flame_t *flame = malloc(sizeof(flame_t));
    sfVideoMode mode = {1920, 1080, 32};

    flame->back = create_sprite((sfVector2f) {0, 0}, "./assets/background.png",
        (sfVector2f) {1, 1});
    flame->player = init_player();
    flame->settings = init_settings();
    flame->menu = init_menu();
    flame->game_win = sfRenderWindow_create(mode, "Flame",
        sfClose | sfResize | sfDefaultStyle, NULL);
    flame->view = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    sfRenderWindow_setView(WINDOW, VIEW);
    return flame;
}
