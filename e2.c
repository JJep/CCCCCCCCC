#include "stdio.h"
#include "string.h"
int main(int argc, char const *argv[])
{
	char a = 'C';
	char b = 'h';
	char c = 'i';
	char d = 'n';
	char e = 'a';
	printf("%c%c%c%c%c\n", a,b,c,d,e);

	a+=4;
	b+=4;
	c+=4;
	d+=4;
	e+=4;
	printf("%c%c%c%c%c\n", a,b,c,d,e);


	char a1 = 'T';
	char b1 = 'o';
	char c1 = 'd';
	char d1 = 'a';
	char e1 = 'y';
	printf("%c%c%c%c%c\n", a1,b1,c1,d1,e1);


	// printf("==================W = %d, Bw = %d\n", 'W', 'w');
	if (((int)a1 >= 87 && a1 <= 90) || ((int)a1 >= 119 && a1 <= 122))
	{
		a1-=22;
	}
	if (((int)b1 >= 87 && b1 <= 90) || ((int)b1 >= 119 && b1 <= 122))
	{
		b1-=22;
	}	
	if (((int)c1 >= 87 && c1 <= 90) || ((int)c1 >= 119 && c1 <= 122))
	{
		c1-=22;
	}
	if (((int)d1 >= 87 && d1 <= 90) || ((int)d1 >= 119 && d1 <= 122))
	{
		d1-=22;
	}
	if (((int)e1 >= 87 && e1 <= 90) || ((int)e1 >= 119 && e1 <= 122))
	{
		e1-=22;
	}

	a1+=4;
	b1+=4;
	c1+=4;
	d1+=4;
	e1+=4;
	printf("%c%c%c%c%c\n", a1,b1,c1,d1,e1);

	char p1 = 'P';
	char p2 = 'S';
	char p3 = 'Z';
	char p4 = 'I';
	printf("%c%c%c%c\n", p1,p2,p3,p4);
	p1-=4;
	p2-=4;
	p3-=4;
	p4-=4;
	printf("%c%c%c%c\n", p1,p2,p3,p4);
	
	return 0;	
}