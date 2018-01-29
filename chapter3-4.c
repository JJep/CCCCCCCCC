#include "stdio.h"
int main(int argc, char const *argv[])
{
	int count = 0;
	// count = count++;
	printf("%d %d %d\n",count++, count++, count++);
	return 0;
}