#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXBUF 100

int cmp_twisted(const void* a0, const void* a1) {
    int i0 = ((int*)a0)[0];
    int i1 = ((int*)a1)[0];
    return i0 < i1 ? -1 : i0 > i1 ? 1 : 0;
}

void twist37(char* s) {
    for (int i = 0, sz = strlen(s); i < sz; i++) {
        switch (s[i]) {
            case '3': s[i] = '7'; break;
            case '7': s[i] = '3'; break;
        }
    }
}

int* sortTwisted37(int* array, int arrayLength) {
    char buf[MAXBUF];
    int twisted[arrayLength][2];
    for (int i = 0; i < arrayLength; i++) {
        twisted[i][1] = array[i];
        sprintf(buf, "%d", array[i]);
        char* p = (char*)malloc(strlen(buf) + 1);
        strcpy(p, buf);
        twist37(p);
        twisted[i][0] = atoi(p);
        free(p);
    }

    qsort((void*)twisted, arrayLength, sizeof(twisted[0]), cmp_twisted);

    for (int i = 0; i < arrayLength; i++) {
        printf("%3d <= %3d\n", twisted[i][0], twisted[i][1]);
    }

    int* result = (int*)malloc(arrayLength * sizeof(int));
    for (int i = 0; i < arrayLength; i++) {
        result[i] = twisted[i][1];
    }

    return result;
}

int main(void) {
    int arrayLength = 18;
    int array[]    = {1,3,5,7,9,13,15,17,31,33,35,37,39,71,73,75,77,79};
    int expected[] = {1,7,5,3,9,17,15,13,71,77,75,73,79,31,37,35,33,39};
    // int arrayLength = 9;
    // int array[] = {1,2,3,4,5,6,7,8,9};
    // int expected[] = {1,2,7,4,5,6,3,8,9};
    int* actual1 = sortTwisted37(array, arrayLength);
    
    int is_same = 1;
    for (int i = 0; i < arrayLength; i++) {
        printf("%d ", actual1[i]);
        if (actual1[i] != expected[i]) {
            is_same = 0;
            break;
        }
    }
    printf("\n");
    printf("%s\n", is_same ? "YES!" : "NO");

    free(actual1);
    // assertArray(actual1, expected, 9);

    return 0;
}
