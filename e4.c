#include "stdio.h"
#include "math.h"
void rectangleSquare(){
	double a,b,c,m,s;
	printf("请分别输入三角形的三条边a,b,c。用空格键隔开\n");
	scanf("%lf %lf %lf", &a,&b,&c);
	while (a<=0||b<=0||c<=0||(a+b<=c)||(a+c<=b)||(b+c<=a)) {		//三条边应该都要大于0且任意两边只和大于第三边
		printf("请输入正确的边长！\n");
		scanf("%lf %lf %lf", &a,&b,&c);
	}
	
	m = (a+b+c)/2;
	s = sqrt(m*(m-a)*(m-b)*(m-c));
	printf("该三角形的面积为%.4lf\n", s);
}

void judgeInt() {
	int i;
	printf("请输入一个整数\n");
	scanf("%d",&i);
	if (i>0) 
	{
		printf("the number is greater than 0\n");    //如果i>0
	} else {
		printf("the number is less than or equal to 0\n");	//如果i<=0
	}
}

float functionalFunction() {
	float x;
	printf("请输入x的数值\n");
	scanf("%f",&x);
	if (x<2)
	{
		return x+1;
	} else if (x<4)
	{
		return (1+(x-2)*(x-2));
	} else {
		return ((x-2)*(x-2)+(x-1)*(x-1));
	}
}

void judgeRank() {
	int s;
	printf("请输入一个0~100整数成绩\n");
	scanf("%d",&s);
	switch(s/10){
		case 10:
		case 9:
			printf("该成绩的等级为A\n"); break;
		case 8:
			printf("该成绩的等级为B\n"); break;
		case 7:
			printf("该成绩的等级为C\n"); break;
		case 6:
			printf("该成绩的等级为D\n"); break;
		default:
			printf("该成绩的等级为E\n"); break;
	}

}
int main(int argc, char const *argv[])
{

	//求三角形的面积
	rectangleSquare();

	//判断整数类别
	judgeInt();

	//计算函数
	printf("%f\n", functionalFunction());

	//判断成绩
	judgeRank();
}
