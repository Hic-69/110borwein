/*
** EPITECH PROJECT, 2026
** 110borwein
** File description:
** unit tests for 110
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/borwein.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(write_depend_on_output, stdout_returns_true)
{
    cr_assert_eq(write_depend_on_output(1), true);
}

Test(write_depend_on_output, stderr_returns_false)
{
    cr_assert_eq(write_depend_on_output(2), false);
}

Test(write_depend_on_output, unknown_fd_returns_false)
{
    cr_assert_eq(write_depend_on_output(42), false);
}

Test(parse_n, valid_zero)
{
    int out = -1;

    cr_assert_eq(parse_n("0", &out), true);
    cr_assert_eq(out, 0);
}

Test(parse_n, valid_positive)
{
    int out = -1;

    cr_assert_eq(parse_n("7", &out), true);
    cr_assert_eq(out, 7);
}

Test(parse_n, valid_large)
{
    int out = -1;

    cr_assert_eq(parse_n("2147483647", &out), true);
    cr_assert_eq(out, 2147483647);
}

Test(parse_n, empty_string_is_invalid)
{
    int out = 0;

    cr_assert_eq(parse_n("", &out), false);
}

Test(parse_n, negative_is_invalid)
{
    int out = 0;

    cr_assert_eq(parse_n("-1", &out), false);
}

Test(parse_n, trailing_chars_are_invalid)
{
    int out = 0;

    cr_assert_eq(parse_n("3abc", &out), false);
}

Test(parse_n, float_is_invalid)
{
    int out = 0;

    cr_assert_eq(parse_n("3.14", &out), false);
}

Test(parse_n, overflow_is_invalid)
{
    int out = 0;

    cr_assert_eq(parse_n("9999999999", &out), false);
}

Test(func_n, at_zero_is_one_for_n0)
{
    cr_assert_float_eq(func_n(0, 0.0), 1.0, 1e-12);
}

Test(func_n, at_zero_is_one_for_n5)
{
    cr_assert_float_eq(func_n(5, 0.0), 1.0, 1e-12);
}

Test(func_n, result_between_zero_and_one_for_small_x)
{
    double v = func_n(3, 0.5);

    cr_assert(v > 0.0 && v <= 1.0);
}

Test(func_n, n0_matches_sinc)
{
    double x = 1.0;
    double expected = sin(x) / x;

    cr_assert_float_eq(func_n(0, x), expected, 1e-12);
}

Test(integrate_midpoint, zero_interval_gives_zero)
{
    cr_assert_float_eq(integrate_midpoint(0, 1.0, 1.0, 1000), 0.0, 1e-12);
}

Test(integrate_midpoint, n0_converges_to_known_value)
{
    double val = integrate_midpoint(0, 0.0001, M_PI, 100000);

    cr_assert_float_eq(val, 1.8519, 1e-3);
}

Test(integrate_midpoint, positive_result_for_n1)
{
    double val = integrate_midpoint(1, 0.0001, 10.0, 10000);

    cr_assert(val > 0.0);
}

Test(integrate_trapezoidal, zero_interval_gives_zero)
{
    cr_assert_float_eq(integrate_trapezoidal(0, 2.0, 2.0, 1000), 0.0, 1e-12);
}

Test(integrate_trapezoidal, n0_converges_to_known_value)
{
    double val = integrate_trapezoidal(0, 0.0001, M_PI, 100000);

    cr_assert_float_eq(val, 1.8519, 1e-3);
}

Test(integrate_trapezoidal, positive_result_for_n2)
{
    double val = integrate_trapezoidal(2, 0.0001, 10.0, 10000);

    cr_assert(val > 0.0);
}

Test(integrate_simpson, zero_interval_gives_zero)
{
    cr_assert_float_eq(integrate_simpson(0, 3.0, 3.0, 1000), 0.0, 1e-12);
}

Test(integrate_simpson, n0_converges_to_known_value)
{
    double val = integrate_simpson(0, 0.0001, M_PI, 100000);
    cr_assert_float_eq(val, 1.8519, 1e-3);
}

Test(integrate_simpson, equals_weighted_average_of_mid_and_trap)
{
    int n = 2;
    double a = 0.0001, b = 5.0;
    int steps = 5000;
    double mid  = integrate_midpoint(n, a, b, steps);
    double trap = integrate_trapezoidal(n, a, b, steps);
    double simp = integrate_simpson(n, a, b, steps);
    double expected = (2.0 * mid + trap) / 3.0;

    cr_assert_float_eq(simp, expected, 1e-12);
}

Test(borwein, n0_integral_close_to_pi_over_2)
{
    double val = integrate_simpson(0, 0.0, BORWEIN_UPPER_BOUND, BORWEIN_SUBINTERVALS);

    cr_assert_float_eq(val, M_PI / 2.0, 1e-4);
}

Test(borwein, n6_integral_close_to_pi_over_2)
{
    double val = integrate_simpson(6, 0.0, BORWEIN_UPPER_BOUND, BORWEIN_SUBINTERVALS);

    cr_assert_float_eq(val, M_PI / 2.0, 1e-4);
}

Test(borwein, n7_integral_strictly_less_than_pi_over_2)
{
    double val = integrate_simpson(7, 0.0, BORWEIN_UPPER_BOUND, BORWEIN_SUBINTERVALS);

    cr_assert(val < M_PI / 2.0);
}
