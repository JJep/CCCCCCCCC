#include "stdio.h"
#include "string.h"
#include "ctype.h"
char *rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
char *msg[] = {"is not a palindrome", "is a regular palindrome", "is a mirrored string", "is a mirrored palindrome"};
char r(char ch)
{
    if (isalpha(ch))
        return rev[ch - 'A'];
    else
        return rev[ch - 'A' + 42];
}
int main(int argc, char const *argv[])
{
    char s[100];
    while(scanf("%s", s) == 1)
    {
        int i;
        for (i = 0; s[i] != '\0'; ++i)
        {
            if (s[i] != s[strlen(s)-i-1]) break; //不是回文串
        }
        if (s[i]== '\0')    //是回文串
        {
            int i ;
            for ( i = 0; s[i] != '\0'; ++i)
            {
                if (s[i] != r(s[strlen(s)-1-i]) )    //不是镜像串
                {
                    printf("%s -- %s\n", s, msg[1]);
                    break;
                }
            }
            if (s[i] == '\0')
                printf("%s -- %s\n", s, msg[3]);//是镜像串
        }
        else
        {
            int i;
            for ( i = 0; s[i] != '\0'; ++i)
            {
                if (s[i] != r(s[strlen(s)-1-i]) ) //不是镜像串
                {
                    printf("%s -- %s\n", s, msg[0]);
                    break;
                }
            }
            if (s[i] == '\0')
                printf("%s -- %s\n", s, msg[2]); //是镜像串
        }
    }
    return 0;
}
