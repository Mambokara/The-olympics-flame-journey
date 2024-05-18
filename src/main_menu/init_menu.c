/*
** EPITECH PROJECT, 2024
** Jamalakitou
** File description:
** init_menu
*/

#include "../../include/functions.h"
#include "../../include/structs.h"

menu_t *init_menu(void)
{
    menu_t *menu = malloc(sizeof(menu_t));
    sfFont *font = sfFont_createFromFile("./assets/Pixellari.ttf");

    menu->play = create_text("PLAY", font, (sfVector2f) {830, 400}, 100);
    menu->option = create_text("OPTION", font, (sfVector2f) {765, 550}, 100);
    menu->credit = create_text("CREDITS", font, (sfVector2f) {745, 700}, 100);
    menu->quit = create_text("QUIT", font, (sfVector2f) {830, 850}, 100);
    return menu;
}
