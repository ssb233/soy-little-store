#include<stdio.h>
char map[200][200];
int n;
int x_1,y_1, x_2, y_2;
void compass(int x1,int y1,int x2,int y2);
void f_printf();
void find_up();
void find_down();
void find_left();
void find_right(); 
void loop(int flag){
	if(x_1==x_2&&y_1==y_2){//�ݹ������������ 
		f_printf();
	}
	//����һ��ȷ���ĵ�ֻ��Ҫ����������һ�ξ��У� 
	if(flag!=2)//�����ϴε��෴�� 
	find_up();
	if(flag!=1)//�����ϴε��෴�� 
	find_down();
	if(flag!=4)//�����ϴε��෴�� 
	find_left();
	if(flag!=3)//�����ϴε��෴�� 
	find_right();
}
int main(){
	
	scanf("%d",&n);
	int x1,x2,y1,y2;
	scanf(" %d%d%d%d",&x1,&y1,&x2,&y2);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf(" %c",&map[i][j]);
		}
	}
	compass( x1, y1, x2, y2);
	return 0;
}
void compass(int x1,int y1,int x2,int y2){
	x_1=x1;x_2=x2;y_1=y1;y_2=y2;
		 loop(0);
}

void find_up(){
	if(x_1==0||map[x_1-1][y_1]=='1')return;//�޷��ݹ���˳� 
		x_1--;map[x_1][y_1]='S';
		loop(1);//��ȥ�ݹ������������˵������·ʧ���� 
		map[x_1][y_1]='0';x_1++;
}
void find_down(){
	if(x_1==n-1||map[x_1+1][y_1]=='1')return;
	x_1++;map[x_1][y_1]='S';
		loop(2);
		map[x_1][y_1]='0';x_1--;
}
void find_left(){
	if(y_1==0||map[x_1][y_1-1]=='1')return;
	y_1--;map[x_1][y_1]='S';
	loop(3);
	map[x_1][y_1]='0';y_1++;
}
void find_right(){
	if(y_1==n-1||map[x_1][y_1+1]=='1')return;
	y_1++;map[x_1][y_1]='S';
	loop(4);
	map[x_1][y_1]='0';y_1--;
}
void f_printf(){
	map[x_2][y_2]='L';
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%c",map[i][j]);
		}
		printf("\n");
	}
}
