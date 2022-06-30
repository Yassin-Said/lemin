/*
** EPITECH PROJECT, 2022
** lemin
** File description:
** erase_elt
*/
#include "my.h"
#include "lemin.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int len_tab(char **arr)
{
    int i = 0;

    for (; arr[i]; i++);
    return (i);
}

char **erase_mid_hash(char **arr, int i)
{
    for (int j = 0; arr[i][j] != '\0'; j++) {
        if (arr[i][j] == '#' && my_strcmp(arr[i], "##start")
            != 0 && my_strcmp(arr[i], "##end") != 0)
            arr[i][j] = '\0';
    }
    return (arr);
}

char **erase_hash(char **arr)
{
    int i = 0;

    while (arr[i]) {
        if (arr[i][0] == '#' && arr[i][1] != '#') {
            arr = pop_tab(arr, i);
            i--;
        } else {
            arr = erase_mid_hash(arr, i);
        }
        i++;
    }
    return (arr);
}

char *erase_str_elt(char *str, int i)
{
    int k = 0;
    char *new_str = NULL;

    if (!str || my_strlen(str) <= i)
        return (str);
    new_str = malloc(sizeof(char) * my_strlen(str));
    if (new_str == NULL)
        return (new_str);
    for (int j = 0; str[j] != '\0'; j++) {
        if (j != i) {
            new_str[k] = str[j];
            k++;
        }
    }
    free(str);
    new_str[k] = '\0';
    return (new_str);
}

char **clean_arr(char **text, int *i)
{
    if (text[*i][0] == '\n' || text[*i][0] == '\0') {
        text = pop_tab(text, *i);
        *i = *i - 1;
    }
    return (text);
}
