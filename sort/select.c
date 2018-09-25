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


int main() {
	printf("选择排序\n");

	int a[] = {12, 2, 34, 213, 23};
	int l = 5;
	int t;

	printfArray(a, l);

	for (int i = 0; i < l-1; i ++) {
		int maxIndex = 0;
		for (int j = 1; j < l-i; j ++) {
			if (a[j] > a[maxIndex]) {
				maxIndex = j;
			}
		}
	// 交换
	t = a[maxIndex];
	a[maxIndex] = a[l-i-1];
	a[l-i-1] = t;
	}
	printfArray(a, l);	

	return 0;
}
