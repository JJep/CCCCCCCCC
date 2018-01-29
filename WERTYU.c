#include "stdio.h"
char s[] = "1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
int main(int argc, char const *argv[])
{
	int i , c;
	while((c = getchar()) != EOF) {
		for ( i = 1; s[i] && s[i] != c; ++i);
			if (s[i])	putchar(s[i-1]);	
			else putchar(s[i]);
	}
	return 0;
}