/*
** EPITECH PROJECT, 2022
** lemin
** File description:
** anthills
*/
#include "my.h"
#include "lemin.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int fill_elt(node_t **all_node, char **start_line, int id, int len)
{
    if (!start_line || tab_len(start_line) != 3)
        return -1;
    all_node[len] = malloc(sizeof(node_t));
    for (int i = 0; start_line[i]; i++) {
        if (is_int(start_line[i]) == -1)
            return -1;
    }
    all_node[len]->x = my_getnbr(start_line[1]);
    all_node[len]->y = my_getnbr(start_line[2]);
    all_node[len]->name = malloc(sizeof(char) * my_strlen(start_line[0]) + 1);
    all_node[len]->name = my_strcpy(all_node[len]->name, start_line[0]);
    all_node[len]->id = id;
    all_node[len]->min = 0;
    all_node[len]->passed = 0;
    all_node[len + 1] = NULL;
    return (0);
}

void fill_road(node_t **all_node, char **text)
{
    char **line = NULL;
    int nb_road = 0;

    for (int i = 0; all_node[i]; i++) {
        nb_road = count_road(all_node[i], text);
        all_node[i]->neighbor = malloc(sizeof(int) * (nb_road + 1));
        all_node[i]->neighbor[0] = -1;
    }
    for (int i = 1; text[i]; i++) {
        line = my_str_to_array(text[i], '-');
        get_road(line, all_node, 0, 1);
        get_road(line, all_node, 1, 0);
    }
}

char **set_data(char **text, int *nb_node)
{
    char *buffer = NULL;
    size_t size = 0;

    text = get_file(buffer, size, text);
    if (!text)
        return (NULL);
    for (int i = 0; text[i] != NULL; i++)
        text = clean_arr(text, &i);
    text = erase_hash(text);
    if (invalid_command(text) == 84)
        return (NULL);
    *nb_node = get_size(text);
    if (*nb_node == 0)
        return NULL;
    return (text);
}

int main(int ac, char **av)
{
    int res = 0;
    char **text = NULL;
    node_t **all_node = NULL;
    int nb_node = 0;

    (void)av;
    if (ac != 1 || (text = set_data(text, &nb_node)) == NULL)
        return 84;
    all_node = malloc(sizeof(node_t *) * (nb_node + 1));
    all_node[0] = NULL;
    text = get_elt(all_node, text, &res);
    if (error_cases_display(res, text, all_node) == 84)
        return (84);
    text = pop_tab(text, 0);
    display_array(text);
    my_putstr("#moves\n");
    free_all(text);
    return (0);
}
