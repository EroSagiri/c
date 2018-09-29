#include <stdio.h>
// 打印数组
void printfArray(int a[],int l) {
	for (int i = 0; i < l; i ++) {
		if (i != l-1) {
			printf("%d, ", a[i]);
		} else {
			printf("%d\n", a[i]);
		}
	}

}

// 冒泡排序
int * bubbleSort(int a[], int l) {
	int i, j, t, count;
	for (i = 0; i < l; i ++) {
		count = 0;
		for (j = 0; j < l-i-1; j ++) {
			if (a[j] > a[j+1]) {
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
				count ++;
			}
		}
		if (count == 0)
			break;
	}

	return a;
}

int main() {
	printf("冒泡排序\n");
	int a[] = {50500, 23, 1000, 12, 45, 1, 15, 123, 23423, 1210};
	int l= 10;

	printfArray(a, l);
	printfArray(bubbleSort(a, l), l);
	return 0;
}
