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
    #include <stdlib.h>

    #define BORWEIN_LOWER_BOUND 0.0
    #define BORWEIN_UPPER_BOUND 5000.0
    #define BORWEIN_SUBINTERVALS 10000

bool display_help(int fd);
bool write_depend_on_output(int fd);
double f_n(int n, double x);
bool parse_n(const char *str, int *out);
double integrate_midpoint(int n, double a, double b, int steps);
double integrate_trapezoidal(int n, double a, double b, int steps);
double integrate_simpson(int n, double a, double b, int steps);
void display_result(const char *name, int n, double value);
#endif /*BORWEIN_H_*/
