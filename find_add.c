#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE -1

#define MAXBUF 1000

#define TARGET_VALUE 256

int main(void){
    char buf[MAXBUF];

    fgets(buf, sizeof(buf), stdin);
    int n = atoi(buf);

    int ints[n];
    fgets(buf, sizeof(buf), stdin);
    ints[0] = atoi(strtok(buf, " "));
    for (int i = 1; i < n; i++) {
        ints[i] = atoi(strtok(NULL, " "));
    }

    int is_found = FALSE;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ints[i] + ints[j] == TARGET_VALUE) {
                is_found = TRUE;
                break;
            }
        }
        if (is_found) {
            break;
        }
    }

    printf("%s\n", is_found ? "YES" : "NO");

    return 0;
}
