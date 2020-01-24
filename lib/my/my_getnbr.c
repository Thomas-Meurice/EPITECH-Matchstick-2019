/*
** EPITECH PROJECT, 2024
** CPool_Day3
** File description:
** Created by thomas.meurice@epitech.eu,
*/

#include "my.h"
#include <stdlib.h>

static int my_getnbr2(char const *str, int a, int *neg)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            a *= 10;
            a += str[i] - 48;
        }
        if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
            *neg = 1;
        if ((str[i] < '0' || str[i] > '9') &&
            (str[i - 1] >= '0' && str[i - 1] <= '9'))
            return (a);
        i++;
    }
    return (a);
}

int my_getnbr(char const *str)
{
    int a = 0;
    int neg = 0;

    if (str == NULL)
        return (84);
    a = my_getnbr2(str, a, &neg);
    return (a);
}
