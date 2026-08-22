/*
** EPITECH PROJECT, 2026
** 110boerwein
** File description:
** error cases handling and display help
*/

#include "../include/borwein.h"

bool display_help(int fd)
{
    dprintf(fd, "%s", "USAGE\n\t./110borwein n\n"
        "DESCRIPTION\n\tn constant defining he integral to be computed\n");
    return true;
}

bool write_depend_on_output(int fd)
{
    if (fd == 1) {
        display_help(fd);
        return true;
    }
    if (fd == 2) {
        display_help(fd);
        return false;
    } else {
        return false;
    }
}
