/*
** EPITECH PROJECT, 2018
** my_strncmp
** File description:
** Thomas Meurice
*/

#include <unistd.h>
#include <stdlib.h>

char *my_strdup(char const *src)
{
    int nb = 0;
    char *dest = 0;
    int i = 0;

    while (src[nb] != '\0')
            nb++;
    dest = malloc(sizeof(char) * (nb + 1));
    if (dest == NULL)
        return (NULL);
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}