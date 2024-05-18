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
#include <stdbool.h>

int main(void)
{
    flame_t *flame = init_flame();

    game_loop(flame);
    return 0;
}
