#include<stdio.h>
void swap(int *a, int *b);
void printfArray(int a[], int l);
void reverseArray(int a[], int l);

int main() {
	int a[] = {1, 2, 332, 323, 2323, 323, 443};

	printfArray(a, sizeof(a)/sizeof(a[0]));
	reverseArray(a, sizeof(a)/sizeof(a[0]));
	printfArray(a, sizeof(a)/sizeof(a[0]));
}

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void reverseArray(int a[], int l) {
	if (l > 2 ) {
		for(int i =0; i < (l-1)/2; i ++) {
			swap(&a[i], &a[l-i-1]);
		}
	} else if (l == 2 ) {
		swap(&a[0], &a[1]);
	}
}

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