//
// Created by fguld on 5/4/2026.
//
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

static void test_example(void **state) {
    (void)state; /* unused */
    assert_int_equal(1 + 1, 2);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_example),
    };
    return cmocka_run_group_tests(tests, nullptr, nullptr);
}