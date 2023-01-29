#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void getnext(char T[], int next[]) {
	int i = 0, j = -1;
	next[0] = -1;
	while (T[i] != '\0') {
		if (j == -1 || T[i] == T[j]) {
			// iΪ��׺λ�ã�jΪǰ׺λ��
			//����µ�λ��ƥ��ɹ�����ô˵��next[k+1]= j+1;
			i++;
			j++;
			next[i] = j;
		} else
			j = next[j]; //���ַ���ͬ����jֵ����
			//����Ļ�������ǰj�����������ǰ��׺����ԭ����jλ���Ѿ�ƥ�������ǰ��׺������
			//��ǰ׺���������ǰ��׺���ȼ���������ԭ���������ǰ��׺�������ڵݹ飩 
	}
}
int KMPindex(char S[ ], char T[ ]) {
	int i = 0, j = 0, *next;
	next = (int *)malloc(sizeof(int) * (strlen(T) + 1));
	getnext(T, next); //��next
	while ( S[i] != '\0' && T[j] != '\0') {
		if (S [i] == T[j] ) {
			i++;
			j++ ;
		} else
//j���˵���Ӧλ�ÿ�ʼƥ�䣬i����
			(j == 0) ? i++ : ( j = next[j]);
	}
	free(next);
	if ( T[j] == '\0') //ƥ��ɹ�������ƥ��λ��
		return i - j;
	else
		return -1;
}
