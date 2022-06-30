/*
** EPITECH PROJECT, 2021
** allocates memory copies string
** File description:
** task01
*/

#include <unistd.h>
#include <stdlib.h>

char *my_strdup(char const *src, char c)
{
    char *str = NULL;

    if (src == NULL)
        return (NULL);
    str = malloc(sizeof(char) * (my_strlen_char(src, c) + 1));
    my_strcpy_char(str, src, c);
    return (str);
}
