/*
** EPITECH PROJECT, 2024
** CPool_Day3
** File description:
** Created by thomas.meurice@epitech.eu,
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    int x = 1;

    while (x <= 46340 && (x * x) < nb)
        x++;
    if (x * x == nb)
        return (x);
    else
        return (0);
}