//输入字符串转为逆序数字；
 //逆序方便计算 
void deal_num_f(char *p1, char *p2, int len1, int len2) {

	for (int i = 0; i < len1 / 2; i++) {
		char tmp = *(p1 + i);
		*(p1 + i) = *(p1 + len1 - 1 - i);
		*(p1 + len1 - 1 - i) = tmp;
	}
	for (int i = 0; i < len2 / 2; i++) {
		char tmp = *(p2 + i);
		*(p2 + i) = *(p2 + len2 - 1 - i);
		*(p2 + len2 - 1 - i) = tmp;
	}//字符串翻转； 便于计算；
	 

	for (int i = 0; i < len1; i++) {
		num1[i] = s1[i] - '0';
	}
	for (int i = 0; i < len2; i++) {
		num2[i] = s2[i] - '0';//从字符转换到数字；
	}
}
//////////////////////////////////////////////////
///////////////////////////////////////////////
//把两个数字字符串逆序之后，这里是转化成了逆序数字相乘
//num_f[]里面存着逆序的相乘结果， 
void multiple_num(int *p1, int *p2, int len1, int len2) {
	for(int i=0;i<len1;i++){
		for(int j=0;j<len2;j++){
			int k=*(p1+i)*(*(p2+j));
			num_f[i+j]+=k%10;
			num_f[i+j+1]+=k/10;//先存取，不着急进位； 
			}
	}
	for(int i=0;i<len1+len2;i++){//位数一定为len1+len2或者len1+lne2-1;不妨取到len1+len2； 
	 if(num_f[i]>9){
	 	int tmp=num_f[i];
	 	num_f[i]=tmp%10;
	 	num_f[i+1]+=tmp/10;
	 }
	} 
}
/////////////////////////////////////////////////////
//加法 
void plus_num(int *p1, int *p2, int len1, int len2) {
	int len=len1>len2?len1:len2;
		for(int j=0;j<len;j++){
			int k=*(p1+j)+(*(p2+j));
		//先存取，不着急进位； 
	}
	for(int i=0;i<len;i++){//最后输出的时候可能要再考虑一位； 
	 if(num_f[i]>9){
	 	num_f[i]-=10;
	 	num_f[i+1]++;
	 }
	} 
}
//////////////////////////////////////
//减法，前提默认num1>=num2;//不然还需要额外处理，不过也简单； 
void minus_num(int *p1, int *p2, int len1, int len2) {
	int len=len1>len2?len1:len2;
		for(int j=0;j<len;j++){
			int k=*(p1+j)-(*(p2+j));
		//先存取，不着急进位； 
	}
	for(int i=0;i<len;i++){//最后输出的时候可能要再考虑一位； 
	 if(num_f[i]<0){
	 	num_f[i]+=10;
	 	num_f[i+1]--;
	 }
	} 
}
////////////////////////////////////



/////////////////////////////////////////
//将逆序数字颠倒，得到正序输出，同时跳过前导0； 
int flag=1;
	for(int i=len1+len2;i>=0;i--)//这里的长度，len1+len2肯定没问题，但是也可以根据运算法则做出相应改变 
	{
		if(num_f[i]==0&&flag==1){
			continue;//跳过前导0； 
		}
		flag=0;
		printf("%d",num_f[i]);
	}
	if(flag==1){
		printf("0");
	} 
//////////////////////////////////////////////
