#include<stdio.h>
unsigned long long map[102][103];
//�������� 
int main(){
	 for(int i=0;i<=100;i++){
	 	map[i][0]=1;
	 }
	 for(int i=1;i<=100;i++){
	 	for(int j=1;j<=i;j++){
		 	map[i][j]=map[i-1][j-1]+map[i-1][j];
		 }
	 }
	//����һ�������������n��������m�� 
	//		printf("%llu\n",map[n][m]);
		
	
	
	return 0;
}
