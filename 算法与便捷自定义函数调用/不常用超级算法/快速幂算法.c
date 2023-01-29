#include<stdio.h>
int main()
{
	long long base,power,p;
	long long result=1;
	scanf("%lld%lld%lld",&base,&power,&p);
	while(power)
	{
		if(power&1)//power%2==1
		result=result*base%p;
		power>>=1;
		base=(base*base)%p;
	}
	printf("%lld",result);
	return 0;
}
