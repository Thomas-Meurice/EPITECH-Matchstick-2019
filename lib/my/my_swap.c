/*
** EPITECH PROJECT, 2024
** CPool_Day3
** File description:
** Created by thomas.meurice@epitech.eu,
*/

#include "my.h"

int my_swap(int *a, int *b)
{
    int sto;

    sto = *a;
    *a = *b;
    *b = sto;

    return (0);
}