/*
** EPITECH PROJECT, 2024
** CPool_Day3
** File description:
** Created by thomas.meurice@epitech.eu,
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

int my_putstr(char *str)
{
    int i = 0;

    if (str == NULL) {
        return (84);
    }
    while (str[i] != '\0') {
        write(1, &str[i], 1);
        i++;
    }
    return (0);
}