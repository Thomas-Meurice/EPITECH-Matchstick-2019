/*
** EPITECH PROJECT, 2018
** my_strncmp
** File description:
** Thomas Meurice
*/

#include <unistd.h>
#include "my.h"

int my_show_word_array(char *const *tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
        write(1, "\n", 1);
    }
    return (0);
}