#include <stdio.h>
void swap(int *a, int *b);
void bubble(int a[], int l);
void printfArray(int a[], int l);

int main() {
	int a[] = {32,23,2,3,2,3,2,3,23,432,34,234,242343,342};
	printfArray(a, sizeof(a)/sizeof(a[0]));
	bubble(a, sizeof(a)/sizeof(a[0]));
	printfArray(a, sizeof(a)/sizeof(a[0]));
	return 0;
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
 * bubble sort min to max
 */
void bubble(int a[], int l) {
	for (int i = 0; i < l - 1; ++i)
	{
		for (int j = 0; j < l-i-1; j ++) {
			if (a[j] > a[j+1]) {
				swap(&a[j], &a[j+1]);
			}
		}
	}
}

/**
 * printf array 
 */
void printfArray(int a[], int l) {
	for (int i = 0; i < l; ++i)
	{
		if ( i == l-1) {
			printf("%d\n", a[i]);
		} else {
			printf("%d, ", a[i]);
		}
	}
}