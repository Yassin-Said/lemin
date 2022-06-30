/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** return the lenght of a string
*/
#include <stddef.h>
#include <stdio.h>

int my_strlen(char *str)
{
    int i;

    i = 0;
    if (str == NULL)
        return 0;
    while (str[i] != '\0')
        i++;
    return (i);
}
