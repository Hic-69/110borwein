/*
** EPITECH PROJECT, 2026
** 110borwein
** File description:
** midpoint rule integration
*/

#include "../include/borwein.h"

double integrate_midpoint(int n, double a, double b, int steps)
{
    double h = (b - a) / steps;
    double sum = 0.0;
    int i;

    for (i = 0; i < steps; i++)
        sum += f_n(n, a + (i + 0.5) * h);
    return sum * h;
}
