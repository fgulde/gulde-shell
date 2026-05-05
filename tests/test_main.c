//
// Created by fguld on 5/4/2026.
//
#include <stddef.h>
#include <setjmp.h>
#include <stdarg.h>

#include <cmocka.h>
#include <stdio.h>
#include <stdlib.h>

#include "shell.h"

static char* execute_and_capture(const char* text) {
    char* captured_output = NULL;
    size_t captured_output_size = 0;
    FILE* captured_stream = open_memstream(&captured_output, &captured_output_size);
    assert_non_null(captured_stream);

    char input_buffer[256];
    const int written = snprintf(input_buffer, sizeof(input_buffer), "%s", text);
    assert_true(written >= 0);
    assert_true((size_t)written < sizeof(input_buffer));

    assert_int_equal(shell_execute_input(input_buffer, captured_stream), 0);
    assert_int_equal(fclose(captured_stream), 0);

    return captured_output;
}

static void test_unknown_command_outputs_not_found(void** state) {
    (void)state;
    char* output = execute_and_capture("foobar arg\n");
    assert_string_equal(output, "foobar: command not found\n");
    free(output);
}

static void test_echo_command_is_dispatched(void** state) {
    (void)state;
    char* output = execute_and_capture("echo hello world\n");
    assert_string_equal(output, "hello world\n");
    free(output);
}

static void test_whitespace_input_is_ignored(void** state) {
    (void)state;
    char* output = execute_and_capture("  \t   \n");
    assert_string_equal(output, "");
    free(output);
}

static void test_parser_handles_mixed_whitespace(void** state) {
    (void)state;
    char* output = execute_and_capture("echo one\ttwo   three\n");
    assert_string_equal(output, "one two three\n");
    free(output);
}

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_unknown_command_outputs_not_found),
        cmocka_unit_test(test_echo_command_is_dispatched),
        cmocka_unit_test(test_whitespace_input_is_ignored),
        cmocka_unit_test(test_parser_handles_mixed_whitespace),
    };
    return cmocka_run_group_tests(tests, nullptr, nullptr);
}