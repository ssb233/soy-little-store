#include<string.h>

void swap(char* a, char *b) {
	char tmp = *a;
	*a = *b;
	*b = tmp;
}
void revs(char* str) {
	int len = strlen(str);
	char *low = &str[0];
	char *high = &str[len - 1];
	while (low < high) {
		swap(low++, high--);
	}
}
void rev(char * l, char * r) {
	char tmp;
	while (r > l) {
		tmp = *l;
		*l = *r;
		*r = tmp;
		l++;
		r--;
	}
}
