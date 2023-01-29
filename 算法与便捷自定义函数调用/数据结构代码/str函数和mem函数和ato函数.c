#include<stdio.h>
#include<string.h>

/*char *s;
s=(char *)malloc(strlen(str)+1);  多分配一个给\0;
malloc函数一定要free函数去释放空间；
free(str);释放数组； */

/*字符串操作str版本； 
strcpy(s1,s2);从地址s1开始逐个复制s2；（覆盖）；
strncpy(s1,s2,num);num表示复制  字符数量 ，s2的num个字符
会复制末尾的'\0' 
strcat(s1,s2),把s2拼接到s1的末尾;
strlen(s);在\0位置截断。 
strcmp(s1,s2);比较两个字符串的字典序，
字典序相同就返回0；
(比较的是ascll码值)，，，s1大于s2就返回正数；，，s1小于s2就返回负数； 
strncmp(s1,s2,n);比较前n个字符 
stricmp(s1,s2);忽略大小写比较两个字符串；
strchr(str,ch),返回指针，没有就返回NULL；
strrchr(str,ch),   从后往前找最先出现的位置； 
strstr(s1,s2),    在s1中找s2，返回指针，没有就返回NULL*/



/*字符串操作的mem版本 
void *memchr(const void *str, int c, size_t n) 在参数 str 所指向的字符串的前 n 个字节中搜索
第一次出现字符 c（一个无符号字符）的位置，相似于strchr函数

int memcmp(const void *str1, const void *str2, size_t n)) 把存储区 str1 和存储区 str2 的
前 n 个字节进行比较，相似于strncmp函数

void *memcpy(void *str1, const void *str2, size_t n) 从存储区 str2 复制
 n 个字符到存储区 str1
 
 void *memset(void *str, int c, size_t n) 复制字符 c（一个无符号字符）到
 参数 str 所指向的字符串的前 n 个字符*/
 
 /*字符串转数字合集
 atoi(s)  转int型  
 atof(s)  转double型 
 atol(s)  转long型*/
 
 
 /////////////////////////////
 /*其它类型转换
 关于sscanf和sprintf的补充（待补充）*/
 
 
