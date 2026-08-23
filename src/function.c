/*
** EPITECH PROJECT, 2026
** 110borwein
** File description:
** the Borwein integrand f_n(x)
*/

#include "../include/borwein.h"

double f_n(int n, double x)
{
    double result = 1.0;
    int k;
    double t;
    double term;

    for (k = 0; k <= n; k++) {
        t = x / (2 * k + 1);
        if (t == 0.0)
            term = 1.0;
        else 
            term = sin(t) / t;
        result *= term;
    }
    return result;
}
