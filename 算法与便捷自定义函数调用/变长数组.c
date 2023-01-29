/*
 * 定义结构体 struct Vector，其指针重命名为 VecPtr
 * length   : 数组已使用的长度
 * capacity : 数组的容量
 * array    ：用于存放数据的区域
 */
typedef struct Vector {
    int length;
    int capacity;
    int *array;
} *VecPtr;
 
/*
 * 创建一个空的变长数组，初始容量为 5，返回变长数组的指针
 */
VecPtr create_vector() {
    VecPtr vec = (VecPtr) malloc(sizeof(struct Vector));
    vec->array = (int *) malloc(5 * sizeof(int));
    vec->capacity = 5;
    vec->length = 0;
    return vec;
}
 
/*
 * 这个函数可以在数组的尾部插入元素，当数组满了自动扩大一倍
 * vec  : 变长数组的指针
 * item : 要插入的元素
 */
void push_back(VecPtr vec, int item) {
    vec->array[vec->length] = item;
    vec->length++;
    if (vec->length == vec->capacity)
        vec->array = (int *) realloc(vec->array, 2 * vec->capacity * sizeof(int));
}
