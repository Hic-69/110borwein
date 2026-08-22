/*
** EPITECH PROJECT, 2026
** 110borwein
** File description:
** unit tests for 110
*/

#include <criterion/criterion.h>
#include "../include/borwein.h"

Test(display_help, returns_true_on_stdout)
{
    cr_assert_eq(display_help(1), true);
}

Test(display_help, returns_true_on_stderr)
{
    cr_assert_eq(display_help(2), true);
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
