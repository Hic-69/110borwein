/*
** EPITECH PROJECT, 2026
** 110borwein
** File description:
** parsing and validating the n argument
*/

#include "../include/borwein.h"

bool parse_n(const char *str, int *out)
{
    char *end;
    long value;

    if (str[0] == '\0')
        return false;
    value = strtol(str, &end, 10);
    if (*end != '\0')
        return false;
    if (value < 0 || value > 2147483647)
        return false;
    *out = (int)value;
    return true;
}
