/*
** EPITECH PROJECT, 2024
** CPool_Day3
** File description:
** Created by thomas.meurice@epitech.eu,
*/

#include "my.h"

static int my_prime(int nb)
{
    int i = 2;

    if (nb == 1)
        return (0);
    while (i != nb) {
        if (nb % i == 0)
            return (0);
        i++;
    }
    if (i == nb)
        return (1);
}

int my_find_prime_sup(int nb)
{
    if (nb < 0)
        return (2);
    while (my_prime(nb) != 1) {
        nb++;
    }
    return (nb);
}