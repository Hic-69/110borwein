/*
** EPITECH PROJECT, 2026
** 110borwein
** File description:
** display of a method's computed result
*/

#include "../include/borwein.h"

void display_result(const char *name, int n, double value)
{
    double diff = fabs(value - M_PI / 2.0);

    printf("%s:\n", name);
    printf("I%d = %.10f\n", n, value);
    printf("diff = %.10f\n", diff);
}
