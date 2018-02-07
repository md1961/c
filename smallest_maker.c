#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXBUF 100

int index_of_first_minimum(char* s) {
    int min = 10;
    int index_min = -1;
    for (int i = 0, sz = strlen(s); i < sz; i++) {
        int digit = s[i] - '0';
        if (digit < min) {
            min = digit;
            index_min = i;
        }
    }
    return index_min;
}

int index_of_first_larger_or_equal(char* s, int digit) {
    for (int i = 0, sz = strlen(s); i < sz; i++) {
        int d = s[i] - '0';
        if (d >= digit) {
            return i;
        }
    }
    return strlen(s);
}

void insert(char c, char* s, int index) {
    for (int i = strlen(s) - 1; i >= index; i--) {
        s[i + 1] = s[i];
    }
    s[index] = c;
}

void delete(char* s, int index) {
    for (int i = index, sz = strlen(s); i < sz; i++) {
        s[i] = s[i + 1];
    }
}

long long* smallest(long long n) {
    char strnum[MAXBUF];
    sprintf(strnum, "%lld", n);
    int index_min = index_of_first_minimum(strnum);
    int min = strnum[index_min] - '0';

    int i_from, i_to;
    long long min_number;
    if (min == 0) {
        // if '0' at s[1] -> mov s[0] to first larger.
        if (index_min == 1) {
            i_from = 0;
            char* strnum_from_index_1 = strnum + 1;
            i_to = index_of_first_larger_or_equal(strnum_from_index_1, strnum[0] - '0');
            insert(strnum[0], strnum_from_index_1, i_to);
            min_number = atoll(strnum + 1);
        // if '0' at s[2] or later -> move first of last '0's in a row to s[0].
        } else {
            i_from = strlen(strnum) - 1;
            while (strnum[i_from] != '0') {
                i_from--;
            }
            while (strnum[i_from - 1] == '0') {
                i_from--;
            }
            i_to = 0;
            delete(strnum, i_from);
            min_number = atoll(strnum);
        }
    // if smallest at s[0] -> move next smallest to s[1],
    // and if next smallest at s[1], move next next smallest to s[2], and so on.
    } else if (index_min == 0) {
        int index_min2;
        int offset = 1;
        while (1) {
            char* strnum_sub = strnum + offset;
            index_min2 = index_of_first_minimum(strnum_sub);
            if (index_min2 != 0) {
                break;
            }
            offset++;
        }
        if (index_min2 == -1) {
            i_from = 0;
            i_to = 0;
        } else {
            i_from = index_min2 + offset;
            char digit = strnum[i_from];
            i_to = index_of_first_larger_or_equal(strnum, digit - '0');
            delete(strnum, i_from);
            insert(digit, strnum, offset);
        }
        min_number = atoll(strnum);
    // if smallest at s[1] -> move s[0] to its next largest or equal.
    } else if (index_min == 1) {
        i_from = 0;
        char digit = strnum[i_from];
        delete(strnum, i_from);
        i_to = index_of_first_larger_or_equal(strnum, digit - '0');
        insert(digit, strnum, i_to);
        min_number = atoll(strnum);
    // if smallest at s[2] or later -> move it to s[0].
    } else {
        i_from = index_min;
        i_to = 0;
        char digit = strnum[i_from];
        delete(strnum, i_from);
        insert(digit, strnum, 0);
        min_number = atoll(strnum);
    }

    long long* result = (long long*)malloc(sizeof(long long) * 3);
    result[0] = min_number;
    result[1] = i_from;
    result[2] = i_to;
    return result;
}

void dotest(long long n, char* expected) {
    long long* actual = smallest(n);
    char buf[MAXBUF];
    sprintf(buf, "%lld, %d, %d", actual[0], actual[1], actual[2]);
    if (strcmp(buf, expected) == 0) {
        printf("OK\n");
    } else {
        printf("NG: n = %lld, expected '%s', got '%s'\n", n, expected, buf);
    }
    free(actual);
}

int main(void) {
    dotest(261235, "126235, 2, 0");
    dotest(209917, "29917, 0, 1");
    dotest(285365, "238565, 3, 1");
    dotest(296837, "239687, 4, 1");
    dotest(1000000, "1, 0, 6");

    dotest(120917, "12917, 2, 0");
    dotest(235465, "234565, 3, 2");
    dotest(234665, "234566, 5, 3");

    dotest(187863002809, "18786300289, 10, 0");
    dotest(199819884756, "119989884756, 4, 0");
    dotest(935855753, "358557539, 0, 8");
    dotest(123456789, "123456789, 0, 0");
    dotest(111111111000, "11111111100, 9, 0");

    return 0;
}
