//////////////////////////////////////////////////
// Sort int array
//int������
#define N 10000
int n;
int a[N];
int compare(const void *e1, const void *e2) {
	int v1 = *((int *)e1);
	int v2 = *((int *)e2);
	if (v1 > v2) return 1;
	if (v1 < v2) return -1;
	return 0;
}
qsort(a, n, sizeof(int), compare); // Use > 0 to swap
// Search an element in the sorted array
//Ԫ������

int key;
int *p;
p = (int *)bsearch(&key, a, n, sizeof(int), compare);
//Ԫ�ز���
//����//

// Use == 0 to return

//////////////////////////////////////////////////
// Sort double array//double������
int n;
double a[N];
int compare(const void *e1, const void *e2) {
	double v1 = *((double *)e1);
	double v2 = *((double *)e2);
	if (v1 > v2) return 1;
	if (v1 < v2) return -1;
	return 0;
}
qsort(a, n, sizeof(double), compare);
/////////////////////////////////////////////
// Sort long long array//long long������

int n;
long long a[N];
int compare(const void *e1, const void *e2) {
	long long v1 = *((const long long *)e1);
	long long v2 = *((const long long *)e2);
	if (v1 > v2) return 1;
	if (v1 < v2) return -1;
	return 0;
}
qsort(a, n, sizeof(long long), compare);
//////////////////////////////////////////////////
// Sort array of char array
char buf[100][105];
int n;
qsort(buf, n, sizeof(buf[0]), strcmp);
�ֵ����������� ���Ƚ��ַ��� �ķǶ�̬���� 
//////////////////////////////////////////////////
// Sort char* array
�ֵ�������Ķ�̬���� 
char *lines[100];//ָ������ ��ÿһ��Ԫ����ָ�� ��������char*�� 
int n;//lines�����Ƕ���ָ�룻*��lines+i��=lines[i];��ָ�룻����**��lines+i��=*lines[i];������Ǿ�����ֵ 
int compare(const void *p1, const void *p2) {
	char *a = *(char **)p1;//*(*(lines+i)+j)�����ʾһ����ά�����[i][j]Ԫ�� 
	char *b = *(char **)p2;
	return strcmp(a, b);
}
qsort(lines, n, sizeof(char *), compare);
//////////////////////////////////////////////////
// Sort array of int array//�ַ���������
int data[100][3];
int n;
int compare(const void *e1, const void *e2) {
	int *p1 = (int *)e1;
	int *p2 = (int *)e2;
	if (p1[0] > p2[0]) return 1;
	if (p1[0] < p2[0]) return -1;
// You can use p[1], p[2] as well
	return 0;
}
qsort(buf, n, sizeof(data[0]), compare);
//////////////////////////�ֵ������� 
int comp(const void *p1, const void *p2) {
    char *a = (char *)p1; //��p1ǿ��ת��Ϊchar*���͵�ָ��
    char *b = (char *)p2; //��p2ǿ��ת��Ϊchar*���͵�ָ��
    return strcmp(a, b); //���������ַ������ֵ����С
}
//////////////////////////////
//������򣺰���ÿ�е�һ��Ԫ���������򣬵�һ��Ԫ����ͬʱ���յڶ���Ԫ����������
int cmp(const void *p, const void *q) {
	int *a = (int *)p;
	int *b = (int *)q;
	if(a[0] > b[0]) return 1; //��һ��Ԫ��a<b������1��ʾpָ�����Ӧ����qָ����еĺ���
	else if(a[0] < b[0]) return -1; //��һ��Ԫ��a>b������-1��ʾpָ�����Ӧ����qָ����е�ǰ��
	else if(a[1] > b[1]) return 1; //��ʱһ����һ��Ԫ��a=b���жϵڶ���Ԫ��
	else if((a[1] < b[1]) return -1;
	else return 0; //��һ�����ڶ���Ԫ�ؾ���ȣ�����0��ʾpָ����к�qָ�������ȷ��ǰ���ϵ
}
//����qsort�����Զ�ά����int data[1000][2]ǰn�и��ݹ����������
qsort(data, n, sizeof(data[0]), cmp);
