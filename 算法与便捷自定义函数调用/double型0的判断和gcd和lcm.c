#include <math.h>
#define EPS 1e-6
int isZero(double v) {
	return fabs(v) < EPS;
}
int gcd(int a, int b) {
	int tmp;
	while (b != 0) {
		tmp = a;
		a = b;
		b = tmp % b;
	}
	return a;
}
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}
