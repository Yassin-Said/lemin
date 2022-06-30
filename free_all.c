/*
** EPITECH PROJECT, 2022
** str_manipulation
** File description:
** free_all
*/
#include "my.h"
#include <stdlib.h>

void free_all(char **tab)
{
    if (!tab)
        return;
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}