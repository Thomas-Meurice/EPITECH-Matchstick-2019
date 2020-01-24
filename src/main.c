/*
** EPITECH PROJECT, 2019
** eval_expr
** File description:
** {description}
*/

#include "my.h"
#include "matchstick.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char **fill_tab_part_two(char **tab, int nb)
{
    int nb1 = nb;
    int i = nb * 2 - 1;
    int count = 0;
    int start = 0;

    for (; nb1 > 0; nb1--) {
        for (int j = 0; j < i; i--, count++)
            tab[nb1][count + 1] = '|';
        start++;
        count = start;
        i = (nb * 2 - 1) - (start * 2);
    }
    return (tab);
}

char **fill_tab(char **tab, int x, int y)
{
    for (int i = 0; i < y; i++)
        tab[0][i] = '*';
    for (int i = 0; i < y; i++)
        tab[x - 1][i] = '*';
    for (int i = 1; i < x - 1; i++)
        for (int j = 0; j < y; j++)
            tab[i][j] = ' ';
    for (int i = 0; tab[i] != NULL; i++) {
        tab[i][0] = '*';
        tab[i][y - 1] = '*';
        tab[i][y] = '\0';
    }
    return (tab);
}

int error_management(int ac, char **av, int *nb, int *nb1)
{
    if (ac != 3)
        return (84);
    for (int j = 1; av[j] != NULL; j++)
        for (int i = 0; av[j][i] != '\0'; i++)
            if (av[j][i] < '0' || av[j][i] > '9')
                return (1);
    *nb = my_getnbr(av[1]);
    *nb1 = my_getnbr(av[2]);
    if (*nb < 1 || *nb > 99)
        return (1);
    if (*nb1 < 0)
        return (1);
    return (0);
}

int main(int ac, char **av)
{
    match_t *match = malloc(sizeof(match_t));
    int x = 0;
    int y = 0;
    int ret = 0;

    if (error_management(ac, av, &match->x, &match->nb_stick) == 1)
        return (84);
    x = match->x + 2;
    y = match->x * 2 + 1;
    match->tab = malloc(sizeof(char *) * (x + 1));
    for (int i = 0; i <= x; i++)
        match->tab[i] = malloc(sizeof(char) * (y + 1));
    match->tab[x] = NULL;
    match->tab = fill_tab(match->tab, x, y);
    match->tab = fill_tab_part_two(match->tab, match->x);
    ret = game_loop(match, av[2]);
    if (ret == 1)
        return (1);
    if (ret == 2)
        return (2);
    return (0);
}
