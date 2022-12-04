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
//��x*y��ֳ�Ϊx+x+x��������������һ�����ٵ�ȡģ��
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
 //base�ǵ�����power���ݴΣ�p��ģ�� 
