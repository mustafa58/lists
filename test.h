//
// Created by mustafa58 on 25.09.2022.
//

#ifndef LISTS_TEST_H
#define LISTS_TEST_H
#define __EXCLUDED__

#define RUN XCAT(run_, CALL)
#define XCAT(a,b) CAT(a, b)
#define CAT(a, b) a ## b

#if defined(__BASE_FILE__) && !defined(__INCLUDED__)
#undef  TEST
#define TEST(name, ...) static void name();
#include __BASE_FILE__

int RUN(void) {
    void (*tests[])() = {
#       undef  TEST
#       define TEST(name, ...) name,
#       include __BASE_FILE__
    };
#define __INCLUDED__

    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int i;

    for (i = 0; i < num_tests; ++i) {
        /* stuff before test */
        (tests[i])();
        /* stuff after test */
    }

    return 0;
}
#endif //defined(__INCLUDED__)

#undef  TEST
#define TEST(name, ...) static void name() __VA_ARGS__

#undef __EXCLUDED__
#endif //LISTS_TEST_H
