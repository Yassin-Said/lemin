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

char **get_command(char **text, int *found, int *id, int i)
{
    if (my_strcmp(text[i], "##start") == 0) {
        text = pop_tab(text, i);
        *found = *found + 1;
        *id = 1;
    }
    if (my_strcmp(text[i], "##end") == 0) {
        text = pop_tab(text, i);
        *found = *found + 1;
        *id = 2;
    }
    return (text);
}

char **get_elt(node_t **all_node, char **text, int *res)
{
    int id = 0;
    int found = 0;
    int over = 0;
    char **start_line = NULL;
    int len = 0;

    for (int i = 1; text[i] && over != -1; i++) {
        len = struct_len(all_node);
        text = get_command(text, &found, &id, i);
        start_line = my_str_to_array(text[i], ' ');
        over = fill_elt(all_node, start_line, id, len);
        if (over == 0) {
            text = pop_tab(text, i);
            i--;
        }
        id = 0;
    }
    if (found != 2)
        *res = 84;
    return (text);
}

char **get_file(char *buffer, size_t size, char **text)
{
    int i = 0;

    while (getline(&buffer, &size, stdin) != -1) {
        if (buffer[my_strlen(buffer) - 1] == '\n')
            buffer = erase_str_elt(buffer, my_strlen(buffer) - 1);
        text = my_arr_realloc(text, i + 1);
        text[i] = malloc(sizeof(char) * (my_strlen(buffer) + 1));
        text[i] = my_strcpy(text[i], buffer);
        text[i + 1] = NULL;
        i++;
        size = 0;
    }
    return (text);
}

int get_size(char **text)
{
    int count = 0;
    char **line = NULL;

    for (int i = 1; text[i]; i++) {
        if (text[i][0] == '#')
            continue;
        line = my_str_to_array(text[i], ' ');
        if (!line || tab_len(line) != 3)
            return count;
        if (is_int(text[0]) != 0 && is_int(text[1])
            != 0 && is_int(text[2]) != 0)
            return count;
        count++;
    }
    return (count);
}

void get_road(char **line, node_t **all_node, int i1, int i2)
{
    int len = 0;
    int j = 0;

    for (j = 0; my_strcmp(line[i1], all_node[j]->name) != 0; j++);
    len = len_int_arr(all_node[j]->neighbor);
    all_node[j]->neighbor[len] = find_elt(all_node, line[i2]);
    all_node[j]->neighbor[len + 1] = -1;
}
