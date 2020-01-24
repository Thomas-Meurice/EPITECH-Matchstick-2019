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

int verif_matches(match_t *match, char *str, char *matches)
{
    if (my_strlen(str) == 2 && str[0] == '0') {
        my_putstr("Error: you have to remove at least one match\n");
        return (1);
    }
    for (int i = 0; str[i] != '\n'; i++)
        if (str[i] < '0' || str[i] > '9') {
            my_putstr("Error: invalid input (positive number expected)\n");
            return (1);
        }
    match->stick = my_getnbr(str);
    if (error_number_stick(match, matches) == 1)
        return (1);
    return (0);
}

int verif_line(match_t *match, char *str)
{
    for (int i = 0; str[i] != '\n'; i++)
        if (str[i] < '0' || str[i] > '9') {
            my_putstr("Error: invalid input (positive number expected)\n");
            my_putstr("Line: ");
            return (1);
        }
    match->pos = my_getnbr(str);
    if (match->pos > match->x || match->pos < 1) {
        my_putstr("Error: this line is out of range\n");
        my_putstr("Line: ");
        return (1);
    }
    return (0);
}

int get(match_t *match, char *matches, size_t *size)
{
    my_putstr("\nYour turn:\nLine: ");
    if (getline(&match->str, size, stdin) == -1)
        return (1);
    while (verif_line(match, match->str) == 1)
        if (getline(&match->str, size, stdin) == -1)
            return (1);
    my_putstr("Matches: ");
    if (getline(&match->str1, size, stdin) == -1)
        return (1);
    while (verif_matches(match, match->str1, matches) == 1) {
        my_putstr("Line: ");
        if (getline(&match->str, size, stdin) == -1)
            return (1);
        while (verif_line(match, match->str) == 1)
            if (getline(&match->str, size, stdin) == -1)
                return (1);
        my_putstr("Matches: ");
        if (getline(&match->str1, size, stdin) == -1)
            return (1);
    }
    return (0);
}

int remove_stick_player(match_t *match)
{
    int i = match->x * 2 + 1;
    my_putstr("Player removed ");
    for (int i = 0; match->str1[i] != '\n'; i++)
        my_putchar(match->str1[i]);
    my_putstr(" match(es) from line ");
    my_putstr(match->str);
    for (; match->stick > 0; i--)
        if (match->tab[match->pos][i] == '|') {
            match->tab[match->pos][i] = ' ';
            match->stick--;
        }
    if (empty_map(match) == 1)
        return (1);
    return (0);
}

int game_loop(match_t *match, char *matches)
{
    size_t size;

    match->str = NULL;
    match->str1 = NULL;
    while (empty_map(match) != 1) {
        for (int i = 0; match->tab[i] != NULL; i++) {
            my_putstr(match->tab[i]);
            my_putchar('\n');
        }
        if (get(match, matches, &size) == 1) return (0);
        if (remove_stick_player(match) == 1) {
            print_map_empty(match);
            my_putstr("You lost, too bad...\n");
            return (2);
        } else if (remove_stick_ai(match) == 1) {
            print_map_empty(match);
            my_putstr("I lost... snif... but I'll get you next time!!\n");
            return (1);
        }
    }
    return (0);
}