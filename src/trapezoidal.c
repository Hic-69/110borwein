
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

    sum += sum_integrate(n, a, h, 1, steps, 0.0);
    return sum * h;
}

double sum_integrate(int n, double a, double h, int start, int end, double integ)
{
    int i = start;
    double sum = 0.0;

    for (; i < end; i++) {
        sum += f_n(n, a + (i + integ) * h);
    }
    return sum;
}
