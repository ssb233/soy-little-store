int dia[100005];
int num=0;

void judge(int flag,int i,int dia[]){
	if(dia[flag]==dia[i]){
		//������ͬ��
		if((i-flag)&1){
			num++;
		} 
	}
	else if(dia[flag]!=dia[i]){
		if((i-flag-1)&1){
			num++;
		}
	}
}
//�������⣬һ����������ֻ���������ʣ����ͬ�����ʳ�������
//��ô���ּӼӣ��������ŵķ��÷�����flag���ҵ��ĵ�һ������
//i���ҵ��ĵڶ������ʣ�Ȼ��������������֮����ã� 
