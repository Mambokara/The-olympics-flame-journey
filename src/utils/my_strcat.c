/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** concatenates two strings
*/
#include "../../include/functions.h"
#include "../../include/structs.h"

char *cat_cpy(char *dest, char const *src)
{
    char *save = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src)) + 1);
    int i = 0;
    int j = 0;

    while (dest[i] != '\0') {
        save[i] = dest[i];
        i++;
    }
    while (src[j] != '\0') {
        save[i] = src[j];
        j++;
        i++;
    }
    save[i] = '\0';
    return save;
}

char *my_strcat(char *dest, char *src)
{
    char *new;

    if (dest == NULL)
        return (src);
    if (src == NULL)
        return (dest);
    new = cat_cpy(dest, src);
    return new;
}
