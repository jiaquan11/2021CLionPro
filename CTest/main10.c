//
// Created by jiaquanxia on 2021/6/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 函数指针操作
 */
typedef int(p)(int, int);

void my_func01(int a, int b) {
    printf("%d %d\n", a, b);
}

void test00() {
    p p1;
    //p1(10,20); //错误，不能直接调用，只描述了函数类型，但是并没有定义函数体，没有函数体无法调用
    p *p2 = my_func01;
    p2(10, 20); //正确，指向有函数体的函数入口地址
}


//--------------------------------------------------------------
int my_func(int a, int b) {
    printf("ret:%d\n", a + b);
    return 0;
}

//1. 先定义函数类型，通过类型定义指针
void test01() {
    typedef int(FUNC_TYPE)(int, int);
    FUNC_TYPE *f = my_func;
    //如何调用？
    (*f)(10, 20);
    f(10, 20);
}

//2. 定义函数指针类型
void test02() {
    typedef int(*FUNC_POINTER)(int, int);
    FUNC_POINTER f = my_func;
    //如何调用？
    (*f)(10, 20);
    f(10, 20);
}

//3. 直接定义函数指针变量
void test03() {
    int (*f)(int, int) = my_func;
    //如何调用？
    (*f)(10, 20);
    f(10, 20);
}

int main() {
    test00();
    test01();
    test02();
    test03();
    return 0;
}