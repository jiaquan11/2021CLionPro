//
// Created by jiaquanxia on 2021/6/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * const的使用
 */

//const修饰变量
void test01(){
    //1. const基本概念
    const int i = 0;
    //i = 100; //错误，只读变量初始化之后不能修改

    //2. 定义const变量最好初始化
    const int j;
    //j = 100; //错误，不能再次赋值

    //3. c语言的const是一个只读变量，并不是一个常量，可通过指针间接修改
    const int k = 10;
    //k = 100; //错误，不可直接修改，我们可通过指针间接修改
    printf("k:%d\n", k);
    int* p = &k;
    *p = 100;
    printf("k:%d\n", k);
}

//const 修饰指针
void test02(){
    int a = 10;
    int b = 20;
    //const放在*号左侧 修饰p_a指针指向的内存空间不能修改,但可修改指针的指向
    const int* p_a = &a;
    //*p_a = 100; //不可修改指针指向的内存空间
    p_a = &b; //可修改指针的指向

    //const放在*号的右侧， 修饰指针的指向不能修改，但是可修改指针指向的内存空间
    int* const p_b = &a;
    //p_b = &b; //不可修改指针的指向
    *p_b = 100; //可修改指针指向的内存空间

    //指针的指向和指针指向的内存空间都不能修改
    const int* const p_c = &a;
}

int main() {
    test01();

    test02();
    return 0;
}
