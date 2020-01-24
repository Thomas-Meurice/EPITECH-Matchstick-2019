/*
** EPITECH PROJECT, 2024
** CPool_Day3
** File description:
** Created by thomas.meurice@epitech.eu,
*/

#include <unistd.h>

int my_isneg(int n)
{
    if (n > -1)
        write(1, "P\n", 2);
    else
        write(1, "N\n", 2);
    return (0);
}