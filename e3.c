#include "stdio.h"
int main(int argc, char const *argv[])
{
	printf("请输入三个小写字母以空格隔开\n");
	char a1,a2,a3,aaa1,aaa2,aaa3,aa1,aa2,aa3,ch;
	scanf("%c %c %c", &a1, &a2, &a3);
	a1 = a1 - 32;
	a2 = a2 - 32;
	a3 = a3 - 32;
	printf("%c %c %c\n", a1, a2, a3);

	printf("请输入三个小写字母，输入完成后按回车键\n");
	ch = getchar();
	do
	{
		aa1 = getchar();
		aa2 = getchar();
		aa3 = getchar();
		aa1 = aa1 - 32;
		aa2 = aa2 - 32;
		aa3 = aa3 - 32;
	} while ((ch = getchar() ) != '\n');
	printf("%3c %3c %3c\n", aa1, aa2, aa3);

	printf("请输入三个小写字母，输入完成后按回车键\n");
	do
	{
		aaa1 = getchar();
		aaa2 = getchar();
		aaa3 = getchar();
		aaa1 = aaa1 - 32;
		aaa2 = aaa2 - 32;
		aaa3 = aaa3 - 32;
	} while ((ch = getchar()) != '\n');
	putchar(aaa1);
	putchar(aaa2);
	putchar(aaa3);
	printf("\n");
	return 0;
}