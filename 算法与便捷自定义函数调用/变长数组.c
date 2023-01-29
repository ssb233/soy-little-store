/*
 * ����ṹ�� struct Vector����ָ��������Ϊ VecPtr
 * length   : ������ʹ�õĳ���
 * capacity : ���������
 * array    �����ڴ�����ݵ�����
 */
typedef struct Vector {
    int length;
    int capacity;
    int *array;
} *VecPtr;
 
/*
 * ����һ���յı䳤���飬��ʼ����Ϊ 5�����ر䳤�����ָ��
 */
VecPtr create_vector() {
    VecPtr vec = (VecPtr) malloc(sizeof(struct Vector));
    vec->array = (int *) malloc(5 * sizeof(int));
    vec->capacity = 5;
    vec->length = 0;
    return vec;
}
 
/*
 * ������������������β������Ԫ�أ������������Զ�����һ��
 * vec  : �䳤�����ָ��
 * item : Ҫ�����Ԫ��
 */
void push_back(VecPtr vec, int item) {
    vec->array[vec->length] = item;
    vec->length++;
    if (vec->length == vec->capacity)
        vec->array = (int *) realloc(vec->array, 2 * vec->capacity * sizeof(int));
}
