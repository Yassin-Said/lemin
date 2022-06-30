/*
** EPITECH PROJECT, 2022
** lemin
** File description:
** lemin
*/

#ifndef LEMIN_H
    #define LEMIN_H

typedef struct node {
    int x;
    int y;
    char *name;
    int passed;
    int min;
    int id;
    int *neighbor;
} node_t;

int error_cases_display(int res, char **text, node_t **all_node);
int display_elt(node_t **all_node, char **text);
int count_road(node_t *all_node, char **text);
int data_integrity(node_t **all_node, char **text);
int loop_invalid_command(char **text, int i);
int invalid_command(char **text);
char **get_command(char **text, int *found, int *id, int i);
char **get_elt(node_t **all_node, char **text, int *res);
char **get_file(char *buffer, size_t size, char **text);
int get_size(char **text);
void get_road(char **line, node_t **all_node, int i1, int i2);
char **erase_mid_hash(char **arr, int i);
char **erase_hash(char **arr);
char *erase_str_elt(char *str, int i);
char **clean_arr(char **text, int *i);
int struct_len(node_t **all_node);
int is_int(char *str);
char **my_arr_realloc(char **arr, int size);
int len_int_arr(int *int_arr);
int find_elt(node_t **all_node, char *text);
void display_array(char **text);
void fill_road(node_t **all_node, char **text);
int fill_elt(node_t **all_node, char **start_line, int id, int len);

#endif /* !LEMIN_H */
