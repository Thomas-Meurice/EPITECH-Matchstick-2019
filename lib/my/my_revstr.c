/*
** EPITECH PROJECT, 2024
** CPool_Day3
** File description:
** Created by thomas.meurice@epitech.eu,
*/

#include "my.h"

char *my_revstr(char *str)
{
    int i;
    int a;
    char c;

    for (i = 0; str[i] != '\0'; i++);
    i = i - 1;
    for (a = 0; i > a; a++) {
        c = str[i];
        str[i] = str[a];
        str[a] = c;
        i--;
    }
    return (str);
}