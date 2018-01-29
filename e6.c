#include "stdio.h"
#include "string.h"
void charStr(){
	char str[20];
	strcpy(str,"fwahuihfawui");
	printf("请输入单个字符来匹配\n");
	char c;
	int i;
	scanf("%c", &c);
	for (i = 0; i < 19; ++i)
	{
		if (c == str[i])
		{
			printf("字符%c在字符串%s中第一次出现的位置是第%d个\n", c,str,i);
			break;
		}
	}
	if (i == 19)
	{
		printf("字符串%s中没有该字符。\n", str);
	}
}
void matrix(){
	int n;
	printf("请输入n的数值\n");
	scanf("%d", &n);
	int a[10][10];
	int max,min,mini,maxi;
	int b[n];
	printf("请逐个输入数组中的数值\n");
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &a[i][j]);
		}
	}
	max = min = a[0][0];
	mini = 0, maxi = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%d ", a[i][j]);
			if (min > a[i][j])
			{
				min = a[i][j];
				mini = i;
				printf("mimi = %d\n", mini);
			}
			if (max < a[i][j])
			{
				max = a[i][j];
				maxi = i;
			}
		}
		printf("\n");
	}
	printf("含有最小数的行是第%d行，含有最大数的行是第%d行\n变换后的二维数组为\n", mini+1,maxi+1);
	printf("min = %d, max = %d\n", min,max);
	for (int i = 0; i < n; ++i){
		b[i] = a[maxi][i];
		a[maxi][i] = a[mini][i];
		a[mini][i] = b[i];
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

void bubblePaixu(int *a, int num){
	int n = a[0];
	for (int i = 0; i < num; ++i)
	{
		for (int j = i; j < num; ++j)
		{	
			if (a[i]>=a[j])
			{
				int number = a[i];
				a[i] = a[j];
				a[j] = number;
			}
		}
	}
}

int search(int *a,int number, int target){
	for (int i = 0; i < number; ++i)
	{
		if (target == a[i])
		{
			return i+1;
		}
	}
	return 0;
}
void searchNumber() {
	int a[] = {5,6,3,2,4,1,7,8,9,10,11,54,65,32,21,43,100,98,40,76};
	printf("原数组为 ");
	for (int i = 0; i < 20; ++i)
	{
		printf("%d ", a[i]);
		if (i == 19)
			printf("\n");
	}
	bubblePaixu(a,20);
	printf("排序后为 ");
	for (int i = 0; i < 20; ++i)
	{
		printf("%d ", a[i]);
		if (i == 19)
			printf("\n");
	}
	printf("\n");
	int target;
	printf("请输入要查找的数值\n");
	scanf("%d", &target);
	if (search(a, 20, target)!=0)
	{
		printf("在数组中的第%d个位置\n", search(a, 20, target));
	} else {
		printf("Not Found\n");
	}
}
void input(float student[4][5], int numberi, int numberj){
	for (int i = 0; i < numberi-1; ++i)
	{
		for (int j = 0; j < numberj-1; ++j)
		{
			if (j == 0)
			{
				printf("请输入第%d个学生的成绩\n", i+1);
			}
			scanf("%f",&student[i][j]);
		}
	}
}
void compute(float student[4][5], int numberi, int numberj) {
	for (int i = 0; i < numberi-1; ++i)
	{
		float max = 0;
		for (int j = 0; j < numberj-1; ++j)
		{
			max += student[i][j];
		}
		student[i][numberj-1] = max;
	}
	for (int j = 0; j < numberj-1; ++j)
	{
		float max = 0;
		for (int i = 0; i < numberi -1; ++i)
		{
			max += student[i][j];
		}
		student[numberi-1][j] = max/(numberi-1);
	}
}
void output(float student[4][5], int numberi, int numberj){
	for (int i = 0; i < numberi; ++i)
	{
		for (int j = 0; j < numberj; ++j)
		{
			printf("%.2f ", student[i][j]);
		}
		printf("\n");
	}
}
void student() {
	float student[4][5];

	input(student, 4, 5);
	compute(student, 4, 5);
	output(student, 4, 5);
}
void catStr(char str1[],char str2[]){
	int i = 0,j = 0;
	while (str1[i] != '\0'){
		i++;
	}
	while(str2[j] != '\0'){
		str1[i]=str2[j];
		i++;
		j++;
	}
	str1[i]='\0';
	printf("%s\n", str1);
}
int lenStr(char str[]){
	int i = 0;
	while (str[i]!='\0'){
		i++;
	}
	return i;
}
void stringFunc(){
	char str1[100] = "abcdefg";
	char str2[100] = "ABCDEFG";
	printf("%s\n", str1);
	printf("%s\n", str2);
	printf("%d\n", lenStr(str1));
	printf("%d\n", lenStr(str2));
	catStr(str1, str2);
	printf("%s\n", str1);
	printf("%d\n", lenStr(str1));
}
int main(int argc, char const *argv[])
{
//	在字符串中查找字符.
	printf("\n");
	printf("在字符串中查找字符.\n");
	charStr();	

	//二维数组变换
	printf("\n");
	printf("二维数组变换\n");
	matrix();

	//折半查找
	printf("\n");
	printf("折半查找\n");
	searchNumber();

	//学生成绩
	printf("\n");
	printf("学生成绩\n");
	student();

	//字符串
	printf("\n");
	printf("字符串\n");
	stringFunc();

	return 0;
}
