/*
** EPITECH PROJECT, 2018
** my_strncmp
** File description:
** Thomas Meurice
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int nb;

    for (nb = 0; s1 && s1[0] != '\0' && s1[0] != '\n' && s1[nb] == s2[nb] &&
        nb <= n; nb++);
    return (s1[nb] - s2[nb]);
}