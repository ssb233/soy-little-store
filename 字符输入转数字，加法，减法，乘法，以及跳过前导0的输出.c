//�����ַ���תΪ�������֣�
 //���򷽱���� 
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
	}//�ַ�����ת�� ���ڼ��㣻
	 

	for (int i = 0; i < len1; i++) {
		num1[i] = s1[i] - '0';
	}
	for (int i = 0; i < len2; i++) {
		num2[i] = s2[i] - '0';//���ַ�ת�������֣�
	}
}
//////////////////////////////////////////////////
///////////////////////////////////////////////
//�����������ַ�������֮��������ת�����������������
//num_f[]��������������˽���� 
void multiple_num(int *p1, int *p2, int len1, int len2) {
	for(int i=0;i<len1;i++){
		for(int j=0;j<len2;j++){
			int k=*(p1+i)*(*(p2+j));
			num_f[i+j]+=k%10;
			num_f[i+j+1]+=k/10;//�ȴ�ȡ�����ż���λ�� 
			}
	}
	for(int i=0;i<len1+len2;i++){//λ��һ��Ϊlen1+len2����len1+lne2-1;����ȡ��len1+len2�� 
	 if(num_f[i]>9){
	 	int tmp=num_f[i];
	 	num_f[i]=tmp%10;
	 	num_f[i+1]+=tmp/10;
	 }
	} 
}
/////////////////////////////////////////////////////
//�ӷ� 
void plus_num(int *p1, int *p2, int len1, int len2) {
	int len=len1>len2?len1:len2;
		for(int j=0;j<len;j++){
			int k=*(p1+j)+(*(p2+j));
		//�ȴ�ȡ�����ż���λ�� 
	}
	for(int i=0;i<len;i++){//��������ʱ�����Ҫ�ٿ���һλ�� 
	 if(num_f[i]>9){
	 	num_f[i]-=10;
	 	num_f[i+1]++;
	 }
	} 
}
//////////////////////////////////////
//������ǰ��Ĭ��num1>=num2;//��Ȼ����Ҫ���⴦������Ҳ�򵥣� 
void minus_num(int *p1, int *p2, int len1, int len2) {
	int len=len1>len2?len1:len2;
		for(int j=0;j<len;j++){
			int k=*(p1+j)-(*(p2+j));
		//�ȴ�ȡ�����ż���λ�� 
	}
	for(int i=0;i<len;i++){//��������ʱ�����Ҫ�ٿ���һλ�� 
	 if(num_f[i]<0){
	 	num_f[i]+=10;
	 	num_f[i+1]--;
	 }
	} 
}
////////////////////////////////////



/////////////////////////////////////////
//���������ֵߵ����õ����������ͬʱ����ǰ��0�� 
int flag=1;
	for(int i=len1+len2;i>=0;i--)//����ĳ��ȣ�len1+len2�϶�û���⣬����Ҳ���Ը������㷨��������Ӧ�ı� 
	{
		if(num_f[i]==0&&flag==1){
			continue;//����ǰ��0�� 
		}
		flag=0;
		printf("%d",num_f[i]);
	}
	if(flag==1){
		printf("0");
	} 
//////////////////////////////////////////////
