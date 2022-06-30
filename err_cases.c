/*
** EPITECH PROJECT, 2022
** lemin
** File description:
** err_cases
*/
#include "my.h"
#include "lemin.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int count_road(node_t *all_node, char **text)
{
    char **line = NULL;
    int nb_road = 0;

    for (int j = 0; text[j]; j++) {
        line = my_str_to_array(text[j], '-');
        if (my_strcmp(line[0], all_node->name) == 0 || my_strcmp(line[1],\
            all_node->name) == 0) {
            nb_road++;
        }
    }
    return (nb_road);
}

int data_integrity(node_t **all_node, char **text)
{
    char **line_fomated = NULL;

    if (!text || !all_node)
        return (84);
    for (int i = 1; text[i]; i++) {
        line_fomated = my_str_to_array(text[i], '-');
        if (!line_fomated || tab_len(line_fomated) != 2)
            return (84);
        if (find_elt(all_node, line_fomated[0]) == -1)
            return (84);
        if (find_elt(all_node, line_fomated[1]) == -1)
            return (84);
    }
    return (0);
}

int loop_invalid_command(char **text, int i)
{
    char **line = NULL;

    if (my_strcmp(text[i], "##end") == 0 || my_strcmp(text[i],\
        "##start") == 0) {
        if (!text[i + 1])
            return (84);
        line = my_str_to_array(text[i + 1], ' ');
        if (!line)
            return (84);
        if (tab_len(line) != 3)
            return 84;
        if (is_int(line[0]) != 0 || is_int(line[1])
            != 0 || is_int(line[2]) != 0)
            return (84);
    }
    return (0);
}

int invalid_command(char **text)
{
    for (int i = 0; text[i]; i++) {
        if (loop_invalid_command(text, i) == 84)
            return 84;
    }
    return (0);
}
