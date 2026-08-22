/*
** EPITECH PROJECT, 2026
** 110borwein
** File description:
** unit tests for 110
*/

#include <criterion/criterion.h>
#include "../include/borwein.h"

Test(amazed, test_example)
{
    cr_assert(1 == 1);
}

Test(display_help, return_true)
{
    cr_assert(display_help());
}
