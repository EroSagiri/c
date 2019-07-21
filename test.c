#include <stdio.h>
#define N 4

void fun(int (*t)[N], int m) {
	for(int i = 0; i < N; i ++) {
		for(int j = N - m - 1; j >= 0; j --) {
			t[i][j+m] = t[i][j];
		}
		for(int j = 0; j < m ; j ++) {
			t[i][j] = 0;
		}
	}
}

void p(int (*t)[N]) {
	for(int i = 0; i < N; i ++) {
		for(int j = 0; j < N; j ++) {
			printf("%d\t", t[i][j]);
		}
		printf("\n");
	}
}
	


int main() {
	int t[][N] = {
		1, 2, 3, 4,
		5, 6, 7, 8,
		9,10,11,12,
		13,14,16,16
	};
	p(t);

	printf("输入向右位于距离\n");
	int m = -1;

	while(m <= 0 || m >= N) {
		scanf("%d", &m);
		if(m >= N ) {
			printf("m大于或等于%d\n", N);
		}
		if(m <= 0 ) {
			printf("小于或等于0\n");
		}
	}

	fun(t, m);
	p(t);


	return 0;
}
