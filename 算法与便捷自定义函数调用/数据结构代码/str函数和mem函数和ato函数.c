#include<stdio.h>
#include<string.h>

/*char *s;
s=(char *)malloc(strlen(str)+1);  �����һ����\0;
malloc����һ��Ҫfree����ȥ�ͷſռ䣻
free(str);�ͷ����飻 */

/*�ַ�������str�汾�� 
strcpy(s1,s2);�ӵ�ַs1��ʼ�������s2�������ǣ���
strncpy(s1,s2,num);num��ʾ����  �ַ����� ��s2��num���ַ�
�Ḵ��ĩβ��'\0' 
strcat(s1,s2),��s2ƴ�ӵ�s1��ĩβ;
strlen(s);��\0λ�ýضϡ� 
strcmp(s1,s2);�Ƚ������ַ������ֵ���
�ֵ�����ͬ�ͷ���0��
(�Ƚϵ���ascll��ֵ)������s1����s2�ͷ�������������s1С��s2�ͷ��ظ����� 
strncmp(s1,s2,n);�Ƚ�ǰn���ַ� 
stricmp(s1,s2);���Դ�Сд�Ƚ������ַ�����
strchr(str,ch),����ָ�룬û�оͷ���NULL��
strrchr(str,ch),   �Ӻ���ǰ�����ȳ��ֵ�λ�ã� 
strstr(s1,s2),    ��s1����s2������ָ�룬û�оͷ���NULL*/



/*�ַ���������mem�汾 
void *memchr(const void *str, int c, size_t n) �ڲ��� str ��ָ����ַ�����ǰ n ���ֽ�������
��һ�γ����ַ� c��һ���޷����ַ�����λ�ã�������strchr����

int memcmp(const void *str1, const void *str2, size_t n)) �Ѵ洢�� str1 �ʹ洢�� str2 ��
ǰ n ���ֽڽ��бȽϣ�������strncmp����

void *memcpy(void *str1, const void *str2, size_t n) �Ӵ洢�� str2 ����
 n ���ַ����洢�� str1
 
 void *memset(void *str, int c, size_t n) �����ַ� c��һ���޷����ַ�����
 ���� str ��ָ����ַ�����ǰ n ���ַ�*/
 
 /*�ַ���ת���ֺϼ�
 atoi(s)  תint��  
 atof(s)  תdouble�� 
 atol(s)  תlong��*/
 
 
 /////////////////////////////
 /*��������ת��
 ����sscanf��sprintf�Ĳ��䣨�����䣩*/
 
 
