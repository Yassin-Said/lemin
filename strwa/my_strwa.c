/*
** EPITECH PROJECT, 2022
** my_strwa
** File description:
** my_strwa
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
char *clean_string(char *src);
char *my_strcpy_char(char *dest, char const *src, char c);
int my_strlen_char(char *str, char c);
char *my_strdup(char const *src, char c);

int count_word(char *str, char c)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            count++;
    }
    return count;
}

char *my_str_c_dup(char *src, char c)
{
    char *str = NULL;

    if (src == NULL)
        return (NULL);
    str = malloc(sizeof(char) * (my_strlen_char(src, c) + 1));
    my_strcpy_char(str, src, c);
    return (str);
}

char **my_str_to_array(char *str, char c)
{
    int array_size = (count_word(clean_string(str), c) + 1);
    char **array = NULL;
    int i = 0;

    if ((str = clean_string(str)) == NULL)
        return NULL;
    array = malloc(sizeof(char *) * (array_size + 1));
    if (array == NULL)
        return NULL;
    for (; i < array_size; i++) {
        array[i] = my_str_c_dup(str, c);
        str += (my_strlen_char(str, c) + 1);
    }
    array[i] = NULL;
    return (array);
}
