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
    double sum = (f_n(n, a) + f_n(n, b)) / 2.0;
    int i;

    for (i = 1; i < steps; i++)
        sum += f_n(n, a + i * h);
    return sum * h;
}
