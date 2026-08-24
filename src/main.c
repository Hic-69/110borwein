/*
** EPITECH PROJECT, 2026
** 110borwein
** File description:
** main function
*/

#include "../include/borwein.h"

static void run_borwein(int n)
{
    double midpoint = integrate_midpoint(n, BORWEIN_LOWER_BOUND,
        BORWEIN_UPPER_BOUND, BORWEIN_SUBINTERVALS);
    double trapezoidal = integrate_trapezoidal(n, BORWEIN_LOWER_BOUND,
        BORWEIN_UPPER_BOUND, BORWEIN_SUBINTERVALS);

    display_result("Midpoint", n, midpoint);
    display_result("Trapezoidal", n, trapezoidal);
}

int main(int ac, char **av)
{
    int n;

    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        write_depend_on_output(1);
        return 0;
    }
    if (ac == 2 && parse_n(av[1], &n)) {
        run_borwein(n);
        return 0;
    }
    write_depend_on_output(2);
    return 84;
}
