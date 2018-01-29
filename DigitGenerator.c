#include "stdio.h"
#include "string.h"
#define maxn 100005
int ans[maxn];
int main(int argc, char const *argv[])
{
	int T,n;
	memset(ans,0,sizeof(ans));
	for (int i = 0; i < maxn; ++i)
	{
		int x = i; int y = i;
		while(x > 0)
		{
			y += x % 10;
			x /= 10;
		}
		if (ans[y] == 0 || i < ans[y])
			ans[y] = i;
	}
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}
	return 0;
}