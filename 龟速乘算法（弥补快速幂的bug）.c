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
	
	//�䱾���Ƕ�x*yȡģ�����ǰ�����ֳ�x+x+x+x+x.....�ֱ�ȡģ�����ǲ�����һ�����٣�����λ�ļ��ټ��㣻 
	return 0;
}
