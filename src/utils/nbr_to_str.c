/*
** EPITECH PROJECT, 2024
** nbr_to_str
** File description:
** nbr_to_str
*/
#include "../../include/functions.h"

char *nbr_to_str(int nb)
{
    char *str = malloc(sizeof(char) * 8);
    int i = 0;

    if (nb < 0) {
        str[0] = '-';
        nb *= -1;
        i++;
    }
    if (nb == 0) {
        str[0] = '0';
        i ++;
    }
    for (; nb != 0; i++) {
        str[i] = nb % 10 + 48;
        nb /= 10;
    }
    str[i] = '\0';
    my_revstr(str);
    return str;
}
