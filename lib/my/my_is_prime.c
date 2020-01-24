/*
** EPITECH PROJECT, 2024
** CPool_Day3
** File description:
** Created by thomas.meurice@epitech.eu,
*/

#include "my.h"

int my_is_prime(int nb)
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