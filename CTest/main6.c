//
// Created by jiaquanxia on 2021/6/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 二级指针做形参的输入输出特性
 * */

//二级指针做参数的输出特性是指由被调函数分配内存
//被调函数,由参数n确定分配多少个元素内存
void allocate_space(int **arr, int n) {
    //堆上分配n个int类型元素内存
    int *temp = (int *) malloc(sizeof(int) * n);
    if (NULL == temp) {
        return;
    }
    //给内存初始化值
    int *pTemp = temp;
    for (int i = 0; i < n; i++) {
        //temp[i] = i + 100;
        *pTemp = i + 100;
        pTemp++;
    }
    //指针间接赋值
    *arr = temp;
}

//打印数组
void print_array01(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//二级指针输出特性(由被调函数分配内存)
void test01() {
    int *arr = NULL;
    int n = 10;
    //给arr指针间接赋值
    allocate_space(&arr, n);
    //输出arr指向数组的内存
    print_array01(arr, n);
    //释放arr所指向内存空间的值
    if (arr != NULL) {
        free(arr);
        arr = NULL;
    }
}

//二级指针做形参输入特性
//二级指针做形参输入特性是指由主调函数分配内存。
//打印数组
void print_array02(int **arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr[i]));
    }
    printf("\n");
}

//二级指针输入特性(由主调函数分配内存)
void test02() {
    int a1 = 10;
    int a2 = 20;
    int a3 = 30;
    int a4 = 40;
    int a5 = 50;

    int n = 5;

    int **arr = (int **) malloc(sizeof(int *) * n);
    arr[0] = &a1;
    arr[1] = &a2;
    arr[2] = &a3;
    arr[3] = &a4;
    arr[4] = &a5;

    print_array02(arr, n);

    free(arr);
    arr = NULL;
}

int main() {
    test01();

    test02();
    return 0;
}
