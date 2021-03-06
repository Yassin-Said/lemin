/*
** EPITECH PROJECT, 2021
** my_strcpy
** File description:
** copy an str into an other one
*/

int my_strlen(char const *);

char *my_strcpy(char *dest, char const *src)
{
    int len = 0;
    int incr = 0;

    len = my_strlen(src);
    for (incr = 0; incr != len; incr++) {
        dest[incr] = src[incr];
    }
    dest[incr] = '\0';
    return (dest);
}
