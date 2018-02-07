#include <stdio.h>
#include <stdlib.h>

void permutation(int *array, int length, int i, void (*func)(int *, int)) {
	int tmp;
	if (i == 0) {
		func(array, length);
	} else {
		permutation(array, length, i - 1, func);
		for (int j = i - 1; j >= 0; j--) {
			tmp = array[j]; array[j] = array[i]; array[i] = tmp;
			permutation(array, length, i - 1, func);
			tmp = array[j]; array[j] = array[i]; array[i] = tmp;
		}
	}
}

void print_array(int *array, int length) {
	for (int i = 0; i < length; i++) {
		printf("%3d", array[i]);
	}
	printf("\n");
}

int count = 0;

void count_up(int *pins, int length) {
	int sum0 = pins[0] + pins[1] + pins[2] + pins[3];
	int sum1 = pins[3] + pins[4] + pins[5] + pins[6];
	int sum2 = pins[6] + pins[7] + pins[8] + pins[0];
	if (sum0 == sum1 && sum1 == sum2) {
		count++;
	}
}

/*
void count_up2(int *pins, int length) {
	int sum0 = pins[0] + pins[1] + pins[2];
	int sum1 = pins[3] + pins[4] + pins[5];
	int sum2 = pins[6] + pins[7] + pins[8];
	int sum3 = pins[0] + pins[3] + pins[6];
	int sum4 = pins[1] + pins[4] + pins[7];
	int sum5 = pins[2] + pins[5] + pins[8];
	int sum6 = pins[0] + pins[4] + pins[8];
	int sum7 = pins[2] + pins[4] + pins[6];
	if (sum0 == sum1 && sum1 == sum2 && sum2 == sum3 && sum3 == sum4
		             && sum4 == sum5 && sum5 == sum6 && sum6 == sum7) {
		printf("%d %d %d\n", pins[0], pins[1], pins[2]);
		printf("%d %d %d\n", pins[3], pins[4], pins[5]);
		printf("%d %d %d\n", pins[6], pins[7], pins[8]);
		count++;
	}
}
*/


int main() {
	int pins[9];

	/*
	for (int i = 0; i < 9; i++) {
		pins[i] = i + 1;
	}

	permutation(pins, 9, 8, count_up2);
	printf("count = %d\n", count);

	exit(0);
	*/

	for (int ex = 1; ex <= 10; ex++) {
		int i = 0;
		for (int num = 1; num <= 10; num++) {
			if (num == ex) {
				continue;
			}
			pins[i++] = num;
		}

		permutation(pins, 9, 8, count_up);
	}
	printf("count = %d\n", count);

	return 0;
}
