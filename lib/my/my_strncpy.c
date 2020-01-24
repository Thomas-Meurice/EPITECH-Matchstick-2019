/*
** EPITECH PROJECT, 2018
** my_strncmp
** File description:
** Thomas Meurice
*/

#include "my.h"
#include <stdlib.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    if (src == NULL || dest == NULL)
        return (0);
    while (src[i] != '\0' && n > i) {
        dest[i] = src[i];
        i++;
    }
    if (i < n)
        dest[i] = '\0';
    return (dest);
}