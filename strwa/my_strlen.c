/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** size_of_string
*/

int my_strlen_char(char *str, char c)
{
    int i = 0;

    while ((str[i] != '\0') && (str[i] != c))
        i++;
    return i;
}
