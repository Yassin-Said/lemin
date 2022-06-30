/*
** EPITECH PROJECT, 2022
** lemin
** File description:
** display
*/
#include "my.h"
#include "lemin.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int display_elt(node_t **all_node, char **text)
{
    if (!text || !text[0] || is_int(text[0]) == -1 || my_getnbr(text[0]) <= 0)
        return (84);
    my_putstr("#number_of_ants\n");
    my_put_nbr(my_getnbr(text[0]));
    my_putchar('\n');
    my_putstr("#rooms\n");
    for (int i = 0; all_node[i]; i++) {
        if (all_node[i]->id == 1)
            my_putstr("##start\n");
        if (all_node[i]->id == 2)
            my_putstr("##end\n");
        my_putstr(all_node[i]->name);
        my_putchar(' ');
        my_put_nbr(all_node[i]->x);
        my_putchar(' ');
        my_put_nbr(all_node[i]->y);
        my_putchar('\n');
    }
    my_putstr("#tunnels\n");
    return (0);
}

int error_cases_display(int res, char **text, node_t **all_node)
{
    if (res == 84 || data_integrity(all_node, text) == 84)
        return (84);
    fill_road(all_node, text);
    if (display_elt(all_node, text) == 84)
        return (84);
    return (0);
}

void display_array(char **text)
{
    if (!text)
        return;
    for (int i = 0; text[i]; i++) {
        my_putstr(text[i]);
        my_putchar('\n');
    }
}
