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


int main() {
	// 冒泡排序小到大
	printf("冒泡排序\n");
	int a[] = {23, 12, 45, 1, 15};
	int l= 5;
	int t;

	printf("原始数组 : ");
	printfArray(a, l);
	
	for (int i = 0; i < l; i ++) {
		for (int j = 0; j < l-i-1; j ++) {
			if (a[j] > a[j+1]) {
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
		printf("第%d次排序: ", i);
		printfArray(a, l);
	}
	

	return 0;
}
