/*
** EPITECH PROJECT, 2026
** 110borwein
** File description:
** Simpson's rule integration
*/

#include "../include/borwein.h"

double integrate_simpson(int n, double a, double b, int steps)
{
    double midpoint = integrate_midpoint(n, a, b, steps);
    double trapezoidal = integrate_trapezoidal(n, a, b, steps);

    return (2.0 * midpoint + trapezoidal) / 3.0;
}
