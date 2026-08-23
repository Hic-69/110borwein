/*
** EPITECH PROJECT, 2026
** 110borwein
** File description:
** main function
*/

#include "../include/borwein.h"

int main(int ac, char **av)
{
    int n;

    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        write_depend_on_output(1);
        return 0;
    }
    if (ac == 2 && parse_n(av[1], &n)) {
        return 0;
    }
    write_depend_on_output(2);
    return 84;
}
