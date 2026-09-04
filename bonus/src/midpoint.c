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
    quad_range_t range = {a, h, 0, steps};
    double sum = sum_integrate(n, &range, 0.5);

    return sum * h;
}
