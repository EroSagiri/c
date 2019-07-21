#include <stdio.h>

void swap(int *a, int *b);
void selectSort(int a[], int l);
void printfArray(int a[], int l);

int main() {
	int a[] = {1, 2, 3, 3, 1, 21, 21, 4324, 32, 54, 23};
	printfArray(a, sizeof(a)/sizeof(a[0]));
	selectSort(a, sizeof(a)/sizeof(a[0]));
	printfArray(a, sizeof(a)/sizeof(a[0]));
}

/**
 * swap
 */
void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

/**
 * select sort min to max
 */
void selectSort(int a[], int l) {
	int minIndex;
	for (int i = 0; i < l-1; i ++) {
		minIndex = i;
		for (int j = i+1; j < l; j ++) {
			if (a[j] < a[minIndex]) {
				minIndex = j;
			}
		}
		swap(&a[i], &a[minIndex]);
	}
}

/**
 * printf array
 */
void printfArray(int a[], int l) {
	for (int i = 0; i < l; i ++) {
		if (i == l-1) {
			printf("%d\n", a[i]);
		} else {
			printf("%d, ", a[i]);
		}
	}
}