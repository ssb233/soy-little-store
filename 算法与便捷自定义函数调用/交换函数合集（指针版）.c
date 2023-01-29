void swap(char* a, char *b) {
	char tmp = *a;
	*a = *b;
	*b = tmp;
}
void swap(int* a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void swap(double* a, double *b) {
	double tmp = *a;
	*a = *b;
	*b = tmp;
}
void swap(float* a, float *b) {
	float tmp = *a;
	*a = *b;
	*b = tmp;
}
void swap(char** a, char **b) {
	char *tmp = *a;
	*a = *b;
	*b = tmp;
}
