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

void print_map_empty(match_t *match)
{
    for (int i = 0; match->tab[i] != NULL; i++) {
        my_putstr(match->tab[i]);
        my_putchar('\n');
    }
}

int verif_stick_ai(char *str)
{
    int i = 0;

    for (int nb = 0; str[nb] != '\0'; nb++)
        if (str[nb] == '|')
            i++;
    if (i > 0)
        return (1);
    return (0);
}

void ia_part_two(match_t *match, int nb, int i, int count)
{
    int l = 0;

    for (; match->tab[nb][i] != '\0'; i++);
    for (; i > 0; i--)
        if (match->tab[nb][i] == '|' && count < match->nb_stick) {
            match->tab[nb][i] = ' ';
            count++;
        }
    if (empty_map(match) == 1 && count > 1) {
        l = (match->x - nb) + 1;
        match->tab[nb][l] = '|';
    }
    my_putstr("AI removed ");
    my_put_nbr(count);
    my_putstr(" match(es) from line ");
    my_put_nbr(nb);
    my_putchar('\n');
}

int remove_stick_ai(match_t *match)
{
    int nb = 0;
    int i = 0;
    int count = 0;

    for (int i = 0; match->tab[i] != NULL; i++) {
        my_putstr(match->tab[i]);
        my_putchar('\n');
    }
    my_putstr("\nAI's turn...\n");
    for (; match->tab[nb] != NULL; nb++) {
        if (verif_stick_ai(match->tab[nb]) == 1)
            break;
    }
    ia_part_two(match, nb, i, count);
    if (empty_map(match) == 1)
        return (1);
    return (0);
}
