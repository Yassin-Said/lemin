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

int struct_len(node_t **all_node)
{
    int i = 0;

    if (!all_node)
        return (0);
    for (; all_node[i]; i++);
    return (i);
}

int is_int(char *str)
{
    int incr = 0;

    if (!str)
        return -1;
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' && str[i] > '9')
            incr++;
        if (incr == 1 && str[0] != '-' && i != 0 && my_strlen(str) == 1)
            return (-1);
    }
    return (0);
}

char **my_arr_realloc(char **arr, int size)
{
    int i = 0;
    char **new_arr = NULL;

    if (size < 1)
        return (NULL);
    if (!arr) {
        arr = malloc(sizeof(char *) * (size + 1));
        arr[size] = NULL;
        return (arr);
    }
    new_arr = malloc(sizeof(char *) * (size + 1));
    while (arr[i] != NULL) {
        new_arr[i] = malloc(sizeof(char) * (my_strlen(arr[i]) + 1));
        new_arr[i] = my_strcpy(new_arr[i], arr[i]);
        free(arr[i]);
        i++;
    }
    free(arr);
    new_arr[i] = NULL;
    return (new_arr);
}

int len_int_arr(int *int_arr)
{
    int i = 0;

    for (; int_arr[i] != -1; i++);
    return (i);
}

int find_elt(node_t **all_node, char *text)
{
    for (int i = 0; all_node[i]; i++) {
        if (my_strcmp(all_node[i]->name, text) == 0)
            return (i);
    }
    return (-1);
}
