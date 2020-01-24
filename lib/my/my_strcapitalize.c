/*
** EPITECH PROJECT, 2024
** CPool_Day3
** File description:
** Created by thomas.meurice@epitech.eu,
*/

#include "my.h"

char *my_strcapitalize(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] >= 'a' && str[i] <= 'z') &&
            ((str[i - 1] == ' ' || str[i - 1] == '\t') || i == 0)) {
            str[i] = str[i] - ('a' - 'A');
        }
        i++;
    }
    return (str);
}