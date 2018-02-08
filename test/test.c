#include <stdio.h>
#include <string.h>

void assert_equals_str(char* actual, char* expected) {
    if (strcmp(actual, expected) == 0) {
        printf("OK\n");
    } else {
        printf("NG: '%s' expected, got '%s'\n", expected, actual);
    }
}
