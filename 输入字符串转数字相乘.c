#include<stdio.h>
#include<string.h>
char s1[1005], s2[1005]; //存取每一位的字符
int num1[1005], num2[1005]; //将每一位字符转换为数字用于计算；
int num_f[2005];//存取最终位数；
void cal_num(int *p1, int *p2, int len1, int len2);

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

	cal_num(num1, num2, len1, len2);//去计算最终数字； 
}

int main() {
	scanf("%s%s", s1, s2); //输入字符型数字；
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	deal_num_f(s1, s2, len1, len2);
	int flag=1;
	for(int i=len1+len2;i>=0;i--)
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
	return 0;
}

void cal_num(int *p1, int *p2, int len1, int len2) {
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
