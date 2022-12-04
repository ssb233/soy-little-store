#include<stdio.h>
long long low_mul(long long x,long long y,long long mod)
{
	long long sum=0;
	while(y)
	{
		if(y&1)
		sum=(sum+x)%mod;
		x=(x+x)%mod;
		y>>=1;
	}	
	return sum;
}
//对x*y拆分成为x+x+x。。。。，进行一个加速的取模，
long long quick_mul(long long base,long long power,long long p){
	long long result=1;
	scanf("%lld%lld%lld",&base,&power,&p);
		while(power)
		{
			if(power&1)//power%2==1
			result=(low_mul(result,base,p))%p;
			base=low_mul(base,base,p)%p;
				power>>=1;
		}
		return result;
}
 //base是底数，power是幂次，p是模数 
