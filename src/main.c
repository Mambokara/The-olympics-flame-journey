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

int main(void)
{
    flame_t *flame = init_flame();

    sfRenderWindow_setFramerateLimit(WINDOW, flame->frame);
    game_loop(flame);
    return 0;
}
