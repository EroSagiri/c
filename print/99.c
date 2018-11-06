#include <stdio.h>
int main() {
	printf("打印九九乘法表\n");
	for(int i = 1; i <= 9; i ++) {
		for(int j = 1; j <= 9; j++) {
			printf("%d*%d=%d\t", i, j, i*j);
		}
		printf("\n");
	}
}
