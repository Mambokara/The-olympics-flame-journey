/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** text_utils
*/

#include "../../include/functions.h"
#include "../../include/structs.h"

sfText *create_text(char *str, sfFont *font, sfVector2f position,
    unsigned int Size)
{
    sfText *text = sfText_create();

    if (!text) {
        return NULL;
    }
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, Size);
    sfText_setFillColor(text, sfWhite);
    sfText_setOutlineThickness(text, 5);
    sfText_setString(text, str);
    sfText_setPosition(text, position);
    return text;
}
