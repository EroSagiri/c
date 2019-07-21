#include <stdio.h>
#include <string.h>
#define N 10

/**
 * 学生结构体
 */
typedef struct ss {
	char num[10];
	int s;
} STU;

/**
 * 打印学生成绩数组
 */
void printSTUS(STU *a);

/**
 * 通过参数返回学生数组中最少分数
 */
void fun(STU *a, STU *s);

int main() {
	STU a[N] = { {"A01", 76}, {"A02", 23}, {"A03", 64}, 
		{"A04", 83}, {"A05", 94}, {"A06", 73}, 
		{"A07", 84}, {"A08", 83}, {"A09", 73},
		{"A10", 43} };
	STU m;
	printf("**********原始数据**********\n");
	printSTUS(a);
	fun(a, &m);
	printf("最低分 学号=%s  成绩=%d\n", m.num, m.s);




	return 0;
}


void printSTUS(STU *a) {
	for(int i = 0; i < N; i ++) {
		printf("学号=%s 成绩=%d\n", a[i].num, a[i].s);
	}
}

void fun(STU *a, STU *s) {
	strcpy(s->num, a[0].num);
	s->s = a[0].s;
	for(int i = 0; i < N; i ++ ) {
		if (s->s > a[i].s) {
			strcpy(s->num, a[i].num);
			s->s = a[i].s;
		}
	}
}

