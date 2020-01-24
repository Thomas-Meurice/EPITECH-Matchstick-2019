/*
** EPITECH PROJECT, 2024
** CPool_Day3
** File description:
** Created by thomas.meurice@epitech.eu,
*/

#include "my.h"
#include <stdlib.h>

static char check(char *str, char const *to_find)
{
    int i = 0;

    while (str[i] == to_find[i]) {
        i++;
        if (to_find[i] == '\0')
            return (1);
    }
    return (0);
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;

    while (str[i] != '\0') {
        if (check(&str[i], to_find) == 1)
            return (&str[i]);
        i++;
    }
    return (NULL);
}