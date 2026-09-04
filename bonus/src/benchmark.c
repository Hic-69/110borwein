/*
** EPITECH PROJECT, 2026
** 110borwein
** File description:
** bonus: benchmark of the three integration methods
*/

#include <time.h>
#include "../include/borwein.h"

static const int bench_reps = 10;

static double simpson_naive(int n, double a, double b, int steps)
{
    double h = (b - a) / steps;
    double sum = func_n(n, a) + func_n(n, b);
    int i;

    for (i = 1; i < steps; i++)
        sum += func_n(n, a + i * h) * (i % 2 == 0 ? 2.0 : 4.0);
    return sum * h / 3.0;
}

static double time_method(double (*method)(int, double, double, int),
    int n, double *sink)
{
    clock_t start = clock();
    int r;

    for (r = 0; r < bench_reps; r++)
        *sink += method(n, BORWEIN_LOWER_BOUND, BORWEIN_UPPER_BOUND,
            BORWEIN_SUBINTERVALS);
    return (double)(clock() - start) / CLOCKS_PER_SEC * 1000.0 / bench_reps;
}

static void bench_line(const char *name,
    double (*method)(int, double, double, int), double *sink)
{
    int n_values[3] = {0, 5, 20};
    int j;

    printf("%-18s", name);
    for (j = 0; j < 3; j++)
        printf("  %9.3f ms", time_method(method, n_values[j], sink));
    printf("\n");
}

int main(void)
{
    double sink = 0.0;

    printf("Average time per full integration (%d reps, %d steps)\n\n",
        bench_reps, BORWEIN_SUBINTERVALS);
    printf("%-18s  %12s  %12s  %12s\n", "Method", "n=0", "n=5", "n=20");
    bench_line("Midpoint", &integrate_midpoint, &sink);
    bench_line("Trapezoidal", &integrate_trapezoidal, &sink);
    bench_line("Simpson naive", &simpson_naive, &sink);
    bench_line("Simpson (2M+T)/3", &integrate_simpson, &sink);
    printf("\n(checksum to keep the compiler honest: %.6f)\n", sink);
    return 0;
}
