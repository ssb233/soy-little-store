//////////////////////////////////////////////////
// Sort int array
//int型排序；
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
//元素排序；

int key;
int *p;
p = (int *)bsearch(&key, a, n, sizeof(int), compare);
//元素查找
//查找//

// Use == 0 to return

//////////////////////////////////////////////////
// Sort double array//double型排序；
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
// Sort long long array//long long型排序；

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
字典序升序排列 ，比较字符串 的非动态方法 
//////////////////////////////////////////////////
// Sort char* array
字典序升序的动态排列 
char *lines[100];//指针数组 ，每一个元素是指针 ，类型是char*型 
int n;//lines本身是二重指针；*（lines+i）=lines[i];是指针；所以**（lines+i）=*lines[i];这个才是具体数值 
int compare(const void *p1, const void *p2) {
	char *a = *(char **)p1;//*(*(lines+i)+j)这个表示一个二维数组的[i][j]元素 
	char *b = *(char **)p2;
	return strcmp(a, b);
}
qsort(lines, n, sizeof(char *), compare);
//////////////////////////////////////////////////
// Sort array of int array//字符串型排序；
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
//////////////////////////字典序升序 
int comp(const void *p1, const void *p2) {
    char *a = (char *)p1; //将p1强制转换为char*类型的指针
    char *b = (char *)p2; //将p2强制转换为char*类型的指针
    return strcmp(a, b); //返回两个字符串的字典序大小
}
//////////////////////////////
//排序规则：按照每行第一个元素升序排序，第一个元素相同时按照第二个元素升序排序
int cmp(const void *p, const void *q) {
	int *a = (int *)p;
	int *b = (int *)q;
	if(a[0] > b[0]) return 1; //第一个元素a<b，返回1表示p指向的行应该在q指向的行的后面
	else if(a[0] < b[0]) return -1; //第一个元素a>b，返回-1表示p指向的行应该在q指向的行的前面
	else if(a[1] > b[1]) return 1; //此时一定第一个元素a=b，判断第二个元素
	else if((a[1] < b[1]) return -1;
	else return 0; //第一个，第二个元素均相等，返回0表示p指向的行和q指向的行无确定前后关系
}
//调用qsort函数对二维数组int data[1000][2]前n行根据规则进行排序：
qsort(data, n, sizeof(data[0]), cmp);
