int num_front[20];//对应的下标是指数，对应的数值是系数；
int i=0;
//这是对一个数字进行转换成k进制下的数字，
//数组低位置存取数字的低位；
//输出的时候记得做一些变换； 
void deal_rule(int n,int k){
	if(n==0){
		return;
	}
	num_front[i++]=n%k;
	n/=k;
	return deal_rule(n,k);
}
