/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** Return the len of a string in parameter
*/
#include "../../include/functions.h"
#include "../../include/structs.h"

int my_strlen(char const *str)
{
    int index = 0;

    while (str[index] != '\0') {
        index++;
    }
    return index;
}

char *my_revstr(char *str)
{
    int j = my_strlen(str) - 1;
    int i = 0;
    int var = str[j];
    int divise = my_strlen(str) / 2;

    while (i < divise) {
        var = str[j];
        str[j] = str[i];
        str[i] = var;
        i++;
        j--;
    }
    return str;
}
