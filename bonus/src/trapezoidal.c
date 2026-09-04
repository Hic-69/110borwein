/*
** EPITECH PROJECT, 2026
** 110borwein
** File description:
** trapezoidal rule integration
*/

#include "../include/borwein.h"

double integrate_trapezoidal(int n, double a, double b, int steps)
{
    double h = (b - a) / steps;
    quad_range_t range = {a, h, 1, steps};
    double sum = (func_n(n, a) + func_n(n, b)) / 2.0;

    sum += sum_integrate(n, &range, 0.0);
    return sum * h;
}

double sum_integrate(int n, quad_range_t *range, double offset)
{
    int i = range->start;
    double sum = 0.0;

    for (; i < range->end; i++)
        sum += func_n(n, range->a + (i + offset) * range->h);
    return sum;
}
