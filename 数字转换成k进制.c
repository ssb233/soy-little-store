int num_front[20];//��Ӧ���±���ָ������Ӧ����ֵ��ϵ����
int i=0;
//���Ƕ�һ�����ֽ���ת����k�����µ����֣�
//�����λ�ô�ȡ���ֵĵ�λ��
//�����ʱ��ǵ���һЩ�任�� 
void deal_rule(int n,int k){
	if(n==0){
		return;
	}
	num_front[i++]=n%k;
	n/=k;
	return deal_rule(n,k);
}
