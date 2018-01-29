#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	int n= 0, count = 0;
	while(scanf("%d", &n) == 1 && n != 0)
	{
		int *num = (int *)malloc(sizeof(int) * n);
		for (int i = 0; i < n; ++i)
		  	scanf("%d",&num[i]);
		printf("Game %d:\n", ++count);
		int a=0,b=0,getN;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&getN);
			if (getN == num[i])
				a++;
			else
				for (int j = 0; j < n; ++j)
				{
					if (getN == num[j] && j != i)
					{	
						b++;
						break;
					}
				}
		}
		printf("(%d,%d)\n", a,b);
	}
	return 0;
}