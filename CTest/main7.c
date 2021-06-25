//
// Created by jiaquanxia on 2021/6/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 	数组指针，它是指针，指向数组的指针。
数组的类型由元素类型和数组大小共同决定：int array[5]  的类型为  int[5]；C语言可通过typedef定义一个数组类型：
定义数组指针有一下三种方式：
 */

//方式一
void test01() {
    //先定义数组类型，再用数组类型定义数组指针
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //有typedef是定义类型，没有则是定义变量,下面代码定义了一个数组类型ArrayType
    typedef int(ArrayType)[10];
    //int ArrayType[10]; //定义一个数组，数组名为ArrayType

    ArrayType myarr; //等价于 int myarr[10];
    ArrayType *pArr = &arr; //定义了一个数组指针pArr，并且指针指向数组arr
    for (int i = 0; i < 10; i++) {
        printf("%d ", (*pArr)[i]);
    }
    printf("\n");
}

//方式二
void test02() {
    int arr[10];
    //定义数组指针类型
    typedef int(*ArrayType)[10];
    ArrayType pArr = &arr; //定义了一个数组指针pArr，并且指针指向数组arr
    for (int i = 0; i < 10; i++) {
        (*pArr)[i] = i + 1;
    }
    for (int i = 0; i < 10; i++) {
        printf("%d ", (*pArr)[i]);
    }
    printf("\n");
}

//方式三
void test03() {
    int arr[10];
    int(*pArr)[10] = &arr;

    for (int i = 0; i < 10; i++) {
        (*pArr)[i] = i + 1;
    }
    for (int i = 0; i < 10; i++) {
        printf("%d ", (*pArr)[i]);
    }
    printf("\n");
}

int main() {
    test01();
    test02();
    test03();
    return 0;
}