//
// Created by jiaquanxia on 2021/6/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 二维数组
 * */

//二维数组的线性存储特性
void PrintArray(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//二维数组的线性存储
void test01() {
    int arr[][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };

    int arr2[][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int len = sizeof(arr2) / sizeof(int);

    //如何证明二维数组是线性的？
    //通过将数组首地址指针转成Int*类型，那么步长就变成了4，就可以遍历整个数组
    int *p = (int *) arr;
    for (int i = 0; i < len; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");

    PrintArray((int *) arr, len);
    PrintArray((int *) arr2, len);
}

//二维数组的3种形式参数
//二维数组的第一种形式
void PrintArray01(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("arr[%d][%d]:%d\n", i, j, arr[i][j]);
        }
    }
}

//二维数组的第二种形式
void PrintArray02(int arr[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("arr[%d][%d]:%d\n", i, j, arr[i][j]);
        }
    }
}

//二维数组的第二种形式
void PrintArray03(int(*arr)[3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("arr[%d][%d]:%d\n", i, j, arr[i][j]);
        }
    }
}

void test02() {
    int arr[][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };

    PrintArray01(arr);
    PrintArray02(arr);
    PrintArray03(arr);
}

int main() {
    test01();

    test02();
    return 0;
}