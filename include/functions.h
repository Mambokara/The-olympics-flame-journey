/*
** EPITECH PROJECT, 2024
** functions.h
** File description:
** All functions for the project
*/


#pragma once
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Types.h>
    #include "structs.h"
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdbool.h>

// MOVE FUNCTIONS

int move_player(flame_t *flame, int side);
void check_gravity(flame_t *flame);
void jump_player(flame_t *flame, float deltaTime, sfVector2f *velocity,
    int jump_height);
void animate_flame(flame_t *flame);

/* Game loop functions */

void game_loop(int window);
sfVector2f get_universal_mouse_position(flame_t *flame);

/* Init functions */

w_map_t *init_level_selector(void);
menu_t *init_menu(void);

void display_menu(flame_t *flame);

/* !MENU FUNCTION */

void closed_window(flame_t *flame);
void over_text(flame_t *flame);
void is_pressed(flame_t *flame);
settings_t *init_settings(void);
sfText *create_text(char *str, sfFont *font, sfVector2f position,
    unsigned int Size);
sfSprite *create_sprite(sfVector2f pos, char *file, sfVector2f scale);
sfSprite *create_sprite_portal(portal_t *portal, sfVector2f pos,
    char *file, sfVector2f scale);
sfRectangleShape *create_rectangle(sfVector2f size, sfVector2f pos,
    sfColor outline, sfColor fill);
flame_t *init_flame(int window);
pause_menu_t *init_pause_menu(void);
void display_pause_menu(flame_t *flame);
void is_pause_pressed(flame_t *flame);
void over_pause_text(flame_t *flame);
void move_pause_menu(flame_t *flame, sfVector2f move);
char *my_strcat(char *dest, char *src);
int my_strlen(char const *str);
void display_credits(flame_t *flame);
void display_option(flame_t *flame);
void button_option(flame_t *flame);
void menu_pressed(flame_t *flame);
void display_framerate(flame_t *flame);
char *my_revstr(char *str);
char *nbr_to_str(int nb);
portal_t *init_portal(void);
void get_portal_in_struct(portal_t *portal);
void full_screen(flame_t *flame, int condi);
void resolution_window(flame_t *flame, int condi);
void display_background(flame_t *flame);
level_t **init_levels(void);
void link_portal(portal_t *portal, int src, int dest);
void draw_rectangle(flame_t * flame);
void display_music(flame_t *flame);
void teleport(player_t *player, portal_t *portal, int i, flame_t *flame);
portal_t *portal_lvl1(void);
portal_t *portal_lvl2(void);
portal_t *portal_lvl3(void);
portal_t *portal_lvl4(void);
portal_t *portal_lvl5(void);
portal_t *portal_lvl6(void);
portal_t *portal_lvl7(void);

void selection_menu(flame_t *flame);
void draw_lock(flame_t *flame);
void drawParticles(flame_t *flame);
void updateParticles(flame_t *flame, float deltaTime);
