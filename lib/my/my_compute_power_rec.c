/*
** EPITECH PROJECT, 2024
** CPool_Day3
** File description:
** Created by thomas.meurice@epitech.eu,
*/

int my_compute_power_rec(int nb, int p)
{
    int rep = 0;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    rep = nb * my_compute_power_rec(nb, p - 1);
    return (rep);
}