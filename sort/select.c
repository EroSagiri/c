#include <stdio.h>
// 打印数组
void printfArray(int a[], int l) {
	for(int i =0; i < l; i ++) {
		if (i != l-1) {
			printf("%d, ", a[i]);
		} else {
			printf("%d\n", a[i]);
		}
	}
}

// 选择排序
int * selectSort(int a[], int l) {
	int i, j, maxIndex, t;
	
	for (i = 0; i < l-1; i ++) {
		maxIndex = 0;
		for (j = 1; j < l-i; j ++) {
			if (a[j] > a[maxIndex])
				maxIndex = j;
		}

		t = a[maxIndex];
		a[maxIndex] = a[l-i-1];
		a[l-i-1] = t;
	}

	return a;
}

int main() {
	printf("选择排序\n");

	int a[] = {12, 2, 34, 213, 23};
	int l = 5;
	int t;

	printfArray(a, l);
	printfArray(selectSort(a, l), l);
	return 0;
}
