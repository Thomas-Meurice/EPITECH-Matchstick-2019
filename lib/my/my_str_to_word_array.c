/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** Thomas Meurice
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

static int count_symbol(char const *str, char symbol)
{
    int count = 0;

    for (int nb = 0; str != NULL && str[nb] != '\0'; nb++)
        if (str[nb] == symbol)
            count++;
    count++;
    return (count);
}

int get_pos(char const *str, int nb, char symbol)
{
    int pos = 0;
    int nb_symbol = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (nb_symbol == nb) {
            pos = i;
            break;
        }
        if (str[i] == symbol)
            nb_symbol++;
    }
    return (pos);
}

int get_size(char const *str, char symbole)
{
    int nb = 0;

    while (str && str[nb] != symbole && str[nb] != '\0') {
        nb++;
    }
    return (nb);
}

char *get_str_and_dup(char const *str, int size, char symbol)
{
    char *dup = malloc(sizeof(char) * (size + 1));

    if (!dup)
        return (NULL);
    for (int i = 0; i < size; i++)
        if (str[i] != symbol)
            dup[i] = str[i];
    dup[size] = '\0';
    return (dup);
}

char **my_str_to_word_array(char const *str, char symbol)
{
    char **array = NULL;
    int nb_symbol = count_symbol(str, symbol);
    int pos = 0;
    int size = 0;

    if (str == NULL || str[0] == '\0' || str[0] == '\n')
        return (NULL);
    array = malloc(sizeof(char *) * (nb_symbol + 1));
    if (!array)
        return (NULL);
    for (int nb = 0; nb < nb_symbol; nb++) {
        pos = get_pos(str, nb, symbol);
        size = get_size(&str[pos], symbol);
        array[nb] = get_str_and_dup(&str[pos], size, symbol);
    }
    array[nb_symbol] = NULL;
    return (array);
}
