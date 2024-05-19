/*
** EPITECH PROJECT, 2024
** save.c
** File description:
** Save file for the game
*/

#include "../../include/functions.h"
#include "../../include/structs.h"
#include <fcntl.h>
#include <unistd.h>

int save(flame_t *flame)
{
    int counter = 48;
    int fd = open("./.ofj.save", O_WRONLY | O_CREAT, 0666);

    for (int i = 0; i < 8; i++) {
        if (flame->world->stock[i]->locked == 0) {
         counter ++;
        }
    }
    write(fd, &counter, 1);
    return 0;
}

int load(flame_t *flame)
{
    int fd = open("./.ofj.save", O_RDWR, 0777);
    char *infos = malloc(sizeof(char) * 10);

    if (fd == - 1) {
        return 0;
    }
    read(fd, infos, 10);
    if (atoi(infos) > 8) {
        return 0;
    }
    for (int i = 0; i < atoi(infos); i++) {
        flame->world->stock[i]->locked = 0;
    }
    return 0;
}
