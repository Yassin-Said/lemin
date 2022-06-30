/*
** EPITECH PROJECT, 2022
** clean_string
** File description:
** clean_string_without_malloc
*/

#include <stdlib.h>
#include <stdio.h>

int my_strlen_char(char *str, char c);

char *clean(char *str)
{
    if (!str)
        return (str);
    for (int i = 0; str[i]; i++) {
        if (str[i + 1] == '\0' && str[i] == ' ') {
            str[i] = '\0';
            i -= 2;
        }
    }
    return (str);
}

char *clean_string(char *src)
{
    char *tmp = NULL;
    int i = 0;
    int j = 0;

    if (src == NULL)
        return NULL;
    tmp = malloc(sizeof(char) * my_strlen_char(src, '\0') + 1);
    while (src[i] == ' ' || src[i] == '\t')
        i++;
    for (; src[i] != '\0'; i++) {
        if ((src[i] == ' ' || src[i] == '\t') && (src[i + 1] == ' ' ||
                    src[i + 1] == '\t')) {
        } else {
            tmp[j] = src[i];
            j++;
        }
    }
    tmp[j] = '\0';
    tmp = clean(tmp);
    return tmp;
}
