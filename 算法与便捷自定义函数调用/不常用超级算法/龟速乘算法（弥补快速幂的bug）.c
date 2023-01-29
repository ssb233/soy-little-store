#include<stdio.h>
int main()
{
	long long base,power,p;
	long long result=1,result1=0;
	scanf("%lld%lld%lld",&base,&power,&p);
	
	long long power1=power;
	while(power1)
	{
		if(power1&1)//power%2==1
		result1=(result1+base)%p;
		power1>>=1;
		base=(base+base)%p; 
	}
	
	//其本质是对x*y取模，但是把它拆分成x+x+x+x+x.....分别取模，但是采用了一个加速，右移位的加速计算； 
	return 0;
}
