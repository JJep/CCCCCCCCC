#include "stdio.h"
#include "math.h"
void maxAndMin(){
	int m,n,markNum,i,max,min;
	markNum = -1;
	printf("请输入两个正整数,用空格隔开\n");
	scanf("%d %d",&m,&n);
	while (m<=0||n<=0) {
		printf("输入的数必须为正整数，请重新输入!\n");
		scanf("%d %d",&m,&n);
	}
	while (markNum == -1) {
		if (m<n) {
			markNum = n;
			n = m;
			m = markNum;
		}
		for (i = n, markNum = -1; i > 0; --i)
		{
			if (m%i == 0&&n % i == 0)
			{
				markNum = i;
				break;
			}
		}
	}
	max = markNum;
	min = (m / markNum) * n;
	printf("最大公约数为%d,最小公倍数为%d\n",max,min);
}
void primeNumber(){
	int a[10],number = 1000,i,j,flag = 0,result = 0;
	for (i = number-1; i > 0; i-=2)
	{
		for (j = 3; j <= (int)sqrt(i); j+=2)
		{
			if (i%j==0)
			{
				break;
			} else if (j==(int)sqrt(i))
			{
				a[flag] = i;
				flag++;
			}
		}
		if (flag > 9) break;
	}
	for (i = 0; i < 9; ++i)
	{	
		printf("%d+", a[i]);
		result += a[i];
	}
	printf("%d = %d\n", a[9], (result += a[9]));
}
void pai(){
	float pi,sum = 0;
	int n[] = {20,50,100,200};
	int i,j;
	for (i = 0; i < 4; ++i)
	{
		sum = 0;
		for (j = 1; j <= n[i]; ++j)
		{
			sum += (float)1/(j*j);
		}
		pi = sqrt(6*sum);
		printf("n=%d,pi=%f\n", n[i],pi);
	}
}
void SStirng(){
	int c, n, i,bigc,x;
    c=n=bigc=x=0;
    getchar();
    while(1)
    {
        i = getchar();
        if(i>='0' && i  <= '9') n++;
        else if((i>='a' && i  <= 'z'))
            c++;
        else if(i>='A' && i  <= 'Z')
        	bigc++;
        else if (i!='\n')
        	x++;
        else if(i=='\n') break;
    }
    printf("数字%d个，大写字母%d个，小写字母%d个，其他字符%d个\n", n,bigc,c,x);
}
int main(int argc, char const *argv[])
{
	//求最大公约数和最小公倍数
	maxAndMin();	

	//1000以内10个最大素数之和
	primeNumber();

	//求pi
	pai();

	//统计字符串中的数字根字母
	SStirng();
	return 0;
}