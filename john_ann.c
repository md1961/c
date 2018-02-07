#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0

void print_llarray(char* name, long long* array, long long size);

long long* ann(long long n);

long long* john(long long n) {
    static long long* values = NULL;
    static long long size = 0;
    long long new_value;

    /*
    if (n >= 4) {
        printf("n = %d\n", n);
        print_llarray("johns", values, size);
        exit(1);
    }
    */

    /*
    printf("n = %d\n", n);
    print_llarray("johns", values, size);
    */

    if (n == 1) {
        new_value = 0;
    } else if (n <= size) {
        return values;
    } else {
        long long* johns_before = john(n - 1);
        long long john_before = johns_before[n - 2];

        if (DEBUG)
            printf("calling ann(%lld)...\n", john_before + 1);

        long long* anns_t = ann(john_before + 1);
        long long ann_t = anns_t[john_before];
        new_value = n - 1 - ann_t;
    }
    long long* result = (long long*)realloc(values, sizeof(long long) * ++size);
    result[size - 1] = new_value;
    values = result;

    if (DEBUG) {
        printf("n = %d\n", n);
        print_llarray("new johns", values, size);
    }

    return values;
}

long long sumJohn(long long n) {
    long long* johns = john(n);
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
        sum += johns[i];
    }
    free(johns);
    return sum;
}

long long* ann(long long n) {
    static long long* values = NULL;
    static long long size = 0;
    long long new_value;

    /*
    if (n >= 4) {
        printf("n = %d\n", n);
        print_llarray("anns", values, size);
        exit(1);
    }
    */

    /*
    printf("n = %d\n", n);
    print_llarray("anns", values, size);
    */

    if (n == 1) {
        new_value = 1;
    } else if (n <= size) {
        return values;
    } else {
        long long* anns_before = ann(n - 1);
        long long ann_before = anns_before[n - 2];

        if (DEBUG)
            printf("calling john(%lld)...\n", ann_before + 1);

        long long* johns_t = john(ann_before + 1);
        long long john_t = johns_t[ann_before];
        new_value = n - 1 - john_t;
    }
    long long* result = (long long*)realloc(values, sizeof(long long) * ++size);
    result[size - 1] = new_value;
    values = result;

    if (DEBUG) {
        printf("n = %d\n", n);
        print_llarray("new anns", values, size);
    }

    return values;
}

long long sumAnn(long long n) {
    long long* anns = ann(n);
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
        sum += anns[i];
    }
    //free(anns);
    return sum;
}


void print_llarray(char* name, long long* array, long long size) {
    printf("%s (%lld): ", name, size);
    for (long long i = 0; i < size; i++) {
        printf("%lld ", array[i]);
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    int n = 1;
    if (argc >= 2) {
        n = atoi(argv[1]);
    }

    /*
    long long* johns = john(n);
    long long* anns = ann(n);
    printf("\n");
    print_llarray("john: ", johns, n);
    print_llarray("ann:  ", anns , n);

    free(johns);
    free(anns);
    */

    // sum_john(75) -->  1720
    //printf("sum_john(78) = %lld\n", sumJohn(78));
    // sum_ann(150) -->  6930
    printf("sum_ann(150) = %lld\n", sumAnn(150));
    printf("sum_ann(75) = %lld\n", sumAnn(75));

    return 0;
}
