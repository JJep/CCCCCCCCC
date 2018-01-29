#include "stdio.h"
int main(int argc, char const *argv[])
{
	printf("请输入3个数字,用空格隔开\n");
	double a,b,c;
	scanf("%lf %lf %lf", &a, &b, &c);
	double sum;
	sum = a + b + c;
	double average = sum / 3;
	printf("他们的和为%.3f,平均值为%.3f。\n", sum, average);
	return 0;
}