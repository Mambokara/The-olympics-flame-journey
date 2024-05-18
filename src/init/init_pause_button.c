/*
** EPITECH PROJECT, 2024
** init_pause_menu
** File description:
** init the pause menu
*/
#include "../../include/structs.h"
#include "../../include/functions.h"

pause_menu_t *init_pause_menu(void)
{
    pause_menu_t *menu = malloc(sizeof(pause_menu_t));
    sfFont *font = sfFont_createFromFile("./assets/Pixellari.ttf");

    menu->is_displayed = 0;
    menu->resume = create_text("Back to Game", font,
        (sfVector2f) {700, 700}, 80);
    menu->main_menu = create_text("Go to Main Menu", font, (sfVector2f)
        {660, 400}, 80);
    menu->quit = create_text("Leave Level", font, (sfVector2f) {740, 550}, 80);
    return menu;
}
