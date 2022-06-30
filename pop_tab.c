/*
** EPITECH PROJECT, 2021
** pop_tab
** File description:
** erase an element and he's emplacement on a array
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int tab_len(char **tab)
{
    int i = 0;

    if (!tab)
        return (0);
    for (; tab[i]; i++);
    return (i);
}

char **pop_tab(char **tab, int i)
{
    int incr = 0;
    int incr2 = 0;
    char **new_tab = malloc(sizeof(char *) * (tab_len(tab)));
    while (incr != tab_len(tab)) {
        if (incr != i) {
            new_tab[incr2] = malloc(sizeof(char) * (my_strlen(tab[incr]) + 1));
            new_tab[incr2] = my_strcpy(new_tab[incr2], tab[incr]);
            incr2++;
        }
        incr++;
    }
    new_tab[incr2] = NULL;
    return (new_tab);
}
