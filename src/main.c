/*
** EPITECH PROJECT, 2026
** 110boerwein
** File description:
** main function
*/

#include "../include/borwein.h"

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        write_depend_on_output(1);
        return 0;
    } else {
        write_depend_on_output(2);
        return 84;
    }
}
