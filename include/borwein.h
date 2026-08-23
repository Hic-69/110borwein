/*
** EPITECH PROJECT, 2026
** 110borwein
** File description:
** header and prototypes
*/

#ifndef BORWEIN_H_
    #define BORWEIN_H_

    #include <stdio.h>
    #include <stdbool.h>
    #include <string.h>
    #include <math.h>

bool display_help(int fd);
bool write_depend_on_output(int fd);
double f_n(int n, double x);
#endif /*BORWEIN_H_*/
