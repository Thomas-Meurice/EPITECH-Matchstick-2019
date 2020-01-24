/*
** EPITECH PROJECT, 2019
** eval_expr
** File description:
** {description}
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <matchstick.h>

int empty_map(match_t *match)
{
    int nb = 0;

    for (int i = 0; match->tab[i] != NULL; i++) {
        for (int j = 0; match->tab[i][j] != '\0'; j++)
            if (match->tab[i][j] == '|')
                nb++;
    }
    if (nb == 0)
        return (1);
    return (0);
}

int erreur_number_stick(match_t *match, int stick, char *str)
{
    if (match->nb_stick < match->stick) {
        my_putstr("Error: you cannot remove more than ");
        my_putstr(str);
        my_putstr(" matches per turn\n");
        return (1);
    }
    if (match->stick > stick) {
        my_putstr("Error: not enough matches on this line\n");
        return (1);
    }
    return (0);
}

int error_number_stick(match_t *match, char *str)
{
    int stick = 0;

    for (int i = 0; match->tab[match->pos][i] != '\0'; i++)
        if (match->tab[match->pos][i] == '|')
            stick++;
    if (match->nb_stick < 1) {
        my_putstr("Error: you have to remove at least one match\n");
        return (1);
    }
    if (erreur_number_stick(match, stick, str) == 1)
        return (1);
    return (0);
}