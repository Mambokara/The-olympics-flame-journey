/*
** EPITECH PROJECT, 2024
** init_levels
** File description:
** intit all the levels
*/
#include "../../include/structs.h"
#include "../../include/functions.h"
#include <string.h>

level_t *init_level(int id)
{
    level_t *level = malloc(sizeof(level_t));
    char *file = strdup("./assets/levels/level");

    file = strcat(file, nbr_to_str(id));
    file = strcat(file, "_");
    level->background = create_sprite((sfVector2f){0, 0}, my_strcat(file, "background.png"), (sfVector2f){1, 1});
    level->ground = create_sprite((sfVector2f){0, 0}, my_strcat(file, "map.png"), (sfVector2f){1, 1});
    level->undermap = sfImage_createFromFile(my_strcat(file, "collision.png")); 
    return level;  
}

level_t **init_levels(void)
{
    level_t **levels = malloc(sizeof(level_t *) * 9);
    int index = 0;

    for (index = 0; index < 3; index++) {
        levels[index] = init_level(index + 1);
    }
    levels[0]->portal = portal_lvl2();
    levels[1]->portal = portal_lvl1();
    levels[index] = NULL;
    return levels;
}
