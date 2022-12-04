//////////////////////////////////////////
#include <stdio.h>
int main()
{
return 0;
}
//////////////////////////////////////////
int i, n;
scanf("%d", &n);
for(i = 0; i < n; i++)
{
}
//////////////////////////////////////////
int t;
scanf("%d", &t);
while(t--)
{
}
//////////////////////////////////////////
int t;
while(scanf("%d", &t) != EOF)
{
}
//////////////////////////////////////////
int n, m;
while(scanf("%d%d", &n, &m) != EOF)
{
}
//////////////////////////////////////////
// scanf
char : %c
short : %hd
int : %d
unsigned int: %u
long long : %lld
float : %f
double : %lf
// printf
char : %c
short : %hd
int : %d
unsigned int: %u
long long : %lld
float : %f
double : %f
//////////////////////////////////////////
char* s_gets(char * str)
{
int len;
gets(str);
len = strlen(str);
if(str[len - 1] == '\r')
{
str[len - 1] = '\0';
}
return str;
}
char* s_gets(char * str)
{
int ch;
int n = 0;
ch = getchar();
while(ch != '\n' && ch != EOF)
{
if(ch != '\r')
{
str[n++] = ch;
}
ch = getchar();
}
str[n] = '\0';
return str;
}
