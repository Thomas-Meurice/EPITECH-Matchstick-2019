/*
** EPITECH PROJECT, 2024
** CPool_Day3
** File description:
** Created by thomas.meurice@epitech.eu,
*/

#ifndef _MY_LS_H_
#define _MY_LS_H_

#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>

typedef struct match
{
    int x;
    int nb_stick;
    int pos;
    int stick;
    char **tab;
    char *str;
    char *str1;
} match_t;

#endif /* MY_LS_H */
